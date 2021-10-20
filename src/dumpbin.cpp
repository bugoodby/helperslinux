#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void dumpValueHex( FILE *fp, const void *pData, size_t size )
{
	const char szHexArray[] = "0123456789ABCDEF";
	const unsigned char *p = (const unsigned char*)pData;
	size_t l, line = 0;
	char lineBuf[52] = {0};
	char *pHexPtr = NULL;
	
	lineBuf[49] = '\n';
	
	fputs( "DUMP START\n", fp );
	
	do {
		line = ( size > 16 ) ? 16 : size;
		size -= line;
		
		for ( int i = 0; i < 49; i++ ) lineBuf[i] = ' ';
		pHexPtr = lineBuf + 2;
		
		for ( l = 0; l < line; l++, p++ ) {
			*pHexPtr++ = szHexArray[ *p >> 4 ];
			*pHexPtr++ = szHexArray[ *p & 0xF ];
			pHexPtr++;
		}
		fputs( lineBuf, fp );
		
	} while ( size > 0 );
	
	fputs( "DUMP END\n", fp );
}

long getFileSize( const char *fname )
{
	int fd = open(fname, O_RDONLY);
	if ( fd == -1 ) {
		fprintf(stderr, "%s: could not open %s\n", __FUNCTION__, fname);
		return 0;
	}
	
	FILE *fp = fdopen(fd, "rb");
	if ( !fp ) {
		fprintf(stderr, "%s: could not open %s\n", __FUNCTION__, fname);
		return 0;
	}
	
	struct stat stbuf;
	if ( fstat(fd, &stbuf) == -1 ) {
		fprintf(stderr, "%s: fstat(%s) failed\n", __FUNCTION__, fname);
		return 0;
	}
	
	long file_size = stbuf.st_size;

	fclose(fp);

	return file_size;
}

void dumpbin( const char *fname )
{
	FILE *fp = NULL;
	void *buffer = NULL;
	long bufferSize = 0;
	
	// get file size.
	bufferSize = getFileSize(fname);
	
	if ( bufferSize > 0 ) {
		// allocate memory.
		buffer = malloc(bufferSize);
		if ( !buffer ) {
			fprintf(stderr, "%s: could not allocate memory (%ld byte)\n", __FUNCTION__, bufferSize);
		}
		else {
			// read all data.
			fp = fopen(fname, "rb");
			if ( !fp ) {
				fprintf(stderr, "%s: could not open %s\n", __FUNCTION__, fname);
			}
			if ( fread(buffer, 1, bufferSize, fp) != (size_t)bufferSize ) {
				fprintf(stderr, "%s: fread() failed.\n", __FUNCTION__);
			}
		}
	}
	
	dumpValueHex( stdout, buffer, bufferSize );
	
	free(buffer);
	fclose(fp);
	
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* global variables */
GLOBALPROP g_gprop = {0};



//--------------------------------------------------------------
// show usage
//--------------------------------------------------------------
void usage(void)
{
	fprintf(stdout, "[ %s Version %s ]\n", MODULENAME_STRING, VERSION_STRING);
	fprintf(stdout, "helper functions.\n");
	fprintf(stdout, "\n");
	fprintf(stdout, "Usage : %s [option...]\n", MODULENAME_STRING);
	fprintf(stdout, "\n");
}


//--------------------------------------------------------------
// parse command line
//--------------------------------------------------------------
bool parse_cmdline( int argc, char **argv, GLOBALPROP &gprop )
{
	bool ret = true;
	char *s = NULL;

	/* initialize */
	gprop.argc = 0;
	
	/* parse */
	while ( --argc > 0 ) {
		s = *++argv;
		if ( *s == '-' ) {
			switch ( *++s )
			{
			case 'h':
			case '?':
				usage();
				ret = false;
				break;
			default:
				fprintf(stderr, "Unknown parameter : -%s\n", s);
				ret = false;
				break;
			}
		}
		else {
			gprop.argc = argc;
			gprop.argv = argv;
			break;
		}
	}

	return ret;
}


int main( int argc, char **argv )
{
	if ( !parse_cmdline(argc, argv, g_gprop) ) {
		return -1;
	}
	
	char buffer[256] = {0};
	uint32_t selectNum = 0;
	
	while (1) {
		printf("==============================\n");
		printf("  1: Sample_get_from_env\n");
		printf("  2: Sample_get_from_file\n");
		printf("  3: Sample_IDString\n");
		printf("  q: quit\n");
		printf("==============================\n");
		printf(">>");
		fgets(buffer, sizeof(buffer), stdin);
		
		if ( buffer[0] == 'q' || buffer[0] == 'Q' ) {
			break;
		}
		
		selectNum = strtoul(buffer, NULL, 0);
		switch ( selectNum ) {
		case 1:
			Sample_get_from_env();
			break;
		case 2:
			Sample_get_from_file();
			break;
		case 3:
			Sample_IDString();
			break;
		default:
			printf("[ERROR] invalid number(%u)\n", selectNum);
			break;
		}
	}
	return 0;
}


#ifndef __MAIN_H__
#define __MAIN_H__

#include "debuglog.h"

/*----------------------------------------*/
/* Module Name & Version                  */
/*----------------------------------------*/
#define MODULENAME_STRING	"helpers"
#define VERSION_STRING		"0.01"


/*----------------------------------------*/
/* OPTION Structure                       */
/*----------------------------------------*/

typedef struct _GLOBALPROP {
	int argc;					/* number of input files */
	char** argv;				/* pointer to a file name array */
} GLOBALPROP;


extern GLOBALPROP g_gprop;
inline GLOBALPROP* prop() { return &g_gprop; }



void check_env();
void Sample_get_from_env();
void Sample_get_from_file();
void Sample_IDString();
void dumpbin( const char *fname );
void logging_test_main();


#endif /* __MAIN_H__ */

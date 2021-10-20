#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h> // for sleep()

// ex)
// export TESTVAL=3
// export TESTVAL_LIST=1,2,5,10,-3
// export TESTVAL_SLEEPTIME=5


//すべての環境変数の取得
void test_getAllEnv()
{
	printf("\n********** %s **********\n", __FUNCTION__);
	
	extern char **environ;
	char **env = environ;
	
	while(*env) {
		const char* val = *env;
		if (val) {
		    printf("%s\n", val);
		}
		env++;
	}
}

//環境変数からの取得
void test_getenv()
{
	printf("\n********** %s **********\n", __FUNCTION__);
	
	char *str = getenv("TESTVAL");
	printf("TESTVAL = %s\n", str);
	if ( str ) {
		uint32_t num = strtoul(str, NULL, 0);
		switch ( num ) {
		case 1:
			printf("  1 is set.\n");
			break;
		case 2:
			printf("  2 is set.\n");
			break;
		case 3:
			printf("  3 is set.\n");
			break;
		default:
			printf("  others.\n");
			break;
		}
	}
}

//環境変数からの取得（,区切りのリスト）
void test_getenv_list()
{
	printf("\n********** %s **********\n", __FUNCTION__);
	
	char *str = getenv("TESTVAL_LIST");
	printf("TESTVAL_LIST = %s\n", str);
	if ( str ) {
		char *token = NULL, *saveptr = NULL;
		token = strtok_r(str, ",", &saveptr);
		while ( token ) {
			uint32_t num = strtoul(token, NULL, 0);
			printf("  token=%d\n", num);
			token = strtok_r(NULL, ",", &saveptr);
		}
	}
}

//環境変数から数値を取得してスリープ
void test_getenv_sleep()
{
	printf("\n********** %s **********\n", __FUNCTION__);
	
	char *str = getenv("TESTVAL_SLEEPTIME");
	printf("TESTVAL_SLEEPTIME = %s\n", str);
	if ( str ) {
		uint32_t sec = strtoul(str, NULL, 0);
		printf("--- sleep(%u) start ---\n", sec);
		sleep(sec);
		printf("--- sleep(%u) end ---\n", sec);
	}
}




void Sample_get_from_env()
{
	test_getAllEnv();
	test_getenv();
	test_getenv_list();
	test_getenv_sleep();
}


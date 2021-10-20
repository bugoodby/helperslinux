#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_env()
{
	printf("sizeof(bool) : %lu\n", sizeof(bool));
	printf("sizeof(int) : %lu\n", sizeof(int));
	printf("sizeof(long) : %lu\n", sizeof(long));
	printf("sizeof(long long) : %lu\n", sizeof(long long));
	printf("sizeof(float) : %lu\n", sizeof(float));
	printf("sizeof(double) : %lu\n", sizeof(double));
}

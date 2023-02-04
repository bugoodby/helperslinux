#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_env()
{
	printf("sizeof(bool) : %u\n", sizeof(bool));
	printf("sizeof(int) : %u\n", sizeof(int));
	printf("sizeof(long) : %u\n", sizeof(long));
	printf("sizeof(long long) : %u\n", sizeof(long long));
	printf("sizeof(float) : %u\n", sizeof(float));
	printf("sizeof(double) : %u\n", sizeof(double));
}

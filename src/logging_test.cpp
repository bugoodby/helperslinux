#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>


struct data_list_t {
	uint8_t count;
	uint32_t val[256];
};

void logging_data_list()
{
	// 対象データ生成
	data_list_t dataList;
	dataList.count = 100;
	for ( uint8_t i = 0; i < dataList.count; i++ ) {
		dataList.val[i] = i;
	}
	
	// ログ出力
	char logBuffer[100] = "";
	char *pWritePoint = logBuffer;
	size_t remineSize = sizeof(logBuffer);
	
	uint8_t maxCount = ( dataList.count < 10 ) ? dataList.count : 10;
	for ( uint8_t i = 0; i < maxCount; i++ ) {
		snprintf(pWritePoint, remineSize, "%08X:", dataList.val[i]);
		pWritePoint += 9;
		remineSize = ( remineSize > 9 ) ? remineSize - 9 : 0;
	}
	
	printf("Data List: cnt(%u) val(%s)\n", dataList.count, logBuffer);
}

void logging_arg_list()
{
	// 対象データ生成
	int argc = 5;
	const char *argv[] = { "12345678", "1234567", "0123", "-o", "/tmp/hogehoge.txt" };
	
	// ログ出力
	char buffer[20] = "";
	char tmp[30] = "";
	size_t tmplen = 0;
	size_t remain = sizeof(buffer) - 1;
	
	for ( int i = 0; i < argc; i++ ) {
		snprintf(tmp, sizeof(tmp), "[%s]", argv[i]);
		tmplen = strlen(tmp);
		strncat(buffer, tmp, remain);
		if ( remain < tmplen ) {
			break;
		}
		remain -= strlen(tmp);
	}
	
	printf("Args: %s  (len=%u)\n", buffer, strlen(buffer));
}


void logging_test_main()
{
	logging_data_list();
	logging_arg_list();
}

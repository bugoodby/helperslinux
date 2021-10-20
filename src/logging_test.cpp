#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>


struct data_list_t {
	uint8_t count;
	uint32_t val[256];
};

void logging_test_main()
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


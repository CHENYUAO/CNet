/* @测试程序 
 *
 */
#include<time.h>
#include"Matrix.h"
#include"Net.h"
#include"Data.h"
#include"weights.h"

void main() {
	clock_t start, finish;
	double total_time;
	start = clock();

	for (int k = 0; k < 53; k++) {
		double test_input_batch[DATA_BATCH][DATA_DIMENSION];
		for (int i = 0; i < DATA_BATCH; i++) {
			for(int j = 0; j < DATA_DIMENSION; j++) {
				test_input_batch[i][j] = test_input[k * DATA_BATCH + i][j];
			}
		}
		int* res = (int*)calloc(DATA_BATCH, sizeof(int));
		if (res != NULL) {
			netCalculate(test_input_batch, res);
			for (int i = 0; i < DATA_BATCH; i++) {
				printf("%3d", res[i]);
			}
			free(res);
		}
	}
	


	finish = clock();
	total_time = ( (double)finish - (double)start ) / CLOCKS_PER_SEC;
	printf("\n函数运行时间：%0.3f毫秒 \n", total_time);

}

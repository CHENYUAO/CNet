/* @测试程序 
 *
 */
#include<time.h>
#include"Matrix.h"
#include"Net.h"
#include"Data.h"
void main() {
	clock_t start, finish;
	double total_time;
	start = clock();


	finish = clock();
	total_time = ( (double)finish - (double)start ) / CLOCKS_PER_SEC;
	printf("\n函数运行时间：%0.3f毫秒 \n", total_time);

}

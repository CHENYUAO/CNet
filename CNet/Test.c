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
	
	Matrix mat1;
	double p[12] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 ,5.3,32.3,53.0};
	initialize(&mat1, 2, 6, p);
	show(&mat1);

	int* max = (int*)calloc(2, sizeof(int));
	if (max != NULL) {
		maxIndex(&mat1, max);
		for (int i = 0; i < 2; i++) {
			printf("%3d", max[i]);
		}
	}
	

	free(max);
	/*
	transpose(&mat1);
	show(&mat1);
	
	
	Matrix testInput;
	dataNormalization(test_input_10);
	initialize(&testInput, 10, 11, test_input_10);
	show(&testInput);

	transpose(&testInput);
	show(&testInput);
	
	batchNorm(&mat1,1.0,0.0);
	show(&mat1);
	*/
	/*
	Matrix mat2;
	double q[12] = { 1.0,1.0,1.0,1.0,1.0,1.0, 1.0,1.0,1.0 ,4.0,4.7,7.34};
	initialize(&mat2, 6, 2, q);

	Matrix mat3;
	double* mat3value = (double*)calloc(mat1.row * mat2.column, sizeof(double));
	initialize(&mat3, mat1.row, mat2.column, mat3value);
	multiply(&mat1, &mat2, &mat3);
	show(&mat3);
	addDim(&mat3);
	show(&mat3);
	free(mat3.value);
	*/
	/*
	Matrix testAddDim;
	double* testadddim = (double*)calloc(9, sizeof(double));
	if (testadddim != NULL) {
		for (int i = 0; i < 9; i++) {
			testadddim[i] = 1.0 * i;
		}
		initialize(&testAddDim, 3, 3, testadddim);
		show(&testAddDim);
		transpose(&testAddDim);
		show(&testAddDim);
		addDim(&testAddDim);
		show(&testAddDim);
	}
	*/
	/*
	Matrix mat4;
	double* mat4value = (double*)calloc(mat1.row * mat1.column, sizeof(double));
	initialize(&mat4, mat1.row, mat1.column, mat3value);
	add(&mat1, &mat2, &mat4);
	show(&mat4);
	free(mat4.value);
	Matrix mat6;
	double p6[9] = { 0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	initialize(&mat6, 3, 3, p6);
	show(&mat6);

	Matrix mat7;
	double* mat7value = (double*)calloc((mat6.row + 1)*mat6.column, sizeof(double));
	initialize(&mat7, (mat6.row + 1), mat6.column, mat7value);
	addDim(&mat6,&mat7);
	show(&mat7);
	free(mat7.value);
	
	for (int count = 0; count < 4942; count++) {
		double input[11];
		for (int n = 0; n < 11; n++) {
			input[n] = test_input[count][n];
		}
		int r = netCalculate(input);
		printf("%3d", r);
	}


	double* average = (double*)calloc(DATA_DIMENSION, sizeof(double));
	if (average != NULL) {
		getAverage(test_input_10, average);
		for (int i = 0; i < DATA_DIMENSION; i++) {
			printf("%14.6f", *(average + i));
		}printf("\n");
		free(average);
	}

	double* stdDeviation = (double*)calloc(DATA_DIMENSION, sizeof(double));
	if (stdDeviation != NULL) {
		getStdDeviation(test_input_10, stdDeviation);
		for (int i = 0; i < DATA_DIMENSION; i++) {
			printf("%14.6f", *(stdDeviation + i));
		}printf("\n");
		free(stdDeviation);
	}
	
	for (int i = 0; i < DATA_BATCH; i++) {
		for (int j = 0; j < DATA_DIMENSION; j++) {
			printf("%15.6f", testDataCleaning[i][j]);
		}printf("\n");
	}printf("\n");

	dataNormalization(testDataCleaning);
	for (int i = 0; i < DATA_BATCH; i++) {
		for (int j = 0; j < DATA_DIMENSION; j++) {
			printf("%15.6f", testDataCleaning[i][j]);
		}printf("\n");
	}printf("\n");
	*//*
	for (int count = 0; count < 494; count++) {
		int result[DATA_BATCH];
		dataNormalization(test_input+count);
		netCalculate(test_input+count, result);
		for (int i = 0; i < DATA_BATCH; i++) {
			printf("%d ", result[i]);
		}printf("\n");
	}*/
	finish = clock();
	total_time = ( (double)finish - (double)start ) / CLOCKS_PER_SEC;
	printf("\n函数运行时间：%0.3f毫秒 \n", total_time);

}

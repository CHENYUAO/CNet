/* @Chen Yuao
 * @2020.11.20
 * @数据预处理实现
 * 
 */
#include"Data.h"
#include<math.h>
#include<float.h>

void getAverage(double data[][DATA_DIMENSION],double* result) {
	for (int j = 0; j < DATA_DIMENSION; j++) {
		double sum = 0.0;
		for (int i = 0; i < DATA_BATCH; i++) {
			sum += data[i][j];
		}
		result[j] = sum / DATA_BATCH;
	}
}

void getStdDeviation(double data[][DATA_DIMENSION], double* result) {
	double* average = (double*)calloc(DATA_DIMENSION, sizeof(double));
	if (average != NULL) {
		getAverage(test_input_10, average);
		for (int j = 0; j < DATA_DIMENSION; j++) {
			double sum = 0.0;
			for (int i = 0; i < DATA_BATCH; i++) {
				sum += pow((data[i][j] - average[j]),2);
			}
			result[j] = sqrt(sum / DATA_BATCH);
		}
	}
	free(average);
}

void dataNormalization(double data[][DATA_DIMENSION]) {
	double* average = (double*)calloc(DATA_DIMENSION, sizeof(double));
	double* stdDeviation = (double*)calloc(DATA_DIMENSION, sizeof(double));
	if (average != NULL && stdDeviation != NULL) {
		getAverage(test_input_10, average);
		getStdDeviation(test_input_10, stdDeviation);
		for (int i = 0; i < DATA_BATCH; i++) {
			for (int j = 0; j < DATA_DIMENSION; j++) {
				if (abs(data[i][j] - average[j]) > abs(3 * stdDeviation[j])
					|| data[i][j] == DBL_MAX) {
					data[i][j] = average[j];
				}
				data[i][j] = (data[i][j] - average[j]) / (stdDeviation[j]/*+10e-7*/);
			}
		}
	}
	free(average);
	free(stdDeviation);
}
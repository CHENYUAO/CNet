/* @Chen Yuao
 * @2020.11.13
 * 定义了Matrix结构体与其相关的操作函数，若想使用Matrix，需要声明一个Matrix变量，并用一个一维数组进行初始化
 * 例如：	Matrix mat1;
 *			double p[row*column] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };
 *			initialize(&mat1, 3, 3, p);
 *
 * 
 */


#include "Matrix.h"

void initialize(Matrix* myMatrix,int m, int n,double* p) {
	myMatrix->row = m;
	myMatrix->column = n;
	myMatrix->value = p;
}


void multiply(Matrix* a,Matrix* b, Matrix* c) {
	assert(a->column == b->row);
	for (int i = 0; i < a->row; i++) {
		for (int j = 0; j < b->column; j++) {
			for (int k = 0; k < a->column; k++) {
				c->value[i * b->column + j] += a->value[i * a->column + k] * b->value[k * b->column + j];
			}
		}
	}
}

void add(Matrix* a, Matrix* b, Matrix* c) {
	assert(a->row == b->row && a->column == b->column);
	for (int i = 0; i < a->row*a->column; i++) {
		c->value[i] = a->value[i] + b->value[i];
	}
}

void addVec(Matrix* a, double* b) {
	for (int i = 0; i < a->row; i++) {
		for (int j = 0; j < a->column; j++) {
			a->value[i * a->column + j] += b[j];
		}
	}
}


void sigmoid(Matrix* pointer){
	for (int i = 0; i < pointer->row * pointer->column; i++) {
		(*pointer).value[i] = 1 / (1 + exp(pointer->value[i]));
	}
}

void relu(Matrix* pointer) {
	for (int i = 0; i < pointer->row * pointer->column; i++) {
		if (pointer->value[i] < 0)
			pointer->value[i] = 0;
	}
	
}

void selu(Matrix* pointer) {
	double alpha = 1.6732632423543772848170429916717;
	double scale = 1.0507009873554804934193349852946;
	for (int i = 0; i < pointer->row * pointer->column; i++) {
		if (pointer->value[i] >= 0)
			pointer->value[i] *= scale;
		else pointer->value[i] = scale * alpha * (exp(pointer->value[i]) - 1);
	}
}

void maxIndex(Matrix* myMatrix, int* result) {
	int index = 0;
	for (int i = 0; i < myMatrix->row; i++) {
		double max = -DBL_MAX;
		for (int j = 0; j < myMatrix->column; j++) {
			if (myMatrix->value[i * myMatrix->column + j] > max) {
				max = myMatrix->value[i * myMatrix->column + j];
				index = j + 1;
			}	
		}
		result[i] = index;
	}
}

void addDim(Matrix* myMatrix) {
	double* pre = myMatrix->value;
	double* np = (double*)calloc((myMatrix->row+1) * myMatrix->column, sizeof(double));
	if (np != NULL) {
		for (int i = 0; i < myMatrix->row * myMatrix->column; i++) {
			np[i] = myMatrix->value[i];
		}
		for (int i = 0; i < myMatrix->column; i++) {
			np[myMatrix->row * myMatrix->column + i] = 1.0;
		}
		myMatrix->value = np;
		myMatrix->row++;
		free(pre);
	}
}

void show(Matrix* myMatrix) {
	for (int i = 0; i < myMatrix->row; i++) {
		for (int j = 0; j < myMatrix->column; j++) {
			printf("%14.6f", myMatrix->value[i * myMatrix->column + j]);
		}
		printf("\n");
	}printf("\n");
}

void transpose(Matrix* myMatrix) {
	double* trans = (double*)calloc(myMatrix->row * myMatrix->column, sizeof(double));
	int k = 0;
	if (trans != NULL) {
		for (int j = 0; j < myMatrix->column; j++) {
			for (int i = 0; i < myMatrix->row; i++) {
				trans[k] = myMatrix->value[i*myMatrix->column+j];
				k++;
			}
		}
		for (int i = 0; i < myMatrix->row * myMatrix->column; i++) {
			myMatrix->value[i] = trans[i];
		}
	}
	int t = myMatrix->row;
	myMatrix->row = myMatrix->column;
	myMatrix->column = t;
	free(trans);
}

void batchNorm(Matrix* myMatrix,double* mean,double* var,double* gamma,double* beta) {
	for (int i = 0; i < myMatrix->row; i++) {
		for (int j = 0; j < myMatrix->column; j++) {
			myMatrix->value[i * myMatrix->column + j] -= mean[j];
			myMatrix->value[i * myMatrix->column + j] /= var[j];
			myMatrix->value[i * myMatrix->column + j] = gamma[j] * myMatrix->value[i * myMatrix->column + j] + beta[j];
		}
	}
}
/*
void batchNormOnRow(Matrix* myMatrix, double gamma, double beta) {
	double* average = (double*)calloc(myMatrix->column, sizeof(double));
	double* std = (double*)calloc(myMatrix->column, sizeof(double));
	if (average != NULL && std != NULL) {
		for (int j = 0; j < myMatrix->column; j++) {
			double sum = 0.0;
			for (int i = 0; i < myMatrix->row; i++) {
				sum += myMatrix->value[i * myMatrix->column + j];
			}
			average[j] = sum / myMatrix->row;
		}
		for (int j = 0; j < myMatrix->column; j++) {
			double sum = 0.0;
			for (int i = 0; i < myMatrix->row; i++) {
				sum += pow(myMatrix->value[i * myMatrix->column + j] - average[j], 2);
			}
			std[j] = sqrt(sum / myMatrix->row);
		}
		for (int j = 0; j < myMatrix->column; j++) {
			for (int i = 0; i < myMatrix->row; i++) {
				myMatrix->value[i * myMatrix->column + j] -= average[j];
				myMatrix->value[i * myMatrix->column + j] /= std[j];
				myMatrix->value[i * myMatrix->column + j] = gamma * myMatrix->value[i * myMatrix->column + j] + beta;
			}
		}
	}
	free(average);
	free(std);
}
*/
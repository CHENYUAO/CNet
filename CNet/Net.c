/* @Chen Yuao
 * @2020.11.17
 * @模型从输入到输出的重构
 * 
 * 每需要一个新的Matrix，都需要先声明再初始化
 * 调用multiply(),add()和addDim()三个函数时，需要申请一个内存区域
 * 并使用这个内存区域对一个矩阵进行初始化，再将该矩阵地址传入函数
 * 
 * @2020.12.2更新
 * 为了避免在函数体内申请内存，函数体外释放，几个运算函数更改了形式
 * 应在函数体外部声明一个Matrix类型的变量，并用申请的内存进行初始化，
 * 将结果矩阵的地址作为参数传递给运算函数
 * 使用完后一定要手动释放内存
 * 例如：	Matrix mat3;
 *			double* mat3value = (double*)calloc(mat1.row * mat2.column, sizeof(double));
 *			initialize(&mat3, mat1.row, mat2.column, mat3value);
 *			multiply(&mat1, &mat2, &mat3);
 *			show(&mat3);
 *			free(mat3.value);
 */

#include "Net.h"
#include "weights.h"

void netCalculate(double input[][DATA_DIMENSION],int* result) {

	
	double* inputOneDim = (double*)calloc(DATA_BATCH * DATA_DIMENSION, sizeof(double));
	if (inputOneDim != NULL) {
		int k = 0;
		for (int i = 0; i < DATA_BATCH; i++) {
			for (int j = 0; j < DATA_DIMENSION; j++) {
				inputOneDim[k] = input[i][j];
				k++;
			}
		}
	}

	Matrix in;
	initialize(&in, DATA_BATCH, DATA_DIMENSION, inputOneDim);
	//transpose(&in);
	//show(&in);
	Matrix affine1;
	initialize(&affine1, FIRST_LAYER_ROW, FIRST_LAYER_COLUMN, w_1);
	//show(&affine1);
	Matrix affine2;
	initialize(&affine2, SECOND_LAYER_ROW, SECOND_LAYER_COLUMN, w_2);
	//show(&affine2);
	Matrix affine3;
	initialize(&affine3, THIRD_LAYER_ROW, THIRD_LAYER_COLUMN, w_3);
	//show(&affine3);
	
	Matrix affine1Out;
	double* affine1OutValue = (double*)calloc(in.row * affine1.column, sizeof(double));
	initialize(&affine1Out, in.row, affine1.column, affine1OutValue);
	multiply(&in, &affine1,  &affine1Out);
	addVec(&affine1Out, b_1);
	selu(&affine1Out);
	//sigmoid(&affine1Out);
	//show(&affine1Out);
	
	Matrix affine2Out;
	double* affine2OutValue = (double*)calloc(affine1Out.row * affine2.column, sizeof(double));
	initialize(&affine2Out, affine1Out.row, affine2.column, affine2OutValue);
	multiply(&affine1Out, &affine2, &affine2Out);
	addVec(&affine2Out, b_2);
	selu(&affine2Out);
	//sigmoid(&affine2Out);
	//show(&affine2Out);

	Matrix affine3Out;
	double* affine3OutValue = (double*)calloc(affine2Out.row * affine3.column, sizeof(double));
	initialize(&affine3Out, affine2Out.row, affine3.column, affine3OutValue);
	multiply(&affine2Out, &affine3, &affine3Out);
	addVec(&affine3Out, b_3);
	selu(&affine3Out);
	//sigmoid(&affine3Out);
	//show(&affine3Out);

	maxIndex(&affine3Out, result);
		
	free(in.value);
	free(affine1Out.value);
	free(affine2Out.value);
	free(affine3Out.value);	
}

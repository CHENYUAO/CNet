/* @Chen Yuao
 * @2020.11.17
 * @ģ�ʹ����뵽������ع�
 * 
 * ÿ��Ҫһ���µ�Matrix������Ҫ�������ٳ�ʼ��
 * ����multiply(),add()��addDim()��������ʱ����Ҫ����һ���ڴ�����
 * ��ʹ������ڴ������һ��������г�ʼ�����ٽ��þ����ַ���뺯��
 * 
 * @2020.12.2����
 * Ϊ�˱����ں������������ڴ棬���������ͷţ��������㺯����������ʽ
 * Ӧ�ں������ⲿ����һ��Matrix���͵ı���������������ڴ���г�ʼ����
 * ���������ĵ�ַ��Ϊ�������ݸ����㺯��
 * ʹ�����һ��Ҫ�ֶ��ͷ��ڴ�
 * ���磺	Matrix mat3;
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
	Matrix affine1;
	initialize(&affine1, FIRST_LAYER_ROW, FIRST_LAYER_COLUMN, w_1);
	Matrix affine2;
	initialize(&affine2, SECOND_LAYER_ROW, SECOND_LAYER_COLUMN, w_2);
	//show(&affine2);
	Matrix affine3;
	initialize(&affine3, THIRD_LAYER_ROW, THIRD_LAYER_COLUMN, w_3);
	//show(&affine3);

	batchNorm(&in, mean_1, var_1, 1.0, 0.0);
	Matrix affine1Out;
	double* affine1OutValue = (double*)calloc(in.row * affine1.column, sizeof(double));
	initialize(&affine1Out, in.row, affine1.column, affine1OutValue);
	multiply(&in, &affine1,  &affine1Out);
	addVec(&affine1Out, b_1);
	selu(&affine1Out);
	//sigmoid(&affine1Out);
	//show(&affine1Out);

	batchNorm(&affine1Out, mean_2, var_2, 1.0, 0.0);
	Matrix affine2Out;
	double* affine2OutValue = (double*)calloc(affine1Out.row * affine2.column, sizeof(double));
	initialize(&affine2Out, affine1Out.row, affine2.column, affine2OutValue);
	multiply(&affine1Out, &affine2, &affine2Out);
	addVec(&affine2Out, b_2);
	selu(&affine2Out);
	//sigmoid(&affine2Out);
	//show(&affine2Out);

	batchNorm(&affine2Out, mean_3, var_3, 1.0, 0.0);
	Matrix affine3Out;
	double* affine3OutValue = (double*)calloc(affine2Out.row * affine3.column, sizeof(double));
	initialize(&affine3Out, affine2Out.row, affine3.column, affine3OutValue);
	multiply(&affine2Out, &affine3, &affine3Out);
	addVec(&affine3Out, b_3);
	//selu(&affine3Out);
	//sigmoid(&affine3Out);
	//show(&affine3Out);

	maxIndex(&affine3Out, result);
		
	free(in.value);
	free(affine1Out.value);
	free(affine2Out.value);
	free(affine3Out.value);	
}

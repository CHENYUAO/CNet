/* @Chen Yuao
 * @2020.11.13
 * @Matrix.c��ͷ�ļ�
 * 
 * @2020.11.26
 * @���ڵ�ַ���ݵ�Ч��ԶԶ����ֵ���ݵ�Ч�ʣ���˽��������� Matrix ��Ϊ Matrix* 
 * @ʵ���˾���ת��transpose��batch normalize����
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>
/*************************************************************************************/

typedef struct {
	int row;            //row:����
	int column;         //column:����
	double* value;      //value��ָ��һ��һά�����ָ��
}Matrix;


/************************************************************************************/


/* �������ƣ�initialize  
 * ����������Matrix* myMatrix �� ��ʼ������ĵ�ַ
 *		int m, int n �� ��������������
 *		double* p �� ָ��һ����ά�����ָ��
 * 
 */
void initialize(Matrix* myMatrix, int m, int n, double* p);



/* �������ƣ�multiply
 * ����������Matrix* a, Matrix* b :     ���˷��������������ָ��
 *         Matrix* c �� ���ڴ���������ľ����ָ�룬��Ҫ����������ʼ��
 * 
 */
void multiply(Matrix* a, Matrix* b, Matrix* c);



/* �������ƣ�add
 * ����������Matrix* a, Matrix* b �� ���ӷ��������������ָ��
 *          Matrix* c �� ���ڴ���������ľ����ָ�룬��Ҫ����������ʼ��
 *
 */
void add(Matrix* a, Matrix* b, Matrix* c);


/* �������ƣ�addDim
 * ����������Matrix myMatrix
 *			Matrix* result : ���ڴ���������ľ���ָ�룬��Ҫ����������ʼ��һ��Matrix
 *
 * ��һά����������չһλ�����һλ��1
 * 
 */
void addDim(Matrix* myMatrix);

void addVec(Matrix* a, double* b);

/* �������ƣ�show
 * ����������Matrix myMatrix
 *
 * �ڿ���̨����ʾ����
 */
void show(Matrix* myMatrix);


//sigmoid�����
void sigmoid(Matrix* pointer);  

//relu�����
void relu(Matrix* pointer);     

void selu(Matrix* pointer);

/* �������ƣ�maxIndex
 * ����������Matrix* myMatrix
 * ����ֵ�����ֵ���±�+1
 *
 */
void maxIndex(Matrix* myMatrix,int* result);

/* �������ƣ�transpose
 * ����������Matrix* myMatrix
 * 
 * ������ת��
 */
void transpose(Matrix* myMatrix);

/* �������ƣ�batchNorm
 * ����������Matrix* myMatrix, double gamma, double beta
 *			myMatrix���������
 *			gamma:������
 *			beta��ƽ����
 * �Ծ������batch normalization����
 * 
 */
void batchNorm(Matrix* myMatrix, double* mean, double* var, double* gamma, double* beta);
/* @Chen Yuao
 * @2020.11.13
 * @Matrix.c的头文件
 * 
 * @2020.11.26
 * @由于地址传递的效率远远高于值传递的效率，因此将函数参数 Matrix 改为 Matrix* 
 * @实现了矩阵转置transpose和batch normalize函数
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>
/*************************************************************************************/

typedef struct {
	int row;            //row:行数
	int column;         //column:列数
	double* value;      //value：指向一个一维数组的指针
}Matrix;


/************************************************************************************/


/* 函数名称：initialize  
 * 函数参数：Matrix* myMatrix ： 初始化矩阵的地址
 *		int m, int n ： 矩阵行数和列数
 *		double* p ： 指向一个二维数组的指针
 * 
 */
void initialize(Matrix* myMatrix, int m, int n, double* p);



/* 函数名称：multiply
 * 函数参数：Matrix* a, Matrix* b :     做乘法运算的两个矩阵指针
 *         Matrix* c ： 用于存放运算结果的矩阵的指针，需要先声明并初始化
 * 
 */
void multiply(Matrix* a, Matrix* b, Matrix* c);



/* 函数名称：add
 * 函数参数：Matrix* a, Matrix* b ： 做加法运算的两个矩阵指针
 *          Matrix* c ： 用于存放运算结果的矩阵的指针，需要先声明并初始化
 *
 */
void add(Matrix* a, Matrix* b, Matrix* c);


/* 函数名称：addDim
 * 函数参数：Matrix myMatrix
 *			Matrix* result : 用于存放运算结果的矩阵指针，需要先声明并初始化一个Matrix
 *
 * 将一维向量长度扩展一位，最后一位置1
 * 
 */
void addDim(Matrix* myMatrix);

void addVec(Matrix* a, double* b);

/* 函数名称：show
 * 函数参数：Matrix myMatrix
 *
 * 在控制台上显示矩阵
 */
void show(Matrix* myMatrix);


//sigmoid激活函数
void sigmoid(Matrix* pointer);  

//relu激活函数
void relu(Matrix* pointer);     

void selu(Matrix* pointer);

/* 函数名称：maxIndex
 * 函数参数：Matrix* myMatrix
 * 返回值：最大值的下标+1
 *
 */
void maxIndex(Matrix* myMatrix,int* result);

/* 函数名称：transpose
 * 函数参数：Matrix* myMatrix
 * 
 * 将矩阵转置
 */
void transpose(Matrix* myMatrix);

/* 函数名称：batchNorm
 * 函数参数：Matrix* myMatrix, double gamma, double beta
 *			myMatrix：运算矩阵
 *			gamma:伸缩量
 *			beta：平移量
 * 对矩阵进行batch normalization处理
 * 
 */
void batchNorm(Matrix* myMatrix, double* mean, double* var, double gamma, double beta);
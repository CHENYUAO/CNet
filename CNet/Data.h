/* @Chen Yuao
 * @2020.11.20
 * @Data.c的头文件
 *
 */
#pragma once

#include<stdio.h>
#include"Net.h"
#include"Matrix.h"

/* 函数名称：getAverage
 * 函数参数：double data[][DATA_DIMENSION] : 进行相关计算的二维数组
 *			double* result : 存放运算结果的数组
 */
void getAverage(double data[][DATA_DIMENSION], double* result);


/* 函数名称：getStdDeviation
 * 函数参数：double data[][DATA_DIMENSION] : 进行相关计算的二维数组
 *			double* result : 存放运算结果的数组
 */
void getStdDeviation(double data[][DATA_DIMENSION], double* result);


/* 函数名称：dataDeal
 * 函数参数：double data[][DATA_DIMENSION] : 进行相关计算的二维数组
 * 函数解析：将缺失的数据（定义为DBL_MAX），以及异常值（与均值的差值大于三倍标准差的数据）填充为均值
 *			并进行数据规约（标准差标准化法）
 */
void dataNormalization(double data[][DATA_DIMENSION]);
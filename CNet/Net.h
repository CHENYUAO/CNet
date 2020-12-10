/* @Chen Yuao
 * @2020.11.17
 * @Matrix.c的头文件，此外包含了模型参数以及一些宏定义
 *
 */
#pragma once
#include"Matrix.h"
#include<float.h>

#define FIRST_LAYER_ROW      41
#define FIRST_LAYER_COLUMN   89
#define SECOND_LAYER_ROW     89
#define SECOND_LAYER_COLUMN  89
#define THIRD_LAYER_ROW      89
#define THIRD_LAYER_COLUMN   5

#define DATA_BATCH           128
#define DATA_DIMENSION       41

void netCalculate(double input[][DATA_DIMENSION],int* result);



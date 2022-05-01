#pragma once

#include <stdbool.h>
#include "stackAndQueue.h"

#define SMALLCARCOST 0.1	//小车每秒收费单元
#define BIGCARCOST 0.2		//大车每秒收费单元

bool inCar(Stack s, Queue q, Car item);		//车辆进入处理
bool outCar(Stack s, Queue q, Car item);	//车辆驶入处理
double carCost(Car item);	//计算费用
int addTime(STime st);		//计算时间
void printTime(STime st);	//打印时间
void printData(Car item);
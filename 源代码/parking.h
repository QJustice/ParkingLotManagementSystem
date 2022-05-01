#pragma once

#include <stdbool.h>
#include "stackAndQueue.h"

#define SMALLCARCOST 0.1	//С��ÿ���շѵ�Ԫ
#define BIGCARCOST 0.2		//��ÿ���շѵ�Ԫ

bool inCar(Stack s, Queue q, Car item);		//�������봦��
bool outCar(Stack s, Queue q, Car item);	//����ʻ�봦��
double carCost(Car item);	//�������
int addTime(STime st);		//����ʱ��
void printTime(STime st);	//��ӡʱ��
void printData(Car item);
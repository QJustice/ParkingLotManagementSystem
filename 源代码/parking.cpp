#include <stdio.h>
#include "parking.h"

bool inCar(Stack s, Queue q, Car item)
{
	if (s == NULL || q == NULL)
	{
		printf("空指针导致异常\n");
		return false;
	}
	//停车场未满
	if (!FullStack(s))
		Push(s, item);
	//便道未满
	else if (!QueueIsFull(q))
	{
		InsertQueue(q, item);
		printf("停车场已满，已停入便道\n");
	}
	//停车场与便道均满
	else
		printf("暂无空位\n");
	return true;
}

bool outCar(Stack s, Queue q, Car item)
{
	Car tempPS ;	//停车场最末尾的车	
	Car tempPPQ;	//使出的便道排第一的车
	if (!EmptyStack(s))
		GetTopStack(s, &tempPS);
	//若是停车场最尾车那么直接使出若便道有车那么进入补上
	if (item.num == tempPS.num)
	{
		Car tempPPS;	//使出的停车场最末尾的车
		//停车场最末尾的车离开
		Pop(s, &tempPPS);
		tempPPS.outTime = item.outTime;
		printData(tempPPS);
		//如果便道有车
		if (!QueueIsEmoty(q))
		{
			//便道的车进入停车场
			DeleteQueueHead(q, &tempPPQ);
			Push(s, tempPPQ);
		}
	}
	else
	{
		Car tempCar; //临时挪位车辆
		Stack parkingTemp = CreateStack();
		while (!EmptyStack(s))
		{
			//停车场的车离开
			Pop(s, &tempCar);
			if (tempCar.num == item.num)
			{			
				tempCar.outTime = item.outTime;
				printData(tempCar);
				break;
			}
			Push(parkingTemp, tempCar);
			
		}
		while (!EmptyStack(parkingTemp))
		{
			Pop(parkingTemp, &tempCar);
			Push(s, tempCar);
		}
		//销毁栈防止内存泄漏
		DestroyStack(&parkingTemp);
		//如果便道有车
		if (!QueueIsEmoty(q))
		{
			//便道的车进入停车场
			DeleteQueueHead(q, &tempPPQ);
			Push(s, tempPPQ);
			printf("便道首车已进入停车场\n");
		}
	}
	return false;
}

double carCost(Car item)
{
	if (item.type == 'S')	//小车
		return (addTime(item.outTime) - addTime(item.inTime)) * SMALLCARCOST;
	if (item.type == 'B')	//大车	
		return (addTime(item.outTime) - addTime(item.inTime)) * BIGCARCOST;
	//异常情况
	return 0.0;
}

int addTime(STime st)
{
	return st.hour * 3600 + st.min * 60 + st.sec;
}

void printTime(STime st)
{
	printf("%0d:%0d:%0d", st.hour, st.min, st.sec);
}

void printData(Car item)
{
	printf("车牌号%d的车进入时间是", item.num);
	printTime(item.inTime);
	printf(" 离开时间是");
	printTime(item.outTime);
	printf(" 总费用 %.2f\n", carCost(item));
}

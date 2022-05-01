#include <stdio.h>
#include "parking.h"

bool inCar(Stack s, Queue q, Car item)
{
	if (s == NULL || q == NULL)
	{
		printf("��ָ�뵼���쳣\n");
		return false;
	}
	//ͣ����δ��
	if (!FullStack(s))
		Push(s, item);
	//���δ��
	else if (!QueueIsFull(q))
	{
		InsertQueue(q, item);
		printf("ͣ������������ͣ����\n");
	}
	//ͣ������������
	else
		printf("���޿�λ\n");
	return true;
}

bool outCar(Stack s, Queue q, Car item)
{
	Car tempPS ;	//ͣ������ĩβ�ĳ�	
	Car tempPPQ;	//ʹ���ı���ŵ�һ�ĳ�
	if (!EmptyStack(s))
		GetTopStack(s, &tempPS);
	//����ͣ������β����ôֱ��ʹ��������г���ô���벹��
	if (item.num == tempPS.num)
	{
		Car tempPPS;	//ʹ����ͣ������ĩβ�ĳ�
		//ͣ������ĩβ�ĳ��뿪
		Pop(s, &tempPPS);
		tempPPS.outTime = item.outTime;
		printData(tempPPS);
		//�������г�
		if (!QueueIsEmoty(q))
		{
			//����ĳ�����ͣ����
			DeleteQueueHead(q, &tempPPQ);
			Push(s, tempPPQ);
		}
	}
	else
	{
		Car tempCar; //��ʱŲλ����
		Stack parkingTemp = CreateStack();
		while (!EmptyStack(s))
		{
			//ͣ�����ĳ��뿪
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
		//����ջ��ֹ�ڴ�й©
		DestroyStack(&parkingTemp);
		//�������г�
		if (!QueueIsEmoty(q))
		{
			//����ĳ�����ͣ����
			DeleteQueueHead(q, &tempPPQ);
			Push(s, tempPPQ);
			printf("����׳��ѽ���ͣ����\n");
		}
	}
	return false;
}

double carCost(Car item)
{
	if (item.type == 'S')	//С��
		return (addTime(item.outTime) - addTime(item.inTime)) * SMALLCARCOST;
	if (item.type == 'B')	//��	
		return (addTime(item.outTime) - addTime(item.inTime)) * BIGCARCOST;
	//�쳣���
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
	printf("���ƺ�%d�ĳ�����ʱ����", item.num);
	printTime(item.inTime);
	printf(" �뿪ʱ����");
	printTime(item.outTime);
	printf(" �ܷ��� %.2f\n", carCost(item));
}

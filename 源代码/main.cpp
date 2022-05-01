#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stackAndQueue.h"
#include "parking.h"

int main(void)
{
	Stack parking = CreateStack();
	Queue shortcut = CreateQueue();
	Car tempItem;
	STime st;
	printf("�밴����ȷ˳������:\n����״̬(����'A'���뿪'D'),���ƺţ��������ͣ���'B'��С��'S'),����ʱ����뿪ʱ��)\n");
	while (1)
	{		
		scanf("%c", &tempItem.state);
		if (tempItem.state == 'E')
			break;
		scanf("%d %c %d:%d:%d", &tempItem.num, &tempItem.type, &st.hour, &st.min, &st.sec);
		rewind(stdin);
		if (tempItem.state == 'A')
		{
			tempItem.inTime = st;
			inCar(parking, shortcut, tempItem);
		}
		if (tempItem.state == 'D')
		{
			tempItem.outTime = st;
			outCar(parking, shortcut, tempItem);
		}
		
	}
	//�ͷ��ڴ�
	DestroyStack(&parking);
	DestroyQueue(&shortcut);
	return 0;
}
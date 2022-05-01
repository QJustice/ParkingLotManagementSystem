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
	printf("请按照正确顺序输入:\n车辆状态(进入'A'或离开'D'),车牌号，车辆类型（大车'B'或小车'S'),进入时间或离开时间)\n");
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
	//释放内存
	DestroyStack(&parking);
	DestroyQueue(&shortcut);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stackAndQueue.h"

Stack CreateStack(void)
{
	//申请栈空间
	Stack s = (Stack)malloc(sizeof(struct SNode));
	if (s == NULL) //异常测试
	{
		printf("Function CreateStack error, error reason: memory request failed\n");
		return NULL;
	}
	//重置内存为0
	memset(s, 0, sizeof(struct SNode));
	//栈顶标记初始化
	s->top = -1;
	return s;
}

bool Push(Stack s, SElementType item)
{
	//将元素item置入栈顶
	if (s == NULL)	//异常判断
	{
		printf("Stack address empty\n");
		return false;
	}
	if (s->top == SMAXSIZE - 1)
	{
		printf("栈满状态\n");
		return false;
	}
	s->top++;
	s->data[s->top] = item;
	return true;

}

bool Pop(Stack s, SElementType* item)
{
	//将栈顶元素弹出
	if (s == NULL)	//异常判断
	{
		printf("Stack address empty\n");
		item = NULL;
		return false;
	}
	if (s->top == -1)
	{
		printf("Error!The empty stack\n");
		item = NULL;
		return false;
	}
	//带出栈顶元素
	*item = s->data[s->top];
	//栈指针下移
	s->top--;
	return true;
}

bool GetTopStack(Stack s, SElementType* item)
{
	//栈非空时带出栈顶元素但并不会弹出，栈顶将保留
	if (s == NULL)	//异常判断
	{
		printf("Stack address empty\n");
		item = NULL;
		return false;
	}
	if (s->top == -1)
	{
		printf("Error!The empty stack\n");
		item = NULL;
		return false;
	}
	//带出元素
	*item = s->data[s->top];
	return true;
}

bool EmptyStack(Stack s)
{
	//栈空时返回true否则返回false
	if (s == NULL)	//异常判断
	{
		printf("Stack address empty\n");
		return false;
	}
	if (s->top == -1)
		return true;
	return false;
}

bool FullStack(Stack s)
{
	if (s->top == SMAXSIZE - 1)
	{
		//printf("栈满状态\n");
		return true;
	}
	return false;
}

bool ClearStack(Stack s)
{
	//清空栈
	if (s == NULL)	//异常判断
	{
		printf("Stack address empty\n");
		return false;
	}
	s->top = -1;
	return false;
}

bool DestroyStack(Stack* s)
{
	if (s == NULL)	//异常判断
	{
		printf("Stack address empty\n");
		return false;
	}
	Stack kill = *s;
	free(kill);	//释放内存
	kill = *s = NULL;	//避免野指针
	return true;
}

Queue CreateQueue(void)
{
	//创建队列并初始化为一个空的循环队列
	Queue q = (Queue)malloc(sizeof(struct QNode));
	if (q == NULL)	//异常检查
	{
		printf("Function CreateQueue error, reason:memory request failed\n");
		return NULL;
	}
	//置零内存块
	memset(q, 0, sizeof(struct QNode));
	q->front = 0;
	q->rear = 0;

	return q;
}

bool InsertQueue(Queue q, QElementType item)
{
	//异常检测
	if (q == NULL)
	{
		printf("Function InsertQueue error, reason:queue address empty\n");
		return false;
	}

	//将元素item插入队列去
	if ((q->rear + 1) % QMAXSIZE == q->front)
	{
		printf("队列满\n");
		return false;
	}
	//队列元素赋值
	q->data[q->rear] = item;
	//队尾后移
	q->rear = (q->rear + 1) % QMAXSIZE;
	return true;
}

bool QueueIsEmoty(Queue q)
{
	//异常检测
	if (q == NULL)
	{
		printf("Function QueueIsEmoty error, reason:queue address empty\n");
		return false;
	}
	//空队列返回true
	if (q->front == q->rear)
		return true;
	return false;
}

bool QueueIsFull(Queue q)
{
	//异常检测
	if (q == NULL)
	{
		printf("Function QueueIsFull error, reason:queue address empty\n");
		return false;
	}
	//满队列返回true
	if ((q->rear + 1) % QMAXSIZE == q->front)
	{
		return true;
	}
	return false;
}

bool DeleteQueueHead(Queue q, QElementType* item)
{
	//异常检测
	if (q == NULL)
	{
		printf("Function DeleteQueueHead error, reason:queue address empty\n");
		item = NULL;
		return false;
	}
	if (q->front == q->rear)	//异常检测
	{
		printf("Queue is empty\n");
		item = NULL;
		return false;
	}
	//删除队头元素并带出
	//带出头元素
	*item = q->data[q->front];
	//队列头移动舍弃原队列头
	q->front = (q->front + 1) % QMAXSIZE;
	return true;
}

bool GetHeadQueue(Queue q, QElementType* item)
{
	//异常检测
	if (q == NULL)
	{
		printf("Function GetHeadQueue error, reason:queue address empty\n");
		item = NULL;
		return false;
	}
	if (q->front == q->rear)	//异常检测
	{
		printf("Queue is empty\n");
		item = NULL;
		return false;
	}
	//带出头元素
	*item = q->data[q->front];
	return true;
}

bool ClearQueue(Queue q)
{
	//异常检测
	if (q == NULL)
	{
		printf("Function ClearQueue error, reason:queue address empty\n");
		return false;
	}
	//重置队列头尾舍弃全部元素
	q->front = q->rear = 0;
	return true;
}

bool DestroyQueue(Queue* q)
{
	//异常检测
	if (q == NULL)
	{
		printf("Function DestroyQueue error, reason:queue address empty\n");
		return false;
	}
	Queue kill = *q;
	//释放内存
	free(kill);
	//避免野指针
	*q = kill = NULL;
	return true;
}

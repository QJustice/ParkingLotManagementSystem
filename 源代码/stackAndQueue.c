#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stackAndQueue.h"

Stack CreateStack(void)
{
	//����ջ�ռ�
	Stack s = (Stack)malloc(sizeof(struct SNode));
	if (s == NULL) //�쳣����
	{
		printf("Function CreateStack error, error reason: memory request failed\n");
		return NULL;
	}
	//�����ڴ�Ϊ0
	memset(s, 0, sizeof(struct SNode));
	//ջ����ǳ�ʼ��
	s->top = -1;
	return s;
}

bool Push(Stack s, SElementType item)
{
	//��Ԫ��item����ջ��
	if (s == NULL)	//�쳣�ж�
	{
		printf("Stack address empty\n");
		return false;
	}
	if (s->top == SMAXSIZE - 1)
	{
		printf("ջ��״̬\n");
		return false;
	}
	s->top++;
	s->data[s->top] = item;
	return true;

}

bool Pop(Stack s, SElementType* item)
{
	//��ջ��Ԫ�ص���
	if (s == NULL)	//�쳣�ж�
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
	//����ջ��Ԫ��
	*item = s->data[s->top];
	//ջָ������
	s->top--;
	return true;
}

bool GetTopStack(Stack s, SElementType* item)
{
	//ջ�ǿ�ʱ����ջ��Ԫ�ص������ᵯ����ջ��������
	if (s == NULL)	//�쳣�ж�
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
	//����Ԫ��
	*item = s->data[s->top];
	return true;
}

bool EmptyStack(Stack s)
{
	//ջ��ʱ����true���򷵻�false
	if (s == NULL)	//�쳣�ж�
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
		//printf("ջ��״̬\n");
		return true;
	}
	return false;
}

bool ClearStack(Stack s)
{
	//���ջ
	if (s == NULL)	//�쳣�ж�
	{
		printf("Stack address empty\n");
		return false;
	}
	s->top = -1;
	return false;
}

bool DestroyStack(Stack* s)
{
	if (s == NULL)	//�쳣�ж�
	{
		printf("Stack address empty\n");
		return false;
	}
	Stack kill = *s;
	free(kill);	//�ͷ��ڴ�
	kill = *s = NULL;	//����Ұָ��
	return true;
}

Queue CreateQueue(void)
{
	//�������в���ʼ��Ϊһ���յ�ѭ������
	Queue q = (Queue)malloc(sizeof(struct QNode));
	if (q == NULL)	//�쳣���
	{
		printf("Function CreateQueue error, reason:memory request failed\n");
		return NULL;
	}
	//�����ڴ��
	memset(q, 0, sizeof(struct QNode));
	q->front = 0;
	q->rear = 0;

	return q;
}

bool InsertQueue(Queue q, QElementType item)
{
	//�쳣���
	if (q == NULL)
	{
		printf("Function InsertQueue error, reason:queue address empty\n");
		return false;
	}

	//��Ԫ��item�������ȥ
	if ((q->rear + 1) % QMAXSIZE == q->front)
	{
		printf("������\n");
		return false;
	}
	//����Ԫ�ظ�ֵ
	q->data[q->rear] = item;
	//��β����
	q->rear = (q->rear + 1) % QMAXSIZE;
	return true;
}

bool QueueIsEmoty(Queue q)
{
	//�쳣���
	if (q == NULL)
	{
		printf("Function QueueIsEmoty error, reason:queue address empty\n");
		return false;
	}
	//�ն��з���true
	if (q->front == q->rear)
		return true;
	return false;
}

bool QueueIsFull(Queue q)
{
	//�쳣���
	if (q == NULL)
	{
		printf("Function QueueIsFull error, reason:queue address empty\n");
		return false;
	}
	//�����з���true
	if ((q->rear + 1) % QMAXSIZE == q->front)
	{
		return true;
	}
	return false;
}

bool DeleteQueueHead(Queue q, QElementType* item)
{
	//�쳣���
	if (q == NULL)
	{
		printf("Function DeleteQueueHead error, reason:queue address empty\n");
		item = NULL;
		return false;
	}
	if (q->front == q->rear)	//�쳣���
	{
		printf("Queue is empty\n");
		item = NULL;
		return false;
	}
	//ɾ����ͷԪ�ز�����
	//����ͷԪ��
	*item = q->data[q->front];
	//����ͷ�ƶ�����ԭ����ͷ
	q->front = (q->front + 1) % QMAXSIZE;
	return true;
}

bool GetHeadQueue(Queue q, QElementType* item)
{
	//�쳣���
	if (q == NULL)
	{
		printf("Function GetHeadQueue error, reason:queue address empty\n");
		item = NULL;
		return false;
	}
	if (q->front == q->rear)	//�쳣���
	{
		printf("Queue is empty\n");
		item = NULL;
		return false;
	}
	//����ͷԪ��
	*item = q->data[q->front];
	return true;
}

bool ClearQueue(Queue q)
{
	//�쳣���
	if (q == NULL)
	{
		printf("Function ClearQueue error, reason:queue address empty\n");
		return false;
	}
	//���ö���ͷβ����ȫ��Ԫ��
	q->front = q->rear = 0;
	return true;
}

bool DestroyQueue(Queue* q)
{
	//�쳣���
	if (q == NULL)
	{
		printf("Function DestroyQueue error, reason:queue address empty\n");
		return false;
	}
	Queue kill = *q;
	//�ͷ��ڴ�
	free(kill);
	//����Ұָ��
	*q = kill = NULL;
	return true;
}

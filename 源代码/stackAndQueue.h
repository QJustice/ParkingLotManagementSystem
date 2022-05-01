#pragma once

#include <stdbool.h>

#define SMAXSIZE 100	//ջ��С
#define QMAXSIZE 100	//���д�С

typedef char carState; //����״̬
typedef char carType;	//��������
typedef int carNumber;	//���ƺ�

typedef struct stopTime STime; 
typedef struct ParkingNode Parking;
typedef struct CarNode Car;

//ʱ��
struct stopTime
{
	int hour;  //Сʱ
	int min;	//����
	int sec;	//��
};

struct CarNode
{
	carState state; //����״̬
	carType type;	//��������
	carNumber num; //���ƺ�
	STime inTime;	//����ʱ��
	STime outTime;	//�뿪ʱ��
};

typedef struct SNode* Stack;
typedef Car SElementType;
typedef struct QNode* Queue;
typedef Car QElementType;

struct SNode
{
	SElementType data[SMAXSIZE];	//������
	int top;					//ջ�����
};

struct QNode
{
	QElementType data[QMAXSIZE];
	int front;
	int rear;
};

Stack CreateStack(void);	//��������ʼ��ջ
bool Push(Stack s, SElementType item); //ѹջ
bool Pop(Stack s, SElementType* item); //��ջ
bool GetTopStack(Stack s, SElementType* item);	//��ȡջ��Ԫ��
bool EmptyStack(Stack s);			//�ж�ջ�Ƿ�Ϊ��
bool FullStack(Stack s);			//�ж��Ƿ���ջ
bool ClearStack(Stack s);			//���ջ
bool DestroyStack(Stack* s);			//����ջ

Queue CreateQueue(void);	//��������ʼ������
bool InsertQueue(Queue q, QElementType item); //����Ԫ��
bool QueueIsEmoty(Queue q);		//�ж϶����Ƿ��
bool QueueIsFull(Queue q); //�ж϶����Ƿ���
bool DeleteQueueHead(Queue q, QElementType* item); //ɾ��ͷԪ��
bool GetHeadQueue(Queue q, QElementType* item); //��ȡͷԪ��
bool ClearQueue(Queue q); //��ն���
bool DestroyQueue(Queue* q); //���ٶ���

#pragma once

#include <stdbool.h>

#define SMAXSIZE 100	//栈大小
#define QMAXSIZE 100	//队列大小

typedef char carState; //车辆状态
typedef char carType;	//车辆类型
typedef int carNumber;	//车牌号

typedef struct stopTime STime; 
typedef struct ParkingNode Parking;
typedef struct CarNode Car;

//时间
struct stopTime
{
	int hour;  //小时
	int min;	//分钟
	int sec;	//秒
};

struct CarNode
{
	carState state; //车辆状态
	carType type;	//车辆类型
	carNumber num; //车牌号
	STime inTime;	//进入时间
	STime outTime;	//离开时间
};

typedef struct SNode* Stack;
typedef Car SElementType;
typedef struct QNode* Queue;
typedef Car QElementType;

struct SNode
{
	SElementType data[SMAXSIZE];	//数据域
	int top;					//栈顶标记
};

struct QNode
{
	QElementType data[QMAXSIZE];
	int front;
	int rear;
};

Stack CreateStack(void);	//创建并初始化栈
bool Push(Stack s, SElementType item); //压栈
bool Pop(Stack s, SElementType* item); //弹栈
bool GetTopStack(Stack s, SElementType* item);	//读取栈顶元素
bool EmptyStack(Stack s);			//判断栈是否为空
bool FullStack(Stack s);			//判断是否满栈
bool ClearStack(Stack s);			//清空栈
bool DestroyStack(Stack* s);			//销毁栈

Queue CreateQueue(void);	//创建并初始化队列
bool InsertQueue(Queue q, QElementType item); //插入元素
bool QueueIsEmoty(Queue q);		//判断队列是否空
bool QueueIsFull(Queue q); //判断队列是否满
bool DeleteQueueHead(Queue q, QElementType* item); //删除头元素
bool GetHeadQueue(Queue q, QElementType* item); //获取头元素
bool ClearQueue(Queue q); //清空队列
bool DestroyQueue(Queue* q); //销毁队列

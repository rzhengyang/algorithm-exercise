#ifndef _LIST_H
#define _LIST_H

typedef struct{
	int status;//状态，排列的序号
	int deep;
	char move; //父节点到本节点的移动方式/u/r/d/l
	struct Node *prior;//父节点指针
	struct Node *next; //指向下一个节点
}Node;

typedef struct{
	 Node *front;//队列头指针
	 Node *rear; //队列尾指针
}PointList;

PointList *p;
void ListCreat(void);
void ListInsert(char direction,unsigned int changednum,Node *fatherNode);
void ListOut(void);
void checkout(Node *checknode);
int EmptyQueue(void);

#endif

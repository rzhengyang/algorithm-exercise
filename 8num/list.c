#include "list.h"
#include <stdlib.h>
#include <stdio.h>
Node listnode;
//static Node *temp;
Node *list_q;
void ListCreat(void){
	Node *root;
	root = (Node *)malloc(sizeof(Node));
	p = root;
	root->deep = 0;
	root->prior = NULL;
	root->move = NULL;	
	root->status = NULL;
	p->front = root;
	p->rear = root;
	p->rear->next = NULL;
}
//入队列
void ListInsert(char direction,unsigned int changednum,Node *fatherNode)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->status = changednum;
	newnode->move = direction;
	newnode->next = NULL;
	newnode->prior = fatherNode;
	p->rear->next = newnode;
	p->rear = newnode;
}

//出队列
void ListOut(void)
{
	Node *s;
	if(EmptyQueue()){
		printf("已经空空的了\n");}
	else{
	s = p->front->next;
	p->front->next = s->next;
	if(s->next == NULL)
		p->rear = p->front;
	free(s);
	}
}
//判断为空
int EmptyQueue(void)
{
	if(p->front == p->rear)	
		return 1;
	else 
		return 0;
}
void checkout(Node *checknode)
{
	int i;
	Node *tempnode;
	tempnode = checknode;
	printf("\n顺藤摸瓜\n");
	for(i=0;i<4;i++){
	printf("%c ",tempnode->move);
	tempnode = tempnode->prior;
	}
	printf("\n");
}


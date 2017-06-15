#define LOCAL
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
typedef int bool;
#define false 0
#define true  1
int StartNum[9],EndNum[9],test[9];
unsigned int factNum[10],book[362880],answer[1000];
char answerChar[1000];
char sz4move[]="urdl";
unsigned int goalNum;
unsigned int CodeNum;
unsigned int beginNum;
unsigned int changednum;
//输出
void printout(void)
{
	int i,j;
	printf("...........\n\n");
	printf("起始为：\n");
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
		if(StartNum[3*j+i]==0)
			printf("0");
		else
			printf("%d",StartNum[3*j+i]);
		}
	printf("\n");
	}
	printf("...........\n\n");
	printf("最终为：\n");
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
		if(EndNum[3*j+i]==0)
			printf("0");
		else
			printf("%d",EndNum[3*j+i]);
		}
	printf("\n");
	}
	printf("...........\n\n");
}

//计算阶乘并保存起来
void factorialStore(void)
{
	int i,j,fanc;
	factNum[0] = 1;
	for(j=1;j<=9;j++)
	{
		factNum[j] = factNum[j-1]*j;
		printf("%d ",factNum[j]);
	}
	printf("\n阶乘保存完成。。。\n");
}

//从序号到数组 用到了逆序
void fromNumToList(int num,int *p)
{
	int i,j;
	for(i=9-1;i>=0;i--)
		p[i] = num%(9-i),num/=9-i;
	for(i=8;i;i--)
		for(j=i-1;j>=0;j--)
			if(p[j]<=p[i]) p[i]++;
}


//从数组到序号
unsigned int fromListToNum(int *dataList)
{
unsigned int numbCode,i,j,mincount;
	numbCode = 0;
	mincount = 0;
	//思路：有几个数比现在这组数的排列小？
	for(i=0;i<9;i++)
	{
			for(j=i;j<9;j++)
			{
					if(dataList[i]>dataList[j])
						mincount++;
			}
		numbCode = numbCode + mincount * factNum[8-i]; 
		mincount = 0;
	}
	
	return numbCode;
}

//判断奇偶性
int judeEven(void)
{
	int i,j,evenCount;
	int StartCount,EndCount;
	evenCount = 0;
		for(i=0;i<9;i++)	
			for(j=0;j<i;j++)
				if(StartNum[i]<StartNum[j] && StartNum[i]!=0 && StartNum[j]!=0)
					evenCount++;
	StartCount = evenCount;
	evenCount = 0;
		for(i=0;i<9;i++)	
			for(j=0;j<i;j++)
				if(EndNum[i]<EndNum[j] && EndNum[i]!=0 && EndNum[j]!=0)
					evenCount++;
	EndCount = evenCount;
	if((StartCount%2) == (EndCount%2)) return 1;
	return 0;
}

void BFS(char inputchar)
{
	unsigned char i,j,zeroPosition;
	unsigned int nowtestnum;
	unsigned int test_temp[9];
	
	//找到0在哪
	for(i=0;i<9;i++){
				if(test[i]==0) zeroPosition = i;
				test_temp[i] = test[i];
		}
	
		switch(inputchar)
		{
			case 'u':	
						if( zeroPosition < 3) ;
						else
							{
								test_temp[zeroPosition] = test_temp[zeroPosition-3];
								test_temp[zeroPosition-3] = 0;
							}
						break;
			case 'r':	
						if(zeroPosition%3 == 2) ;
						else
							{
								test_temp[zeroPosition] = test_temp[zeroPosition+1];
								test_temp[zeroPosition+1] = 0;
							}
						
						break;
			case 'd':	
						if(zeroPosition > 5) ;
						else
							{
								test_temp[zeroPosition] = test_temp[zeroPosition+3];		
								test_temp[zeroPosition+3] = 0; 
							}
						break;
			case 'l':
						if(zeroPosition%3 == 0) ;
						else
							{
								test_temp[zeroPosition] = test_temp[zeroPosition-1];		
								test_temp[zeroPosition-1] = 0; 
							}
						break;
			default: break;
		}
	ListInsert(inputchar,fromListToNum(test_temp),p->front);
}

int findRightAnswer(void)
{
	unsigned int i,j,k;
	j = 0;
	changednum = fromListToNum(test);
	if(changednum == goalNum)
		{
			printf("终于找到你，你就是答案\n");
			for(i=0;i<3;i++)
				printf("          .          \n");
			printf("我的答案是....\n");
			while(p->front->prior !=NULL)
			{
				p->front  = p->front->prior;
				answer[j] = p->front->status;//找到队列的第一个节点
				answerChar[j] = p->front->move;
				j++;
			}
			//这里输出答案
			while(j--){
				fromNumToList(answer[j],test);
			for(k=0;k<3;k++)
			{
				for(i=0;i<3;i++)
				{
					printf("%d",test[3*k+i]);
				}
				printf("\n");
			}
				if(j>=1)
					printf("\n    ...%c\n",answerChar[j-1]);
				printf(".........\n");
			}
///
printf("最后一步，最终结果:\n");
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
		if(EndNum[3*j+i]==0)
			printf("0");
		else
			printf("%d",EndNum[3*j+i]);
		}
	printf("\n");
	}
	printf("...........\n\n");
///
			return 1;
		}
	return 0;
}

//解决八数码问题
void solve8Number(void)
{
	int i;
	Node *nodeuse;
	ListCreat();//创建root节点
	
	ListInsert(NULL,beginNum,NULL);//将第一个节点入队列
	while(~(EmptyQueue()))
	{
    		p->front = p->front->next;//越过根节点
			fromNumToList(p->front->status,test);//找到队列的第一个节点
			if(findRightAnswer()) break;
			if(book[changednum]!=1)//判断这个节点是否被扩展过
				{
					for(i=0;i<4;i++) //将这个节点扩展
						BFS(sz4move[i]);
					book[changednum] = 1;//扩展之后将节点标记
				}
			//ListOut();
	}


/*	for(i=0;i<4;i++) 
		ListInsert(sz4move[i],beginNum);
	//测试输出，先挪动一位，用来越过root
	//ListOut();//测试出列
	p->front = p->front->next;
	for(i=0;i<4;i++) 
	{
		printf("%c \n",p->front->move);
		p->front = p->front->next;
	}*/
}

//输入函数
void printin(void)
{
int i,j;
char buff[100];
FILE *fs;
fs = freopen("start.in","r",stdin);	

//输入
	for(j=0;j<3;j++)
	{
		gets(buff);
		for(i=0;i<3;i++)
			if(buff[i] == ' ')
				StartNum[3*j+i] = 0;
			else{
				StartNum[3*j+i] = buff[i] - '0';				
				}
	}		
close(fs);
fs = freopen("end.in","r",stdin);	
//输入
	for(j=0;j<3;j++)
	{
		gets(buff);
		for(i=0;i<3;i++)
			if(buff[i] == ' ')
				EndNum[3*j+i] = 0;
			else{
				EndNum[3*j+i] = buff[i] - '0';				
				}
	}
close(fs);
}

//main
int main(void)
{
		int i;
		memset(book,0,sizeof(book));
		//保存1-9的阶乘数
		factorialStore();
		//输入输出
		printin();
		printout();
		beginNum = fromListToNum(StartNum);
		printf("数组变为序号 = %d\n",beginNum);
		fromNumToList(beginNum,test);
		//保存下目标值
		goalNum = fromListToNum(EndNum);
		for (i=0;i<9;i++)
			printf("%d ",test[i]);
		//判断奇偶性,是否有解
		if(judeEven() == 1)
			{
					printf("有解\n");
					solve8Number();
					return 1;
			}
		else
			{
					printf("无解\n");
					return 0;
			}
}

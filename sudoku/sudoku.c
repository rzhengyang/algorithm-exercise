o
#define LOCAL
#include<stdio.h>
#include<string.h>
typedef int bool;
#define false 0
#define true  1
int sudo[10][10],book[10][10],sudoOut[10][10];
//print out
void printOut(void)
{
int i,j;
for(j=0;j<9;j++){
	for(i=0;i<9;i++){
			if(sudo[j][i]==0)
				printf("  ");
			else
				printf("%d ",sudo[j][i]);
			}
		printf("\n");
	}
printf("\n");
}
bool rightDefine(int j,int i,int k)
{
	int m,n,t1,t2;
	//judge row
	for(n=0;n<9;n++){
		if(sudo[j][n] == k)
			return false;
	}	
	//judge column
	for(m=0;m<9;m++){
		if(sudo[m][i] == k)
			return false;
	}	
	//judge squared
	t1=(j/3)*3;
	t2=(i/3)*3;
	for(m=t1;m<t1+3;m++)
		for(n=t2;n<t2+3;n++){
			if(sudo[m][n]==k)
			return false;
			}
	return true;
}
//solve measure
void sudoSolve(int step)
{
	int i,j,k;
	bool flag;
	if(step>=81){
		printOut();
		return ;
	}
	j=step/9;
	i=step%9;
	if(sudoOut[j][i]!=0)
		sudoSolve(step+1);
	else{
		for(k=1;k<=9;k++){
			if(book[j][k]==0){
				flag=rightDefine(j,i,k);
				if(flag){
						book[j][k]=1;
						sudo[j][i]=k;
						sudoSolve(step+1);
						book[j][k]=0;
						sudo[j][i]=sudoOut[j][i];
					}
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("sudoku.in","r",stdin);
#endif
int i,j;
char buff[100];
for(i=0;i<10;i++)
	memset(book[i],0,10);
//former input
	for(j=0;j<9;j++){
		gets(buff);
		for(i=0;i<9;i++){
			if(buff[i]==' ')
				sudo[j][i]=0;
			else{
				sudo[j][i]=buff[i]-'0';
				book[j][(sudo[j][i])]=1;
			}
			sudoOut[j][i]=sudo[j][i];
		}
	}
//sudoSolve
	sudoSolve(0);
return 0;
}

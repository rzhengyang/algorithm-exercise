#include<stdio.h>
void main(){
	int a,b,c,d;
	for(a=1;a<10;a++){
		for(b=1;b<10;b++){
				for(c=1;c<10;c++){
					d=a*a*a+b*b*b+c*c*c;
					if(d<1000 && a<=b && a<=c && b<=c)
					printf("%d  ",d);	
				}
		}	
	}
}

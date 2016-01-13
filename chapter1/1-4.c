#include <stdio.h>
#include <math.h>
#define pi 4.0*atan(1.0)
int main()
{
	float a;
	scanf("%f",&a);
	printf("%f\n",sin((pi*a)/180));
	printf("%f\n",cos((pi*a)/180));
	return 0;
}

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void)
{
	int r;
	printf("\nRadius of Circle: ");
	scanf("%d",&r);
	
	int error=1;
	while(r<=0)
	{
		if(error>2)
		{
			printf("\nToo many attempts");
			printf("\nProgram terminated.\n");
			return 1;
		}
		else
		{
		printf("\nRadius must be greater than 0");
		printf("\nPlease try again: ");
		scanf("%d",&r);
		error++;
		}
	}
	
	float area;
	area=PI*r*r;
	printf("\nThe area is: %.2f\n",area);
	printf("\nThe circumference is: %.2f\n",2*PI*r);
	printf("\nTEST: The circumference is: %.2f\n",2*PI*r);
	return 0;
}

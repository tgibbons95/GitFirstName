#include <stdio.h>
#include <math.h>

int main(void)
{
	float cost,sell;
	printf("\nCost price: ");
	scanf("%f",&cost);
	
	int error=1;
	while(cost<=0)
	{
		if(error>2)
		{
			printf("\nToo many attempts");
			printf("\nProgram terminated.\n");
			return 1;
		}
		else
		{
		printf("\nCost price must be greater than 0");
		printf("\nPlease try again: ");
		scanf("%f",&cost);
		error++;
		}
	}
	
	printf("\nSelling price: ");
	scanf("%f",&sell);
	
	error=1;
	while(sell<=0)
	{
		if(error>2)
		{
			printf("\nToo many attempts");
			printf("\nProgram terminated.\n");
			return 2;
		}
		else
		{
		printf("\n Selling price must be greater than 0");
		printf("\nPlease try again: ");
		scanf("%f",&sell);
		error++;
		}
	}
	
	float profit;
	profit=sell-cost;
	
	if(profit>0)
		printf("\nThe profit is: %.2f\n",profit);
	else if(profit<0)
		printf("\nThe incurred loss is %.2f\n",profit);
	else
		printf("\nThere is no gain or loss\n");
		
	return 0;
}

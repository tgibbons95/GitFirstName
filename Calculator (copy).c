#include <stdio.h>
#include <math.h>

int main(void)
{
	float num1,num2, result;
	int error=1;
	char op;
	
	while(error==1)
	{
	error=0;
	printf("\nValue 1: ");
	scanf("%f",&num1);
	
	printf("\nOperator: ");
	scanf(" %c",&op);
	
	printf("\nValue 2: ");
	scanf("%f",&num2);
	
	switch(op) {
      case '+' :
         result=num1+num2;
         break;
      case '-' :
		 result=num1-num2;
		 break;
      case '*' :
         result=num1*num2;
         break;
      case '/' :
	  {
		 if(num2!=0)
         result=num1/num2;
		 else
		 {
		 error=1;
		 printf("\Can't divide by zero\nTry again\n" );
		 }
		 
	  }
         break;
     
      default :
	  {
         	printf("\nInvalid operator\nTry again\n" );
		error=1;
		break;
	  }
	}
	}
	printf("%f %c %f = %f\n",num1,op,num2,result);
	return 0;
}

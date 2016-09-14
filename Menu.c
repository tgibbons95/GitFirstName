#include <stdio.h>

void displayMenu();
char input(char* message);
unsigned long factorial(unsigned short num);
int leapYear(unsigned int year);
float maximum(float num1, float num2);
float division(int num1, int num2);
void switchStatement(char input);

int main(void)
{
	char choice='a';
	
	while(choice!='e' && choice!='E')
	{
        displayMenu();
		choice=input("\nChoice: ");
		if(choice<'A')
			return 1;

		switchStatement(choice);
	}

	return 0;
}

void displayMenu()
/*Displays text menu for user*/
{
	printf("\na) Factorial of a number");
	printf("\nb) Leap year or not");
	printf("\nc) Maximum of two numbers");
	printf("\nd) Division of two numbers");
	printf("\ne) Exit");
}

char input(char* message)
/*Asks user for inputed number after message
	Error Checks within a range
	Return -1 for error or users input*/
{
	char* error="\nPlease try again: ";
	char* terminate="\nProgram terminated\n";

	char n;
	printf("%s",message);
	scanf(" %c",&n);

	if(!(n>='a' && n<='e') && !(n>='A' && n<='E'))
	{
		printf("%s",error);
		scanf(" %c",&n);
	}
	if(!(n>='a' && n<='e') && !(n>='A' && n<='E'))
	{
		printf("%s",terminate);
		return 'A'-1;
	}
	return n;
}

unsigned long factorial(unsigned short num)
/*Finds the factorial of an unsigned short num
	Returns factorial result as unsigned long*/
{
	if(num<=1)
		return 1;
	else
		return num*factorial(num-1);
}

int leapYear(unsigned int year)
/*Takes a year and determines if it's a leap year
	Returns 1 if leap year 0 if not*/ 
{
	if(year%4==0)
		if(year%100==0)
			if(year%400==0)
				return 1;
			else
				return 0;
		else
			return 1;
	else
		return 0;
}

float maximum(float num1, float num2)
/*finds the max of 2 floating inputs
	Returns max value*/
{
	return (num1>num2)? num1:num2;
}

float division(int num1, int num2)
/*Divides two integer numbers
	Returns result as float*/
{
	float div;
	div=(float)num1/num2;
	return div;
}

void switchStatement(char input)
/*Takes input char and chooses the appropriate operations
	Does not return a value*/
{
	switch(input)
	{
		case 'a':
		case 'A':
		{
			/*data*/
			unsigned long fact=0;
			unsigned short in1=0;
			
			/*input and error check*/
			while(in1<1 || in1>25)
			{
				printf("\nInput number between 1 and 12: ");
				scanf("%u",&in1);
				
				if(in1<1 || in1>25)
			    printf("Number must be between 1 and 12. Please try again\n");
			}
			/*analyze and output*/
			fact=factorial(in1);
			printf("%u! = %lu\n",in1,fact);
			break;
		}
		case 'b':
		case 'B':
		{
			/*data*/
			unsigned int inputYear=0;

			/*input and error check*/
			while(inputYear<=0)
			{
				printf("\nInput year: ");
				scanf("%u",&inputYear);

				if(inputYear<=0)
			    printf("\nYear must be positive. Please try again");
			}

			/*analyze and output*/
			if(leapYear(inputYear)==1)
			    printf("%u is a leap year\n",inputYear);
			else
			    printf("%u is not a leap year\n",inputYear);
		}
			break;
		case 'c':
		case 'C':
		{
			/*data*/
			float num1, num2, max;
			
			/*input*/
            printf("\nNum1: ");
			scanf("%f",&num1);
			printf("Num2: ");
			scanf("%f",&num2);
			
			/*output and analyze*/
			max=maximum(num1,num2);
			printf("The maximum of %f and %f is %f\n",num1,num2,max);
			
		}
			break;
		case 'd':
		case 'D':
		{
			/*data*/
			int num=0,den=0;
			float quo;
			
			/*input and error check*/
			printf("\nNumerator: ");
			scanf("%d",&num);
			while(den==0)
			{
               	printf("Denominator: ");
				scanf("%d",&den);
				if(den==0)
				    printf("Cannot divide by zero. Please try again\n\n");
			}
		
		    /*analyze and output*/
			quo=division(num,den);
			printf("%d / %d = %f\n",num,den,quo);
		}
			break;
		case 'e':
		case 'E':
			printf("\nExitting program\n\n");
			break;
		default:
			//should never happen because of prior analysis
			printf("error");
			break;
	}
}


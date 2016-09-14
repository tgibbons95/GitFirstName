#include <stdio.h>

void displayMenu();
char input(char* message);
void switchStatement(char input);

int main(void)
{
	char choice='a';
	
	while(choice!='c' && choice!='C')
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
	printf("\na) Arithmetic Operations");
	printf("\nb) Bitwise Operations");
	printf("\nc) Exit");
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

	if(!(n>='a' && n<='c') && !(n>='A' && n<='C'))
	{
		printf("%s",error);
		scanf("  %c",&n);
	}
	if(!(n>='a' && n<='c') && !(n>='A' && n<='C'))
	{
		printf("%s",terminate);
		return 'A'-1;
	}
	return n;
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
			unsigned short in1=0,hold1;
			
			/*input and error check*/
			printf("\nInput positive number: ");
			scanf("%u",&in1);			
			int a=0, bin[16]={0};
			hold1=in1;


			/*analyze and store*/
			while(in1!=0)
			{
				bin[a]=in1%2;
				in1=in1/2;
				a++;
			}

			/*output result*/
			a=15;
			while(a>=0)
			{
				printf("%d",bin[a]);
				if(a%4==0)
				    printf(" ");
				a--;
			}
				printf(" = %u\n",hold1);
			break;
		}
		case 'b':
		case 'B':
		{
			/*data*/
            unsigned short in2=0;
            
			/*input and error check*/
			printf("\nInput positive number: ");
			scanf("%u",&in2);
			unsigned short mask=32768;
			int i=0;
			
			/*analyze and output*/
			for(i=0; i<16;i++)
			{
 			   	if ((in2 & mask)==0)
    				printf("0");
   			 	else
        			printf("1");
				if(i%4==3)
				    printf(" ");
				mask = mask >> 1;
			}
				printf(" = %u\n",in2);

		}
			break;
		case 'c':
		case 'C':
			printf("\nExitting program\n\n");
			break;
		default:
			//should never happen because of prior analysis
			printf("error");
			break;
	}
}


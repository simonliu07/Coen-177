//Simon Liu COEN 177 Lab 1
#include <stdio.h>

void main(){
	int x,y;
	
	printf("Hello World\n");
	
	printf("Enter an interger\n");
	scanf("%d",&x);
	printf("%d\n",x);
	
	printf("Enter two interger to add\n");
	scanf("%d %d", &x, &y);
	printf("%d\n", x+y);

	float num1, num2;
	printf("Enter two float numbers to multiply\n");
	scanf("%f %f", &num1, &num2);
	printf("%f\n", num1*num2);

	printf("Enter two interger to get the quotient and remainder\n");
	scanf("%d %d", &x, &y);
	printf("Quotient: %d Remainder: %d\n", x/y, x%y);

	int z;
	printf("Enter two intergers to switch\n");
	scanf("%d %d", &x , &y);
	z = x;
	x = y;
	y = z;
	printf("%d %d\n", x, y);
	
	printf("Enter an interger to chech odd or even\n");
	scanf("%d", &x);
	if(x%2 == 0)
		printf("Even\n");
	else
		printf("Odd\n");
	
	char word;
	printf("Enter a character\n");
	scanf(" %c", &word);
	if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u')
		printf("vowel\n");
	else 
		printf("consonant\n");
	
	printf("Enter three intergers\n");
	scanf("%d %d %d", &x, &y, &z);
	if( x < y)
		x = y;
	if( x < z)
		x = z;
	printf("The biggest interger is: %d\n", x);
	
}

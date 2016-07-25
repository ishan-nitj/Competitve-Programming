#include <stdio.h>

int main(void)
{
   int number;
   scanf("%d", &number);

   printf("The digital root of %d is %d.", number, (1 + (number - 1) % 9));
}


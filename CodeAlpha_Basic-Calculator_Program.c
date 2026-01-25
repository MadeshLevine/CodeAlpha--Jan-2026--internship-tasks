#include <stdio.h>
#include <stdlib.h>

int main()
{
    char op;
    float num1, num2;
    int int1, int2;
    printf("--- Simple Arithmetic Calculator ---\n");
    printf("Choose an operator:\n");
    printf("+  Addition\n");
    printf("-  Subtraction\n");
    printf("*  Multiplication\n");
    printf("/  Division\n");
    printf("%%  Modulus\n");
    printf("E or e  Exit\n");
    while (1)
    {
        printf("\nEnter operator (+, -, *, /, %%, (e or E)): ");
        scanf(" %c", &op);
        switch (op)
        {
            case '+':
                printf("Enter two numbers:\n");
                scanf("%f %f", &num1, &num2);
                printf("Addition of %f and %f is : %.2f\n",num1,num2,num1+num2);
                break;

            case '-':
                printf("Enter two numbers:\n");
                scanf("%f %f", &num1, &num2);
                printf("Subtraction of %f and %f is : %.2f\n",num1,num2,num1-num2);
                break;

            case '*':
                printf("Enter two numbers:\n");
                scanf("%f %f", &num1, &num2);
                printf("Multiplication of %f and %f is : %.2f\n",num1,num2,num1*num2);
                break;

            case '/':
                printf("Enter two numbers:\n");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0)
                    printf("Error: Division by zero is not allowed.\n");
                else
                    printf("Division of %f and %f is : %.2f\n",num1,num2,num1/num2);
                break;

            case '%':
                printf("Enter two integers:\n");
                scanf("%d %d", &int1, &int2);
                if (int2 == 0)
                    printf("Error: Modulus by zero is not allowed.\n");
                else
                   printf("Modulus of %d and %d is : %d\n", int1,int2,int1%int2);
                break;

            case 'E':
            case 'e':
                printf("Exiting calculator......\n");
                exit(0);

            default:
                printf("Invalid operator! Try again.\n");
        }
    }
    return 0;
}

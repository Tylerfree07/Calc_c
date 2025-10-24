#include <stdio.h>
//no functions or arrays//
#include <stdbool.h>

#include <math.h>
int main(void) {
    const char* DEVELOPER = "Tyler Freeman";
    const char* VERSION = "1";
    const char* DATE = "10/23/2025";

    printf("Welcome to my Command-Line calculator!!\n");
    printf(" Developer: %s\n", DEVELOPER);
    printf(" version: %s\n", VERSION);
    printf(" Development Date: %s\n", DATE);
    printf("----------------------------------------\n\n");
    while(true) {
    //calc logic//
        char operation, choice;
        int num1, num2, sum;
        float quotient;
        printf("Select one of the following operations:\n"
               "B) Binary Mathematical Operations, such as addition and subtraction.\n"
               "U) Unary Mathematical Operations, such as square root, and log.\n"
               "A) Advances Mathematical Operations, using variables, arrays.\n"
               "V) Define variables and assign them values.\n"
               "E) Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'B':
            case 'b':
                printf("Please enter the first number:\n ");
                scanf("%d", &num1);
                printf("Please enter the operator(+,-,*,/):\n");
                scanf(" %c", &operation);
                printf("Please enter the second number:\n ");
                scanf("%d", &num2);
                switch (operation) {
                    case '+':
                        sum = num1 + num2;
                        printf("The sum of %d and %d is %d\n", num1, num2, sum);
                        break;
                    case '-':
                        sum = num1 - num2;
                        printf("The difference of %d and %d is %d\n", num1, num2, sum);
                        break;
                    case '*':
                        sum = num1 * num2;
                        printf("The product of %d and %d is %d\n", num1, num2, sum);
                        break;
                    case '/':
                        quotient = (float)num1 / (float)num2;
                        if (num2 == 0) {
                            printf("Cannot divide by zero\n");
                        }
                        else {
                            printf("The quotient of %d and %d is %f\n", num1, num2, quotient);
                        }
                        break;
                    case '%':
                        sum = num1 % num2;
                        printf("The remainder of %d and %d is %d\n", num1, num2, sum);
                        break;
                    case'P':
                    case'p':
                        sum = pow(num1, num2);
                        printf("The power of %d and %d is %d\n", num1, num2, sum);
                        break;
                    case 'X':
                    case 'x':
                        sum = fmax(num1, num2);
                        printf("The maximum of %d and %d is %d\n", num1, num2, sum);
                    case 'I':
                    case 'i':
                        sum = fmin(num1, num2);
                        printf("The minimum of %d and %d is %d\n", num1, num2, sum);

                    default:
                        printf("Invalid operator\n");
                }
                break;
            case 'U':
            case 'u':
                printf("Unary Mathematical Operations\n");
                break;
            case 'A':
            case 'a':
                printf("Advances Mathematical Operations\n");
                break;
            case 'V':
            case 'v':
                printf("Define variables and assign them values.\n");
                break;
            case 'E':
            case 'e':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }





    }
    return 0;
}
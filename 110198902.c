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
        int num1, num2, result;
        float floatResult;
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
                        result = num1 + num2;
                        printf("The sum of %d and %d is %d\n", num1, num2, result);
                        break;
                    case '-':
                        result = num1 - num2;
                        printf("The difference of %d and %d is %d\n", num1, num2, result);
                        break;
                    case '*':
                        result = num1 * num2;
                        printf("The product of %d and %d is %d\n", num1, num2, result);
                        break;
                    case '/':
                        floatResult = (float)num1 / (float)num2;
                        if (num2 == 0) {
                            printf("Cannot divide by zero\n");
                        }
                        else {
                            printf("The quotient of %d and %d is %f\n", num1, num2, floatResult);
                        }
                        break;
                    case '%':
                        result = num1 % num2;
                        printf("The remainder of %d and %d is %d\n", num1, num2, result);
                        break;
                    case'P':
                    case'p':
                        result = pow(num1, num2);
                        printf("The power of %d and %d is %d\n", num1, num2, result);
                        break;
                    case 'X':
                    case 'x':
                        result = fmax(num1, num2);
                        printf("The maximum of %d and %d is %d\n", num1, num2, result);
                    case 'I':
                    case 'i':
                        result = fmin(num1, num2);
                        printf("The minimum of %d and %d is %d\n", num1, num2, result);

                    default:
                        printf("Invalid operator\n");
                }
                break;
            case 'U':
            case 'u':
                printf("Please enter the number:\n ");
                scanf("%d", &num1);
                printf("Please enter the operator(sqrt,log):\n");
                scanf(" %c", &operation);
                switch (operation) {
                    case 'S':
                    case 's':
                        floatResult = sqrt((float)num1);
                        printf("The square root of %d is %f\n", num1, floatResult);
                        break;
                    case 'L':
                    case 'l':
                        floatResult = log((float)num1);
                        printf("The log of %d is %f\n", num1, floatResult);
                        break;
                    case 'E':
                    case 'e':
                        floatResult = exp((float)num1);
                        printf("The exponential of %d is %f\n", num1, floatResult);
                        break;
                    case 'c':
                    case 'C':
                        floatResult = ceil((float)num1);
                        printf("The ceiling of %d is %f\n", num1, floatResult);
                        break;
                    case 'f':
                    case 'F':
                        floatResult = floor((float)num1);
                        printf("The floor of %d is %f\n", num1, floatResult);
                        break;
                    default:
                        printf("Invalid operator\n");
                }


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
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
        char operation, choice, var;
        int num1, num2, result, valid =0;
        float floatResult;
        double a,b,c,d,e, value, n1, n2;
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
                while (!valid) {
                    printf("Please enter the 1st integer: ");

                    if (scanf("%d", &num1) == 1) {
                        valid = 1;  // Successfully read a number
                    } else {
                        printf("Error: Invalid input. Please enter a valid number.\n");
                    }

                    while (getchar() != '\n');  // Clear buffer (newline + any extra chars)
                }
                valid = 0;
                    printf("Please enter the operator(+,-,*,/):\n");
                    scanf(" %c", &operation);
                while (!valid) {
                    printf("Please enter the second integer: ");

                    if (scanf("%d", &num2) == 1) {
                        valid = 1;  // Successfully read a number
                    } else {
                        printf("Error: Invalid input. Please enter a valid number.\n");
                    }

                    while (getchar() != '\n');  // Clear buffer (newline + any extra chars)
                }
                valid = 0;
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
                        break;
                    case 'I':
                    case 'i':
                        result = fmin(num1, num2);
                        printf("The minimum of %d and %d is %d\n", num1, num2, result);
                        break;

                    default:
                        printf("Invalid operator\n");
                        break;
                }
                break;
            case 'U':
            case 'u':
                printf("Please enter the operator(sqrt,log):\n");
                scanf(" %c", &operation);
                while (!valid) {
                    printf("Please enter the value: ");

                    if (scanf("%d", &num1) == 1) {
                        valid = 1;  // Successfully read a number
                    } else {
                        printf("Error: Invalid input. Please enter a valid number.\n");
                    }

                    while (getchar() != '\n');  // Clear buffer (newline + any extra chars)
                }
                valid = 0;
                switch (operation) {
                    case 'S':
                    case 's':
                        if (num1 < 0) {
                            printf("Error: Cannot take square root of negative number.\n");
                        } else {
                            floatResult = sqrt(num1);
                            printf("The square root of %.2d is %.2lf\n", num1, floatResult);
                        }
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
                        break;
                }
                break;
            case 'A':
            case 'a':
                printf("input choice(B,U,E): ");
                scanf(" %c", &choice);
                switch (choice) {
                    case 'B':
                    case 'b':
                        printf("Please enter the first number or variable (a-e): ");
                         // Read first character
                        if (scanf(" %c", &var) == 1) {
                            // Check if it's a variable (a-e or A-E)
                            if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E')) {
                                switch (var) {
                                    case 'a': case 'A': n1 = a; break;
                                    case 'b': case 'B': n1 = b; break;
                                    case 'c': case 'C': n1 = c; break;
                                    case 'd': case 'D': n1 = d; break;
                                    case 'e': case 'E': n1 = e; break;
                                }
                            }
                            else if ((var >= '0' && var <= '9') || var == '-' || var == '.') {
                                // Not a variable → likely a number, so push back and read full number
                                ungetc(var, stdin);
                                scanf("%lf", &n1);
                            }
                            else {
                                // Invalid variable
                                printf("Error: '%c' is not a valid variable (use a-e or a number).\n", var);
                                return 0; // or handle however you want (e.g., loop again)
                            }
                        }
                        printf("please enter the operation(+, -, *, /): ");
                        scanf(" %c", &operation);
                        printf("Please enter the second number or variable (a-e): ");
                        if (scanf(" %c", &var) == 1) {
                            // Check if it's a variable (a-e or A-E)
                            if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E')) {
                                switch (var) {
                                    case 'a': case 'A': n2 = a; break;
                                    case 'b': case 'B': n2 = b; break;
                                    case 'c': case 'C': n2 = c; break;
                                    case 'd': case 'D': n2 = d; break;
                                    case 'e': case 'E': n2 = e; break;
                                    default: printf("Invalid variable\n"); break;
                                }
                            }
                            else if ((var >= '0' && var <= '9') || var == '-' || var == '.') {
                                // Not a variable → likely a number, so push back and read full number
                                ungetc(var, stdin);
                                scanf("%lf", &n1);
                            }
                            else {
                                // Invalid variable
                                printf("Error: '%c' is not a valid variable (use a-e or a number).\n", var);
                                return 0; // or handle however you want (e.g., loop again)
                            }
                        }
                        switch (operation) {
                            case '+':
                                floatResult = n1 +n2;
                                printf("%f + %f = %f\n", n1, n2, floatResult);
                                break;
                            case '-':
                                floatResult = n1 - n2;
                                printf("%f - %f = %f\n", n1, n2, floatResult);
                                break;
                            case '*':
                                floatResult = n1 * n2;
                                printf("%f * %f = %f\n", n1, n2, floatResult);
                                break;
                            case '/':
                                floatResult = n1 / n2;
                                if (n2 == 0) {
                                    printf("Cannot divide by zero\n");
                                }
                                else {
                                    printf("%f / %f = %f\n", n1, n2, floatResult);
                                }
                                break;
                            case '%':
                                floatResult = (int)n1 % (int)n2;
                                printf("%f %% %f = %f\n", n1, n2, floatResult);
                                break;
                            case'P':
                            case'p':
                                floatResult = pow(n1, n2);
                                printf("The power of %f and %f is %f\n", n1, n2, floatResult);
                                break;
                            case 'X':
                            case 'x':
                                floatResult = fmax(n1, n2);
                                printf("The maximum of %lf and %lf is %f", n1, n2, floatResult);
                                break;
                            case 'I':
                            case 'i':
                                floatResult = fmin(n1, n2);
                                printf("The minimum of %lf and %lf is %f", n1, n2, floatResult);
                                break;

                            default:
                                printf("Invalid operator\n");
                        }
                    break;

                    case 'u':
                    case 'U':
                        printf("Please enter the operator(sqrt,log):\n");
                        scanf(" %c", &operation);
                        printf("Please enter the first number or variable (a-e): ");
                        // Read first character
                        if (scanf(" %c", &var) == 1) {
                            // Check if it's a variable (a-e or A-E)
                            if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E')) {
                                switch (var) {
                                    case 'a': case 'A': n1 = a; break;
                                    case 'b': case 'B': n1 = b; break;
                                    case 'c': case 'C': n1 = c; break;
                                    case 'd': case 'D': n1 = d; break;
                                    case 'e': case 'E': n1 = e; break;
                                    default: printf("Invalid variable\n"); break;
                                }
                            }
                            else {
                                // Not a variable → put back first char and read a number
                                ungetc(var, stdin);
                                scanf("%lf", &n1);
                            }
                        }
                        valid = 0;
                        switch (operation) {
                            case 'S':
                            case 's':
                                if (n1 < 0) {
                                    printf("Error: Cannot take square root of negative number.\n");
                                } else {
                                    floatResult = sqrt(n1);
                                    printf("The square root of %.2lf is %.2lf\n", n1, floatResult);
                                }
                                break;
                            case 'L':
                            case 'l':
                                floatResult = log(n1);
                                printf("The log of %lf is %f\n", n1, floatResult);
                                break;
                            case 'E':
                            case 'e':
                                floatResult = exp(n1);
                                printf("The exponential of %lf is %f\n", n1, floatResult);
                                break;
                            case 'c':
                            case 'C':
                                floatResult = ceil(n1);
                                printf("The ceiling of %lf is %f\n", n1, floatResult);
                                break;
                            case 'f':
                            case 'F':
                                floatResult = floor(n1);
                                printf("The floor of %lf is %f\n", n1, floatResult);
                                break;
                            default:
                                printf("Invalid operator\n");
                                break;
                        }
                        break;


                    case 'E':
                    case 'e':
                        printf("Exiting...");
                        break;
                }



                break;
            case 'V':
            case 'v':
                printf("Define or change a variable (a-e)\n");
                scanf(" %c", &operation);
                while (!valid) {
                    printf("Please enter the value: ");

                    if (scanf("%lf", &value) == 1) {
                        valid = 1;  // Successfully read a number
                    } else {
                        printf("Error: Invalid input. Please enter a valid number.\n");
                    }

                    while (getchar() != '\n');  // Clear buffer (newline + any extra chars)
                }
                valid = 0;
                switch (operation) {
                    case 'A':
                    case 'a':
                        a = (float)value;
                        break;
                    case 'b':
                    case 'B':
                        b = (float)value;
                        break;
                    case 'c':
                    case 'C':
                        c = (float)value;
                        break;
                    case 'd':
                    case 'D':
                        d = (float)value;
                        break;
                    case 'e':
                    case 'E':
                        e = (float)value;
                        break;
                    default:
                        printf("Invalid variable input\n");
                        break;
                }
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
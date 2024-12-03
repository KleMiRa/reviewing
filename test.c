#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
    int i = 0;
    while (i < argc){
        if (argc == 1) {
            printf("laba 1\n");
            printf("If you want see all commands, enter -h or --help\n");
            return 0;
        } 
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
            printf("All commands:\n");
            printf("1. When entering '-h' or '--help', the program will give a detailed help with the functionality of the program, if any problems suddenly arise.\n");
            printf("2. When entering '-t' or '--table', the program will output in tabular form the sizes of all simple types of the C/C++ language.\n");
            printf("3. When you enter '-c' or '--calc', the program will output 3 lines where you need to enter the first number-the arithmetic action-the second number.\n");
        }
        else if (strcmp(argv[i], "--table") == 0 || strcmp(argv[i], "-t") == 0) {
            printf("Table:\n");
            printf("char:\t\t%lu bytes\n", sizeof(char));
            printf("wchar_t:\t%lu bytes\n", sizeof(wchar_t));
            printf("short:\t\t%lu bytes\n", sizeof(short));
            printf("int:\t\t%lu bytes\n", sizeof(int));
            printf("long:\t\t%lu bytes\n", sizeof(long));
            printf("float:\t\t%lu bytes\n", sizeof(float));
            printf("long long:\t%lu bytes\n", sizeof(long long));
            printf("double:\t\t%lu bytes\n", sizeof(double));
            printf("long double:\t%lu bytes\n", sizeof(long double));
        }
        else if (strcmp(argv[i], "--calc") == 0 || strcmp(argv[i], "-c") == 0) {
            if (argc - i >= 4) {
                printf("Calcuation:\n");
                int a = atof(argv[2]);
                int b = atof(argv[4]);
                char oper = argv[3][0];
                if (oper == '+')
                    printf("Result of +: %d\n", a + b);
                else if (oper == '-')
                    printf("Result of -: %d\n", a - b);
                else if (oper == '*')
                    printf("Result of *: %d\n", a * b);
                else if (oper == '/')
                    printf("Result of /: %d\n", a / b);
                else {
                    printf("Something went wrong... Try again.\n");
                }
            }
            else {
                printf("ERROR! Use the help, to do this, enter -h.\n");
            }
        }
        i++;
    }
    return 0;
}

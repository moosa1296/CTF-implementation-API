#include <iostream>
#include <cstring>

void calculator()
{
    char num1[8];
    char buffer1[8];
    char num2[8];
    char buffer2[8];
    char operation[2];
    char bufferOp[2];

    std::cout << "Calculator\n";

    while (true)
    {
        std::cout << "Enter the first number (or 'q' to quit): ";
        std::cin >> num1;

        // Check for exit condition
        if (strcmp(num1, "q") == 0)
            return;

        std::cout << "Enter the operation (+, -, *, /): ";
        std::cin >> operation;

        // Intentional buffer overflow vulnerabilities
        strcpy(buffer1, num1);
        strcpy(bufferOp, operation);

        std::cout << "Enter the second number: ";
        std::cin >> num2;

        // Intentional buffer overflow vulnerability
        strcpy(buffer2, num2);

        double result;
        switch (bufferOp[0])
        {
            case '+':
                result = atof(buffer1) + atof(buffer2);
                break;
            case '-':
                result = atof(buffer1) - atof(buffer2);
                break;
            case '*':
                result = atof(buffer1) * atof(buffer2);
                break;
            case '/':
                result = atof(buffer1) / atof(buffer2);
                break;
            default:
                std::cout << "Invalid operation\n";
                return;
        }

        std::cout << "Result: " << result << "\n";
    }
}

int main()
{
    calculator();
    return 0;
}

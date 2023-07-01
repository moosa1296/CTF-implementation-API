#include <iostream>
#include <limits>

void printFlag() {
    std::cout << "Congratulations! You triggered the integer overflow and got the flag!\n";
    std::cout << "FLAG{example_flag}\n";
}

int main() {
    std::cout << "Integer Overflow Challenge\n";
    std::cout << "Enter positive numbers to add. Enter a negative number to trigger the integer overflow.\n";

    short acc = 0;
    short n;
    while (acc >= 0) {
        std::cout << "acc = " << acc << std::endl;
        std::cout << "Enter a number to add: ";

        if (!(std::cin >> n)) {
            std::cout << "Invalid value\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (n < 0) {
            n = std::abs(n);
        }

        n %= 100;
        acc += n;
        acc %= 100;
    }

    printFlag();

    return 0;
}


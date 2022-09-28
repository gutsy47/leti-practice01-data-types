#include <iostream>
#include <iomanip>

void printSizeOfTypes() {
    std::cout << "\n Data Type  | Size (bytes)\n";
    std::cout << "------------+-------------\n";
    std::cout << "        int | " << sizeof(int) << '\n';
    std::cout << "  short int | " << sizeof(short) << '\n';
    std::cout << "   long int | " << sizeof(long) << '\n';
    std::cout << "      float | " << sizeof(float) << '\n';
    std::cout << "     double | " << sizeof(double) << '\n';
    std::cout << "long double | " << sizeof(long double) << '\n';
    std::cout << "       char | " << sizeof(char) << '\n';
    std::cout << "       bool | " << sizeof(bool) << '\n';
}


std::string getBitsOfInt(int value, bool isDebug = false) {
    /*
     * Returns binary representation of int
     * :param value: int - decimal integer
     * :param isDebug: bool - displays every comparison if true
     * :return: std::string - binary representation of value
     */
    unsigned int order = sizeof(int) * 8;
    unsigned int mask = 1 << (order - 1);
    std::string binaryInt;
    for (int i = 1; i <= order; i++) {

        char bit = value & mask ? '1' : '0';

        // Display iteration details
        if (isDebug) {
            std::cout << value << " & " << std::setw(10) << mask << " = " << bit;
            std::string binaryValue = getBitsOfInt(value);
            std::string binaryMask = getBitsOfInt(int(mask));
            std::cout << " | " << binaryValue << "& " << binaryMask << '\n';
        }

        binaryInt += bit;
        mask >>= 1;

        if (i % 8 == 0 || i == 1)
            binaryInt += ' ';
    }
    return binaryInt;
}


int main() {

    std::cout.setf(std::ios::boolalpha);
    bool isDebug = false;

    // Main loop
    while (true) {

        // Get command number from user
        char userAction;
        std::cout << "<< Action: \n>> ";
        std::cin.sync();
        std::cin >> userAction;
        if (userAction == '0') {
            break;
        }

        switch (userAction) {

            // Print the amount of memory occupied by different types of data
            case '1': {
                std::cout << "Memory occupied by certain data types\n";
                printSizeOfTypes();
                break;
            }

            // Print the binary representation in memory of an integer
            case '2': {
                int userInput;
                std::cout << "<< Enter an integer \n>> ";
                std::cin.sync();
                std::cin >> userInput;
                if (std::cin.fail()) {
                    std::cout << "TypeError: invalid literal for int with base 10.\n";
                    std::cin.clear();
                    break;
                }
                std::cout << "Decimal integer: " << userInput << '\n';
                std::string binaryInt = getBitsOfInt(userInput, isDebug);
                std::cout << "Binary representation: " << binaryInt << '\n';
                break;
            }

            // Print the binary representation in memory of a float
            case '3': {
                float userInput;
                std::cout << "<< Enter a float \n>> ";
                std::cin.sync();
                std::cin >> userInput;
                if (std::cin.fail()) {
                    std::cout << "TypeError: invalid literal for float with base 10.\n";
                    std::cin.clear();
                    break;
                }
                std::cout << "Decimal float: " << userInput << '\n';
                break;
            }

            // Print the binary representation in memory of a double
            case '4': {
                double userInput;
                std::cout << "<< Enter a double \n>> ";
                std::cin.sync();
                std::cin >> userInput;
                if (std::cin.fail()) {
                    std::cout << "TypeError: invalid literal for double with base 10.\n";
                    std::cin.clear();
                    break;
                }
                std::cout << "Decimal double: " << userInput << '\n';
                break;
            }
            case '9': {
                isDebug = !isDebug;
                std::cout << "Debug mode: " << isDebug << '\n';
                break;
            }
            default: {
                std::cout << "RuntimeError: unknown command\n";
            }
        }
    }

    return 0;
}
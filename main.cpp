#include <iostream>

int main() {
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
                std::cout << "Memory sizes:\n";
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
            default: {
                std::cout << "RuntimeError: unknown command\n";
            }
        }
    }

    return 0;
}
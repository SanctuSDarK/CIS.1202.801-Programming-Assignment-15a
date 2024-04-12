/* David Belvin
CIS.1202.801
April 17th, 2024
Professor Bowman

CIS 1202 Programming Assignment #14
Inheritance
*/

#include <iostream>
#include <stdexcept>

// Exception for invalid characters
class invalidCharacterException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Character Exception";
    }
};

// Exception for invalid range
class invalidRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Range Exception";
    }
};

// Function to calculate character offsets
char character(char start, int offset) {

    // Check if start is a letter
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }

    // Calculate target character
    char target = start + offset;

    // Check if target has transitioned from upper to lowercase or vice versa
    if ((start >= 'A' && start <= 'Z' && (target < 'A' || target > 'Z')) ||
        (start >= 'a' && start <= 'z' && (target < 'a' || target > 'z'))) {
        throw invalidRangeException();
    }

    return target;
}

int main() {

    // Test values
    char testCases[][2] = {
        {'a', 1},
        {'a', -1},
        {'Z', -1},
        {'?', 5},
        {'A', 32}
    };

    for (auto& test : testCases) {
        try {
            char result = character(test[0], test[1]);
            std::cout << "character('" << test[0] << "', " << (int)test[1] << ") should return '" << result << "'.\n";
        }
        catch (const invalidCharacterException) {
            std::cout << "character('" << test[0] << "', " << (int)test[1] << ") should throw an invalidCharacterException.\n";
        }
        catch (const invalidRangeException) {
            std::cout << "character('" << test[0] << "', " << (int)test[1] << ") should throw an invalidRangeException.\n";
        }
    }

    return 0;
}

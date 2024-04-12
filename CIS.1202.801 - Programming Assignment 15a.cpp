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

    // Check if target is a valid letter
    if (!((target >= 'A' && target <= 'Z') || (target >= 'a' && target <= 'z'))) {
        throw invalidRangeException();
    }

    return target;
}

int main() {
    // Placeholder for driver code
    return 0;
}
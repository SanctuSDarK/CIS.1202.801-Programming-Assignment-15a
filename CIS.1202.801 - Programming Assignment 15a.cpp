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
    return start + offset; // Placeholder, to be replaced with actual logic
}

int main() {
    // Placeholder for driver code
    return 0;
}
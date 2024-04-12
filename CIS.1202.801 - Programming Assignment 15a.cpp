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

        // Exception message for an invalid character
        return "Invalid Character Exception";
    }
};

// Exception for invalid range
class invalidRangeException : public std::exception {
public:
    const char* what() const noexcept override {

        // Exception message for an invalid range
        return "Invalid Range Exception";
    }
};

// Function to calculate character offsets
char character(char start, int offset) {

    // Check if start is a letter
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {

        // Throw exception for non-letter start
        throw invalidCharacterException();
    }

    // Calculate target character
    char target = start + offset;

    // Check if target has transitioned from upper to lowercase or vice versa
    if ((start >= 'A' && start <= 'Z' && (target < 'A' || target > 'Z')) ||
        (start >= 'a' && start <= 'z' && (target < 'a' || target > 'z'))) {

        // Throw exception for invalid case transition
        throw invalidRangeException();
    }

    // Return the valid character
    return target;
}

int main() {

    // Initialize an array of test cases. Each test case is an array with a start character and an offset.
    char testCases[][2] = {

        // Test case: 'a' with an offset of 1 should return 'b'.
        {'a', 1},

        // Test case: 'a' with an offset of -1 is invalid (out of range).
        {'a', -1},
       
        // Test case: 'Z' with an offset of -1 should return 'Y'.
        {'Z', -1},
       
        // Test case: '?' is not a valid start character.
        {'?', 5},
       
        // Test case: 'A' with an offset of 32 is invalid (transitions from uppercase to lowercase).
        {'A', 32}
    };

    // Loop through each test case
    for (auto& test : testCases) {
        try {

            // Attempt to calculate the character using the start and offset values
            char result = character(test[0], test[1]);

            // If successful, output the expected result
            std::cout << "character('" << test[0] << "', " << (int)test[1] << ") should return '"
                << result << "'.\n";
        }
        catch (const invalidCharacterException) {

            // Catch block for invalid start characters, output the exception message
            std::cout << "character('" << test[0] << "', " << (int)test[1] 
                << ") should throw an invalidCharacterException.\n";
        }
        catch (const invalidRangeException) {

            // Catch block for invalid offset values that result in a character out of the valid range,
            // output the exception message
            std::cout << "character('" << test[0] << "', " << (int)test[1] 
                << ") should throw an invalidRangeException.\n";
        }
    }

    // Exit the program successfully
    return 0;
}

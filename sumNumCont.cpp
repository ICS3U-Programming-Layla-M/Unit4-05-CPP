// Copyright (c) Year Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: May 25, 2021
// This program asks the user for how many times to add
// numbers together and then adds them if they are whole
// numbers, otherwise it does not

#include <iostream>
#include <string>

int main() {
    // define variables
    int sum = 0, counter = 0, numberAsInt, timesAddedInt;
    std::string numberAsString, timesAddedString, sumAsString = "";

    while (true) {
        // ask user for how many numbers to add
        std::cout << "How many numbers do you want to add? ";
        std::cin >> timesAddedString;

        try {
            // convert from string to integer
            timesAddedInt = std::stoi(timesAddedString);

            if (timesAddedInt <= 0) {
                std::cout << timesAddedInt << " is not a "
                "positive number, try again.\n";
            } else {
                std::cout << "\n";
                while (counter < timesAddedInt) {
                    std::cout << "Enter a positive number to add: ";
                    std::cin >> numberAsString;

                    try {
                        // convert from string to integer
                        numberAsInt = std::stoi(numberAsString);
                        // check if input is a positive number
                        if (numberAsInt > 0) {
                            if (counter == 0) {
                                // first number in the addition
                                sum = sum + numberAsInt;
                                sumAsString = numberAsString;
                                counter = counter + 1;
                                continue;
                            } else {
                                // rest of the numbers in the addition
                                sum = sum + numberAsInt;
                                sumAsString = sumAsString + " +"
                                " " + numberAsString;
                                counter = counter + 1;
                                continue;
                            }
                        }  // check if number is negative
                        std::cout << numberAsInt << " is not a "
                        "positive number, try again.\n";
                    } catch (std::invalid_argument) {
                        std::cout << numberAsString << " is not a "
                        "positive number, try again.\n";
                    }
                } std::cout << "\n";
                std::cout << sumAsString << " = " << sum;
                break;
            }
        } catch (std::invalid_argument) {
            // error message
            std::cout << timesAddedString << " is not a "
            "positive number, try again.\n";
        }
    }
}

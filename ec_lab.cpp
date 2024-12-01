#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string& str);

double extractNumeric(const string& str) {
    bool decimalExists = false;
    bool signExists = false;
    bool digitExists = false;

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if ((c == '+' || c == '-') && i == 0) { // If there is a unary operator, check if it is only the first character
            signExists = true;
        }
        else if (isdigit(c)) { // If the character is a digit, continue and check the next character
            digitExists = true;
            continue;
        }
        else if (c == '.' && !decimalExists) { // If the character is a decimal, check if a decimal already exists in the string
            decimalExists = true;
        }
        else {
            return -999999.99; // If the string fails validation checks, return -999999.99
        }
    }

    if (!digitExists) {
        return -999999.99;
    }

    double value = 0.0;
    double decimalPortion = 0.0;
    double divisor = 10;
    bool decimalExistsNew = false;
    bool isNegative = (str[0] == '-');

    for (int i = (signExists ? 1 : 0); i < str.size(); i++) { //If the number is signed, start iterating at the second index (1) so it is not included 
        char c = str[i];

        if (c == '.') {
            decimalExistsNew = true;
            continue;
        }

        if (!decimalExistsNew) {
            value = value * 10 + (c - '0'); 
                                        
        } else {
            decimalPortion = decimalPortion + (c - '0') / divisor;
            divisor *= 10;

        }

        /*
        Move all the digits to the left by multiplying the value by 10
        then subtract '0' (ASCII value 48) from the current character's
        ASCII value.

        If a decimal exists, start working on the decimal portion of the number.
        Based on how many digits there are in the decimal portion, we will divide
        the next digit by the next multiple of 10 and add it to the decimal portion total.
        */
    }

    value += decimalPortion;
    if (isNegative) {
        value = -value;
    }

    return value;
}





int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        if (input.length() > 20) {
            cout <<"The input is invalid." << endl;
            continue;

        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout <<"The input is invalid." << endl;
        }
    }

    return 0;

}
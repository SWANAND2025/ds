#include <iostream>
using namespace std;

// ------------------------------
// Function to calculate length
// ------------------------------
int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// ------------------------------
// Function to copy one string to another
// ------------------------------
void stringCopy(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';   // Add null character
}

// ------------------------------
// Function to reverse a string
// ------------------------------
void stringReverse(char str[]) {
    int start = 0;
    int end = stringLength(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// ------------------------------
// Function to concatenate two strings
// ------------------------------
void stringConcatenate(char str1[], char str2[]) {
    int len1 = stringLength(str1);
    int i = 0;

    // move str2 elements into str1
    while (str2[i] != '\0') {
        str1[len1 + i] = str2[i];
        i++;
    }

    str1[len1 + i] = '\0';
}

// ------------------------------
// Main Function
// ------------------------------
int main() {
    char str1[100], str2[100], copyStr[100];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    cout << "\nLength of string 1 = " << stringLength(str1) << endl;

    stringCopy(str1, copyStr);
    cout << "Copied string = " << copyStr << endl;

    stringReverse(str1);
    cout << "Reversed string 1 = " << str1 << endl;

    stringConcatenate(str1, str2);
    cout << "Concatenated string = " << str1 << endl;

    return 0;
}

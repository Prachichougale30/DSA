#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeatingChar(string str) {
    unordered_map<char, int> freq;

    // 1. Count frequency of each character
    for (char ch : str) {
        freq[ch]++;
    }

    // 2. Find the first character with frequency = 1
    for (char ch : str) {
        if (freq[ch] == 1) {
            return ch;
        }
    }

    // 3. If no non-repeating character found
    return 0;  // NULL character
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    char result = firstNonRepeatingChar(str);

    if (result != 0) {
        cout << "First non-repeating character: " << result << endl;
    } else {
        cout << "No non-repeating character found." << endl;
    }

    return 0;
}

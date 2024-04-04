#include <iostream>
#include <unordered_map>

using namespace std;

int romanCharValue(char r) {
    switch (r) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToDecimal(string s) {
    int result = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        int s1 = romanCharValue(s[i]);
        if (i + 1 < n) {
            int s2 = romanCharValue(s[i + 1]);
            if (s1 >= s2) {
                result = result + s1;
            }
            else {
                result = result + s2 - s1;
                i++;
            }
        }
        else {
            result = result + s1;
        }
    }
    return result;
}

int main() {
    string romanNumeral;
    cout << "Enter a Roman numeral or Q to quit: ";
    cin >> romanNumeral;
    int decimalValue = romanToDecimal(romanNumeral);
    cout << romanNumeral << " = " << decimalValue << endl;
}

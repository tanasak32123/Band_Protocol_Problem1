#include <iostream>
#include <string>

using namespace std;

/*
    Problem 1: Boss Baby's Revenge
    This time complexity is O(n).
    This memory complexity is O(n).
*/
int main () {
    string s;
    cin >> s;

    // trivial case: if string length is 1 and first index is R character
    if (s.length() == 1 || s.at(0) == 'R') {
        cout << "Bad boy" << "\n";
        return 0;
    }

    bool isGoodBoy = true;
    unsigned int sCount = 1; // string begin with S...
    unsigned int rCount = 0;
    for (unsigned int i = 1; i < s.length(); i++) {
        if (s[i] == 'S' && s[i - 1] == 'R') {
            if (rCount < sCount) {
                isGoodBoy = false;
                break;
            }
            sCount = 1; rCount = 0;
            continue;
        }

        if (s[i] == 'S') sCount++;
        if (s[i] == 'R') rCount++;
    }

    if (sCount > rCount) { isGoodBoy = false; }

    if (isGoodBoy) {
        cout << "Good Boy" << "\n";
    } else {
        cout << "Bad Boy" << "\n";
    }

    return 0;
}

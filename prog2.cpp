#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

       
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int length = 0;

 
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int result = obj.lengthOfLastWord(s);
    cout << "Length of last word: " << result << endl;

    return 0;
}

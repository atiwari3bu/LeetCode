#include<stdlib.h>

class Solution {
public:
    bool isPalindrome(int x) {
        string org=to_string(x);
        string rev;
        for(auto iter=org.end()-1;iter>=org.begin();--iter){
            rev.push_back(*iter);
        }
        if(org==rev) return true;
        else return false;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}


int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

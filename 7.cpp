#include<string>

class Solution {
public:
    int reverse(int x) {
        long int num=0;
        while(x!=0){
            num=num*10+x%10;
            if(num>INT_MAX || num<INT_MIN) return 0;
            x=x/10;
        }
        return (int)num;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}


int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

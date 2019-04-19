class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        for(int i=1;(n/pow(5,i))!=0;++i){
            count+=n/pow(5,i);
        }
        return count;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

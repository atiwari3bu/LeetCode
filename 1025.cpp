class Solution {
public:
    bool divisorGame(int N) {
        int dp[1001] = {0};
        for(int i=2;i<=N;++i){
            for(int j=1;j<=i/2;++j){
                if(i%j==0 && !dp[i-j]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[N];
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
        int N = stringToInteger(line);
        
        bool ret = Solution().divisorGame(N);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

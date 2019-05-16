class Solution {
public:
    string convertToTitle(int n) {
        if(n==0) return "";
        map<int,char> mp;
        for(int i=65;i<91;++i){
            mp.insert(make_pair(i-65,char(i)));
        }
        
        string ans;
        while(n>0){
            ans.insert(ans.begin(),mp[(n-1)%26]);
            n=(n-1)/26;
        } 
        
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().convertToTitle(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}

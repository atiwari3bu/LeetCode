class Solution {
public:
    string logic(string temp){
        int count,j,i;
        string str="";
        for(i=0;temp[i]!='\0';++i){
            count=0;
            for(j=i;temp[j]!='\0';++j){
                if(temp[j]==temp[i]) ++count;
                else break;
            }
            string temp1=std::to_string(count)+temp[i];
            str+=temp1;
            i=j-1;
        }
        
        return str;
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";
        string str="1";
        
        for(int i=2;i<=n;++i){
            str=logic(str);
        }
        return str;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}

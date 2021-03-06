class Solution {
public:
    string customSortString(string S, string T) {
        string ans;
        map<char,int> mp;
        for(auto& c: T) mp[c]++;
        
        for(auto& c : S){
            if(mp.find(c)!=mp.end()){
                while(mp[c]>0){
                    ans+=c;
                    mp[c]--; 
                }
                //mp.erase(c);
            }
        }
        
        for(auto& elem:mp){
            while(elem.second>0){
                ans+=elem.first;
                (elem.second)--;
            }
        }
        
        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        getline(cin, line);
        string T = stringToString(line);
        
        string ret = Solution().customSortString(S, T);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}

class Solution {
public:
    int titleToNumber(string s) {
        map<char,int> hash_map;
        int sum=1;
        for(int i=1;i<=26;++i){
            hash_map.insert(pair<char,int>((char)(i+64),i));
        }
        for(int i=s.length()-1,j=0;i>=0;--i,++j){
            sum+=(hash_map.find(s[i])->second)*pow(26,j);
        }
        return (sum-1);
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
        string s = stringToString(line);
        int ret = Solution().titleToNumber(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

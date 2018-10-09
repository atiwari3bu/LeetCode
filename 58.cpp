class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0,i;
        
        for(i=s.length()-1;i>=0;--i){
            if(i==s.length()-1 && s[i]==' '){
                s.erase(i);
                continue;
            }
            if(s[i]!=' ') ++length;
            else break;
        }
        
        return length;
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
        int ret = Solution().lengthOfLastWord(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

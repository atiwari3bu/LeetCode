class Solution {
public:
    struct letter{
        char letter;
        int freq;
    };
    
    string frequencySort(string s) {
        
        letter letters[128]={0};
        for(auto c : s){
            int index=(int)c;
            letters[index].letter=c;
            ++(letters[index].freq);
        }
        
        sort(letters,letters+127,[](auto& a1,auto& a2){return a1.freq>a2.freq;});
        string temp;
        for(int i=0,j=0;i<s.length(),j<s.length();++i){
            for(int k=0;k<letters[i].freq;++k){
                temp+=letters[i].letter;
            }
            j+=letters[i].freq;
        }
      
        return temp;
        
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
        
        string ret = Solution().frequencySort(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}

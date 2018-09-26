class Solution {
public:
    
    void showStack(std::stack<char> st){  // For debugging
        while(!st.empty()){
            cout<<st.top()<<endl;
            st.pop();
        }
    }
    
    bool isValid(string s) {
        std::stack<char> st;
        if(*s.begin()==')' || *s.begin()==']' || *s.begin()=='}') return false;
        for(auto iter=s.begin();iter!=s.end();++iter){
            if(*iter=='(' || *iter=='{' || *iter=='[') st.push(*iter);
            else{
                if(st.size()==0) return false;
                else if(st.top()=='(' && *iter==')'){
                    st.pop();
                    continue;
                }
                else if(st.top()=='[' && *iter==']'){
                    st.pop();
                     continue;
                }
                else if(st.top()=='{' && *iter=='}'){ 
                    st.pop();
                    continue;
                }
                else return false;
            }
        }
        if(st.size()!=0) return false;
        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

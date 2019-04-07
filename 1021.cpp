class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        stack<char> st;
        
        for(int i=0;i<S.length();++i){
            if(!st.empty()){
                if(S[i]==')')  st.pop();
                else st.push(S[i]);
                if(!st.empty())  ans.push_back(S[i]);
            }
            else st.push(S[i]);
        }
        return ans;
    }
};

class Solution {
    public:
    string editString(string& str){
        string ans;
        
        for(int i=0;i<str.length();++i){
            if(str[i]=='#'){
                if(ans.length()>0) ans.pop_back();
            }
            else ans+=str[i];
        }
        
        return ans;
    }

    bool backspaceCompare(string S, string T) {
        return editString(S) == editString(T);
    }
};

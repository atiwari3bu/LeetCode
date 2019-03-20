class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return true;
        for(int i=0;i<s.length();){
            int temp=s[i];
            if((temp>=48 && temp<=57) || (temp>=65 && temp<=90) || (temp>=97 && temp<=122)){
                if(temp>=65 && temp<=90){
                    s[i]=s[i]+32;
                }
                ++i;
            } 
            else s.erase(s.begin()+i);
        }
        for(int i=0,j=s.length()-1;i<j;++i,--j){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
};

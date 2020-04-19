class Solution {
public:
    
    /*https://leetcode.com/problems/valid-parenthesis-string/discuss/107570/JavaC%2B%2BPython-One-Pass-Count-the-Open-Parenthesis*/
    
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;

        for(auto& ch : s){
            if(ch=='('){
                ++cmin;
                ++cmax;
            }
            
            else if(ch==')'){
                --cmax;
                cmin = max(cmin-1,0);
            }
            
            else{
                ++cmax;
                cmin = max(cmin-1,0);
            }
            
            if(cmax < 0) return false;
        }
        
        return cmin==0;
    }
};

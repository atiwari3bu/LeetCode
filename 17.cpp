class Solution {
public:
    void dfs(int i,vector<string>& combs,string temp,vector<string>& ans,string& digits){
        if(temp.length()>digits.length()) return;
        else if(temp.length()==digits.length()) ans.push_back(temp);
        else{
            int no=digits[i]-'0';
            for(auto& c : combs[no]){
                dfs(i+1,combs,temp+c,ans,digits);
            }
        }
       
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return vector<string>{}; // Edge Case
        vector<string> combs{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        vector<string> ans;
        int i=0;
        dfs(i,combs,temp,ans,digits);
        return ans;
    }
};

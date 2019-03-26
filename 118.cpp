class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows==0) return ans;
        ans[0].push_back(1);
        if(numRows==1) return ans;
        
        for(int i=1;i<numRows;++i){
            ans[i].push_back(1);
            for(int j=0;j+1<ans[i-1].size();++j){
                ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }   
};

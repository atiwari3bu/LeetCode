class Solution {
public:
    void recursion(vector<int>& candidates,int next,vector<int>& sol,int target,vector<vector<int>>& ans){
        if(target==0) {
            ans.push_back(sol);
            return;
        }
        if(next==candidates.size() || target - candidates[next] < 0){
            return ;
        }
        
        sol.push_back(candidates[next]);
        recursion(candidates,next,sol,target-candidates[next],ans);
        sol.pop_back();
        
        recursion(candidates,next+1,sol,target,ans);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> sol;
        recursion(candidates,0,sol,target,ans);
        return ans;
    }
};

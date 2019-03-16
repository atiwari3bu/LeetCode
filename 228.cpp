class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return ans;
        
        for(int i=0;i<nums.size();){
            int start=i;
            int end=i;
            
            while(end+1 < nums.size() && nums[end+1]==nums[end]+1) ++end;
            if(end>start){
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            else ans.push_back(to_string(nums[end]));
            i=end+1;
        }
        
        return ans;
    }
};

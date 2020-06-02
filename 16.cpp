class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close_target = 0;
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();++i){
            int j = i+1, k = nums.size()-1;
            
            while(j<nums.size() && k>=0 && j<k){
                
                int curr_target = nums[i]+nums[j]+nums[k];
                
                if(abs(curr_target-target) < diff){
                    close_target = curr_target;
                    diff = abs(curr_target-target);
                    
                }
                
                if(curr_target==target){ 
                    return target;
                }
                else if(curr_target<target){ 
                    ++j;
                }
                else {
                    --k;
                }
                
            }
        }
        
        return close_target;
    }
};

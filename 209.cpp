class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int end = 0;
        
        int len = INT_MAX;
        int curr_sum = 0;
        
        while(end<nums.size()){
            curr_sum += nums[end];
            ++end;
            
            while(curr_sum >= s){
                len = min(len,end-start);
                curr_sum -= nums[start];
                ++start;
            }
            
        }
        
        return len == INT_MAX ? 0 : len;
    }
};

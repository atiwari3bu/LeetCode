class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int jump = 0;
        
        for(int i=0;i<n;++i){
            if(jump<i) return false;
            
            int elem = nums[i];
            jump = max(jump,elem+i);
        }
        
        return true;
        
    }
};

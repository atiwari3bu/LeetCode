class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
    
        while(low<=high){
    
            int mid = (low+high)/2;
    
            int mid_val = nums[mid]; 
            if(mid_val == target) return true;
            
            if(nums[low]==mid_val && nums[high]==mid_val){ // O(n) worst case
                auto iter = find(nums.begin(),nums.end(),target);
                
                if(iter!=nums.end()) return true;
                else return false;
            }
    
            if(mid_val > nums[low]){ //left half is sorted 
                if( nums[low] <= target  && target < mid_val){
                    high = mid - 1;
                }   
                else{
                    low = mid+1;
                }   
            }   
    
            else if(mid_val < nums[high]){ // right half is sorted
                if(nums[high] >= target && target > mid_val){
                    low = mid + 1;
                }   
                else{
                    high = mid - 1;
                }   
            }   
    
            else{  // rotated completely
               if(mid_val < target){
                   high = mid - 1;  
               }   
               else{
                   low = mid + 1;
               }   
            }   
        }   
    
        return false; 
    }   
};

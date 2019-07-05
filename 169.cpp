class Solution {
    /*
    This is a special type of problem which does exactly the question asks.
    The majority element must be more than half of size of array.
    
    If the test case is I input {3,3,4,6,7}, it returns 7, instead of 3....
    which is not the majority as it is not more than n/2.
    
    https://leetcode.com/problems/majority-element/discuss/51613/O(n)-time-O(1)-space-fastest-solution
    */
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        
        for(auto& num: nums){
            if(++mp[num]>n/2) return num;
        }
        
        return 0; 
    }
};

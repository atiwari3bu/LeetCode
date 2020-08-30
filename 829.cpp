class Solution {
public:
    /*https://leetcode.com/problems/consecutive-numbers-sum/discuss/129015/5-lines-C%2B%2B-solution-with-detailed-mathematical-explanation.*/
    
    
    int consecutiveNumbersSum(int N) {
        
        int ans = 1;
        
        for(int k=2; k<sqrt(2*N);++k){
            if((N-(k*(k-1)/2))%k == 0) ++ans;     
        }
        
        return ans;
        
    }
};

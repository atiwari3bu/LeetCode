class Solution {
public:
    vector<int> convertToBinary(int num,int max){
        vector<int> temp;
        while(num!=0){
            temp.push_back(num & 1);
            num=num>>1;
        }
        
        for(int i=temp.size();i<max;++i){
            temp.push_back(0);
        }
        return temp;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int size=pow(2,nums.size());
        vector<vector<int>> ans;
        for(int i=0;i<size;++i){
            vector<int> temp=convertToBinary(i,nums.size());
            vector<int> ans1;
            for(int i=0;i<nums.size();++i){
                if(temp[i]!=0) ans1.push_back(nums[i]);
            } 
            ans.push_back(ans1);
        }
        return ans;
    }
};

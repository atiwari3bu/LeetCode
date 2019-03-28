class Solution {
public:
    int singleNumber(vector<int>& nums){
        map<int,int> mp;
        
        for(int number:nums){
            mp[number]++;
            if(mp[number]==3) mp.erase(number);
        }
        
        return mp.begin()->first;
    }
};

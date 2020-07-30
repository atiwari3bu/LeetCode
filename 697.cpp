class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,int>> mp;
        int max_count = 0;
        
        for(int i=0;i<nums.size();++i){
            int var = nums[i];
            
            if(mp.find(var)==mp.end()){
                mp[var] = make_pair(i,1);
            }
            else{
                mp[var].second++;
            }
            max_count = max(max_count,mp[var].second);
        }
        
        for(auto it = mp.begin();it!=mp.end();){
            if(it->second.second < max_count){
                it = mp.erase(it);
            }
            else ++it;
        }
        
        int min_arr_length = INT_MAX;
        
        for(int i=0;i<nums.size();++i){
            int var = nums[i];
            
            if(mp.find(var)!=mp.end()){
                mp[var].second--;
                
                if(mp[var].second == 0){
                    min_arr_length = min(min_arr_length,(i-mp[var].first) + 1);
                }
                
            }
        }  
        
        return min_arr_length;
    }
};

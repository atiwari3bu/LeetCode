class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        vector<vector<string>> ans;
        
        for(auto& my_string : strs){
            string original_string = my_string;
            sort(my_string.begin(),my_string.end());
            
            if(mp.find(my_string)==mp.end()) mp.insert(make_pair(my_string,vector<string>{original_string}));
            else mp[my_string].push_back(original_string);
        }
        
        for(auto& entry : mp){
            vector<string> temp;
            
            for(auto& map_keys : entry.second){
                temp.push_back(map_keys);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp;
        
        for(auto&c : magazine) mp[c]++;
        for(auto&c : ransomNote){
            if(mp.find(c)==mp.end()) return false;
            else{
                mp[c]--;
                if(mp[c]<0) return false;
            }
        }
        
        return true;
    }
};

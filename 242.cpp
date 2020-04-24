class Solution {
public:
    bool isAnagram(string s, string t) {
        // Since it is containing unicode characters and there size can be more than 1000
        // It is therefore preferable to use unordered_map instead of character array
        if(s.length()!=t.length()) return false; // since lengths of two string must be equal
        unordered_map<char,int> mp;
        
        for(char& ch : s) mp[ch]++;
        
        for(char& ch : t){
            if(mp.find(ch)!=mp.end() && mp[ch]>0) mp[ch]--;
            else return false;
        }
        
        return true;
    }
};

class Solution {
public:

		/* using stringstream to split and also for_each in algorithms library */
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> s(banned.begin(),banned.end());
        string temp;
        pair<string,int> max("",0);
        unordered_map<string,int> mp;
        
        for_each(paragraph.begin(),paragraph.end(),[](auto &c){ c=isalpha(c)?tolower(c):' ';});
        stringstream ss(paragraph);
        
        while(ss>>temp){
            if(s.find(temp)==s.end() && max.second<++mp[temp]) 
                max=make_pair(temp,mp[temp]);
        } 
        
        return max.first; 
    }
};

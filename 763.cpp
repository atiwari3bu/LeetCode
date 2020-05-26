class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int mp[26]={0};
        
        for(int i=0;i<S.length();++i){
            int index = S[i]-'a';
            mp[index] = i;
        }
        
        int window_start = 0;
        int window_end = 0;
        
        for(int i=0;i<S.length();++i){
            char ch = S[i];
            int char_index = mp[ch-'a'];
            
            window_end = max(window_end,char_index);
            
            if(window_end == i){ // reached the end of the window
                ans.push_back(window_end-window_start+1);
                window_start = window_end + 1;
            }
        }
        
        return ans;
        
    }
};

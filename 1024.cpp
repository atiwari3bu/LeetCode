class Solution {
    public:
    /* copied from https://leetcode.com/problems/video-stitching/discuss/269988/C%2B%2BJava-6-lines-O(n-log-n) */
    
    int videoStitching(vector<vector<int>>& clips, int T,int ans=0) {
        sort(clips.begin(),clips.end(),[](auto& a,auto& b){ return a[0]<b[0];});
        for(int i=0,st=0,end=0;st<T;++ans,st=end){
            for(;i<clips.size() && clips[i][0]<=st;++i){
                end=max(end,clips[i][1]);
            }
            if(st==end) return -1;
        } 
        return ans;
    }
};

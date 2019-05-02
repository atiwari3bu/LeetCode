class Solution {
    public:
    /* copied from https://leetcode.com/problems/video-stitching/discuss/269988/C%2B%2BJava-6-lines-O(n-log-n) */
    
    /* Dynamic Programming DP Dp dp*/

		/* https://leetcode.com/problems/video-stitching/discuss/270036/JavaC%2B%2BPython-Greedy-Solution-O(1)-Space */ 
    
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        vector<int> dp(101, 101);
        dp[0] = 0;
        for (auto& c : clips)
            for (int i = c[0] + 1; i <= c[1]; i++)
                dp[i] = min(dp[i], dp[c[0]] + 1);
        return dp[T] >= 100 ? -1 : dp[T];
    } 
    /*
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
    */
};

class Solution {
public:
    struct compare{
        template<typename T>
        bool operator()(T& a,T& b){
            return a[0]==b[0]? a[1]<b[1] : a[0]<b[0];
        }
    };
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare());
        
        for(int i=0;i+1<intervals.size();++i){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i+1][0]=intervals[i][0];
                if(intervals[i][1]>intervals[i+1][1]) intervals[i+1][1]=intervals[i][1];
                intervals.erase(intervals.begin()+i);
                --i;
            }
        }
        return intervals;
    }
};

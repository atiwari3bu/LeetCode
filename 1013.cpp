class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(61, 0);
        int pairs=0;
        for(int i=0;i<time.size();++i){
            int val=time[i]%60;
            int comp=60-val;
            if(comp==60) comp=0;
            if(v[comp]>=1) pairs+=v[comp];
            v[val]+=1;
        }
        return pairs;
    }
};

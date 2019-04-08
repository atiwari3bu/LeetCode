class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        for(N=(N-1)%14+1;N>0;--N){ //Cycle repeats
            vector<int> ans(cells.size());
            for(int i=0;i<cells.size();++i){
                if(i==0 || i==cells.size()-1) ans[i]=0; 
                else{
                    ans[i]=!((cells[i-1]&1) ^ (cells[i+1])&1);
                }
            }
            cells=ans;
        }
        return cells;
    }
};

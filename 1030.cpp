class Solution {
public:
    struct compareD{
        template<typename T>
        bool operator()(T&a, T&b){
            return a[2]>b[2];
        }
    };
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        priority_queue<vector<int>,vector<vector<int>>,compareD> pq;
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                int dist=abs(i-r0) + abs(j-c0);
                vector<int> temp{i,j,dist};
                pq.push(temp);
            }
        }
        
        while(!pq.empty()){
            auto val=pq.top();
            ans.push_back(vector<int>{val[0],val[1]});
            pq.pop();
        }
        return ans;
        
    }
};

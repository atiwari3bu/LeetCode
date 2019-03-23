class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row_size=grid.size();
        int col_size=grid[0].size();
        int res=0;
        int total=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<row_size;++i){
            for(int j=0;j<col_size;++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    ++total;
                }
            }
        }
        
        while(!q.empty()){
            int times=0;
            int s=q.size();
            
            while(s--){
                auto front=q.front();
                q.pop();
                int i=front.first;
                int j=front.second;
                if(i>0){
                    if(grid[i-1][j]==1){
                        --total;
                        grid[i-1][j]=2;
                        q.push({i-1,j});
                        times=1;
                    }
                }
                if(j>0){
                    if(grid[i][j-1]==1){
                        --total;
                        grid[i][j-1]=2;
                        q.push({i,j-1});
                        times=1;
                    }
                }
                if(i<row_size-1){
                    if(grid[i+1][j]==1){
                        --total;
                        grid[i+1][j]=2;
                        q.push({i+1,j});
                        times=1;
                    }
                }
                if(j<col_size-1){
                    if(grid[i][j+1]==1){
                        --total;
                        grid[i][j+1]=2;
                        q.push({i,j+1});
                        times=1;
                    }
                }
            }
            res+=times;
        }
        
        
        if(total == 0)
            return res;
        else return -1;
        
    }
};

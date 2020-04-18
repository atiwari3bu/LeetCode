class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int num_rows = grid.size(),num_cols;
        if(num_rows) num_cols = grid[0].size();
        
        for(int i=0;i<num_rows;++i){
            for(int j=0;j<num_cols;++j){
                
                if(grid[i][j]=='1'){
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    ++ans;
                    
                    while(!q.empty()){
                        
                        auto front = q.front();
                        int row = front.first;
                        int col = front.second;
                        
                        if(grid[row][col]=='0'){
                            q.pop();
                            continue;
                        }
                            
                        
                        grid[row][col]='0';
                        q.pop();
                        
                        if(row+1<num_rows && grid[row+1][col]=='1')
                            q.push(make_pair(row+1,col));

                        if(row-1>=0 && grid[row-1][col]=='1')
                            q.push(make_pair(row-1,col));

                        if(col+1<num_cols && grid[row][col+1]=='1')
                            q.push(make_pair(row,col+1));

                        if(col-1>=0 && grid[row][col-1]=='1')
                            q.push(make_pair(row,col-1));
                        
                    }
                }
            }
        }
        
        return ans;
    }
};

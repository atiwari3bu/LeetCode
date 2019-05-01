class Solution {
public:
    /*bfs Bfs BFS */
    /* Doing this for easy grep search */
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if(grid.size()==0) return {};
        
        queue<pair<int,int>> q;
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,0));
        vector<pair<int,int>> temp;
       
        q.push(make_pair(r0,c0));
        
        while(!q.empty()){
            auto elem = q.front();
            q.pop();
            int r = elem.first, c = elem.second;
            visited[r][c]=true;
            if(r == 0 || r== row-1 || c==0 || c==col-1) temp.push_back(elem);
            else if(r+1<row && grid[r+1][c]!=grid[r][c] || r-1>=0 && grid[r-1][c]!=grid[r][c] || c+1<col && grid[r][c+1]!=grid[r][c] || c-1>=0 && grid[r][c-1]!=grid[r][c]){
                temp.push_back(elem);
            }
            if(r+1<row && grid[r+1][c]==grid[r][c]  && !visited[r+1][c]) q.push(make_pair(r+1,c));
            if(r-1>=0 && grid[r-1][c] == grid[r][c] && !visited[r-1][c]) q.push(make_pair(r-1,c));
            if(c+1<col && grid[r][c+1] == grid[r][c]&& !visited[r][c+1]) q.push(make_pair(r,c+1));
            if(c-1>=0 && grid[r][c-1] == grid[r][c]&& !visited[r][c-1]) q.push(make_pair(r,c-1));
            
        }
        
        for(auto elem : temp){
            grid[elem.first][elem.second]=color;
        }
        return grid;
        
    }
};

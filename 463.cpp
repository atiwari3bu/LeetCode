class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total=0;
        
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==0){
                    if(i+1<grid.size() && grid[i+1][j]==1) ++total;
                    if(i-1>=0 && grid[i-1][j]==1) ++total;
                    if(j+1<grid[i].size() && grid[i][j+1]==1) ++total;
                    if(j-1>=0 && grid[i][j-1]==1) ++total;
                }
                else{
                    if(i==0) ++total;
                    if(i==grid.size()-1) ++total;
                    if(j==0) ++total;
                    if(j==grid[i].size()-1) ++total;
                }
            }
        }
           
        return total;
    }
};

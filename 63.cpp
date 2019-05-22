class Solution {
public:
    void print(vector<vector<int>>& mat){
        for(auto& row: mat){
            for(auto& col: row) cout<<col<<" ";
            cout<<endl;
        }
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<long int>> dp(row,vector<long int>(col,0));
        bool row_present=false, col_present=false;
        
        for(int i=0;i<col;++i){
            if(obstacleGrid[0][i]==1){
                dp[0][i]=0;
                col_present=true;
            }
            else if(col_present) dp[0][i]=0;
            else dp[0][i]=1;
        }
        
        for(int i=0;i<row;++i){
            if(obstacleGrid[i][0]==1){
                dp[i][0]=0;
                row_present=true;
            }
            else if(row_present) dp[i][0]=0;
            else dp[i][0]=1;
        }
        
        for(int i=1;i<row;++i){
            for(int j=1;j<col;++j){
                obstacleGrid[i][j]==1 ? dp[i][j]=0 : dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        //print(dp); 
        return dp[row-1][col-1];
    }
}

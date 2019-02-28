class Solution {
public:
    struct point{
        int row;
        int col;
        point(int x,int y){
            this->row=x;
            this->col=y;
        }
    };
    
    void setZeroes(vector<vector<int>>& matrix) {
        int row_size=matrix.size();
        int col_size=matrix[0].size();
        vector<point> points;
        
        for(int i=0;i<row_size;++i){
            for(int j=0;j<col_size;++j){
                if(matrix[i][j]==0){
                    points.push_back(point(i,j));    
                }
            }
        }
        
        for(auto& p : points){
            for(auto & elem : matrix[p.row]){
                elem=0;
            }
            for(int i=0;i<row_size;++i){
                matrix[i][p.col]=0;
            }
        
        }
        
    }
};

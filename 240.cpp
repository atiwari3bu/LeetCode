class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        
        int curr_row = 0, curr_col = num_cols-1; // staring from the top right 
        
        while(curr_row < num_rows && curr_col >=0){
            int curr_elem = matrix[curr_row][curr_col];
            
            if(target == curr_elem) return true;
            
            else if(curr_elem > target){
                --curr_col;
            }
            
            else ++curr_row;
        }
        return false;
        
    }
};

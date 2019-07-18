class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int row_length=matrix.size(),col_length=matrix[0].size();
        int start=0,end=row_length*col_length-1;

        while(start<=end){
            int mid=(start+end)/2;
            int val = matrix[mid/col_length][mid%col_length];
            
            if(target==val) return true;
            else if(target>val) start=mid+1;
            else end=mid-1;
            
        }
        
        return false;
    }
};

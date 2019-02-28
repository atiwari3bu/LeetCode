class Solution {
public: 
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int k=0;
        int times=1;
        while(k<n-1){
            for(int i=k,j=n-1;i<n-k-times;++i,--j){
                int temp1=matrix[k][i];
                int temp2=matrix[i][n-1];
                int temp3=matrix[n-1][j];
                int temp4=matrix[j][k];
                matrix[i][n-1]=temp1;
                matrix[n-1][j]=temp2;
                matrix[j][k]=temp3;
                matrix[k][i]=temp4;
            }
            --n;
            ++k;
            --times;
        }
        
    }
};

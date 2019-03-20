class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size()==0) return A;
        
        for(int i=0,j=A.size()-1;i<j;){
            if((A[i]%2==0) && (A[j]%2==1)){
                ++i;
                --j;
            }
            else if((A[i]%2 ==1) && (A[j]%2==0)){
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
            else if((A[i]%2 ==1) && (A[j]%2==1)){
                --j;
            }
            else{
                ++i;
            }
        }
        
        return A;
    }
};

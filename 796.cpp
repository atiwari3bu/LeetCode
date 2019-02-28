class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length()!=B.length()) return false;
        if(A.length()==0) return true;
        
        for(int i=0;i<B.length();++i){
            if(B[i]==A[0]){
                bool is_valid=true;
                for(int j=0,k=i;j<A.length();++j,++k){
                    if(k==B.length()) k=0;
                    if(A[j]!=B[k]) is_valid=false;
                }
                if(is_valid==true) return true;
            }
        }
        
        return false;
    }
};

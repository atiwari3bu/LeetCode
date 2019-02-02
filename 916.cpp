class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int size=A.size();
        int matrix[size][26];
        
        for(int i=0;i<size;++i){
            for(int j=0;j<26;++j){
                matrix[i][j]=0;
            }
        }
        
        for(int i=0;i<size;++i){
            for(int j=0;j<(A[i].length());++j){
                int index=A[i][j]-'a';
                ++matrix[i][index];
            }
        }
        
        int word[26];
        for(int i=0;i<26;++i){
            word[i]=0;
        }
        for(int i=0;i<B.size();++i){
            int temp[26];
            for(int k=0;k<26;++k){
                temp[k]=0;
            }
            for(int j=0;j<B[i].length();++j){
                int index=B[i][j]-'a';
                ++temp[index];
                if(temp[index]>word[index]) word[index]=temp[index];
            }
        }
        
        vector<string> temp;
        for(int i=0;i<A.size();++i){
            bool is_substring=false;
            for(int j=0;j<26;++j){
                if(matrix[i][j]<word[j]){
                    is_substring=true;
                    break;
                }
            }
            if(is_substring==false) temp.push_back(A[i]);
        }
        
        return temp;
    }
};

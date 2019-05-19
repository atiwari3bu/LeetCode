    void print(vector<vector<bool>>& mat){
        cout<<"----------------"<<endl;
        for(auto row:mat){
            for(auto col:row) cout<<col<<" ";
            cout<<endl;
        }
        cout<<"----------------"<<endl;
    }
    
    string longestPalindrome(string s) {
        vector<vector<bool>> matrix(s.length(),vector<bool>(s.length(),false));
        int n=s.length();
        
        for(int i=0;i<s.length();++i){
            matrix[i][i]=true;  // For odd length palindrome
            if (i==0) continue;
            matrix[i-1][i]=s[i]==s[i-1];  // For even length palindrome
        }
        
        
        for(int j=2;j<n;++j){
            for(int i=0;i<n-j;++i){
                if(matrix[i+1][i+j-1]==1 && s[i]==s[i+j]){
                    matrix[i][i+j]=true;
                }
            }
        }
        
        
        int max=0;
        string max_str="";
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==1 && max<j-i+1){
                    max=j-i+1;
                    max_str=s.substr(i,j-i+1);
                }
            }
        } 
        
        return max_str;
    }
};

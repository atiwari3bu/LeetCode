class Solution {
  
  public:
    enum status{ r,d,l,u,nogo};

    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> mat;
      status stat;

      for(int i=0;i<n;++i){
        vector<int> temp;
        for(int j=0;j<n;++j){
          temp.push_back(-1);
        }
        mat.push_back(temp);
      }

      int cr=0,cc=0;

      if(n>0) stat=r;

      for(int i=1;i<=pow(n,2);++i){
        if(stat==r){
          if(cc>=n || mat[cr][cc]!=-1){
            stat=d;
            ++cr;
            --cc;
            --i;
            continue;
          }
          mat[cr][cc]=i;
          ++cc;
        }

        else if(stat==d){
          if(cr>=n || mat[cr][cc]!=-1) {
            stat=l;
            --cc;
            --cr;
            --i;
            continue;
          }
          mat[cr][cc]=i;
          ++cr;
        }

        else if(stat==l){
          if(cc<0 || mat[cr][cc]!=-1){
            stat=u;
            --cr;
            ++cc;
            --i;
            continue;
          }
          mat[cr][cc]=i;
          --cc;
        }

        else{
          if(mat[cr][cc]!=-1 || cr<0){
            stat=r;
            ++cc;
            ++cr;
            --i;
            continue;
          }
          mat[cr][cc]=i;
          --cr;
        }

      }
      return mat;
    }
};

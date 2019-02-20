class Solution {
	public:
		enum status{r,d,l,u};

		void negate(vector<vector<bool>>& v, int n, int m){
			for(int i=0;i<n;++i){
				vector<bool> temp;
				for(int j=0;j<m;++j){
					temp.push_back(false);
				}
				v.push_back(temp);
			}
		}

		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> ans;
			enum status stat=r;
			int n=matrix.size();
			if(n==0) return ans;
			int m=matrix[0].size();

			vector<vector<bool>> available;
			negate(available,n,m);

			int cr=0,cc=0;
			for(int i=0;i<(n*m);++i){
				if(stat==r){
					if(cc>=m || available[cr][cc]==true){
						stat=d;
						--cc;
						++cr;
						--i;
						continue;
					}
					available[cr][cc]=true;
					ans.push_back(matrix[cr][cc]);
					++cc;
				}

				else if(stat==d){
					if(cr>=n || available[cr][cc]==true){
						stat=l;
						--cr;
						--cc;
						--i;
						continue;
					}
					ans.push_back(matrix[cr][cc]);
					available[cr][cc]=true;
					++cr;
				}

				else if(stat==l){
					if(cc<0 || available[cr][cc]==true){
						stat=u;
						++cc;
						--cr;
						--i;
						continue;
					}
					ans.push_back(matrix[cr][cc]);
					available[cr][cc]=true;
					--cc;
				}

				else{
					if(cc<0 || available[cr][cc]==true){
						stat=r;
						++cr;
						++cc;
						--i;
						continue;
					}
					ans.push_back(matrix[cr][cc]);
					available[cr][cc]=true;
					--cr;
				}
			}
			return ans;
		}
};

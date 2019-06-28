class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			unordered_set<char> c[9];
			unordered_set<char> block[3][3];

			for(int i=0;i<9;++i){
				unordered_set<char> r;

				for(int j=0;j<9;++j){
					char ch = board[i][j];
					int row=i/3,col=j/3;
					if(ch =='.') continue;

					if(r.find(ch)==r.end()){
						r.insert(ch);
					}
					else return false;

					if(c[j].find(ch)==c[j].end()){
						c[j].insert(ch);
					}
					else return false;

					if(block[row][col].find(ch)==block[row][col].end()){
						block[row][col].insert(ch);
					}
					else return false;

				}

			}

			return true;

		}
};

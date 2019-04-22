class Solution {
	public:
		int longestArithSeqLength(vector<int>& A) {
			if(A.size()==0) return 0;
			if(A.size()==1) return 1;

			unordered_map<int,unordered_map<int,int>> um;
			int res=2;

			for(int i=0;i<A.size();++i){
				for(int j=i+1;j<A.size();++j){
					int diff= A[j]-A[i];
					if(um[diff].find(i)==um[diff].end()){
						um[diff][j]=2;
					}
					else{
						um[diff][j]=1+um[diff][i];
					}
					if(res< um[diff][j]) res = um[diff][j];
				}
			}

			return res;
		}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
				return !isspace(ch);
				}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
				return !isspace(ch);
				}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> A = stringToIntegerVector(line);

		int ret = Solution().longestArithSeqLength(A);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

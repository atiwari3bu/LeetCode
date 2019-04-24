class Solution {
    public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> B(A.size());
        B[A.size()-1]=A[A.size()-1];

        for(int i=A.size()-1;i>=1;--i){
            B[i-1]=A[i-1]<B[i]?A[i-1]:B[i]; 
        }

        int max=0;
        for(int i=1;i<A.size();++i){
            if(max<A[i-1]) max=A[i-1];
            if(max<=B[i]) return i;
        }
        return max;

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
        
        int ret = Solution().partitionDisjoint(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

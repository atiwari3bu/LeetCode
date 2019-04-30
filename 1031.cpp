class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        
        for(int i=1;i<A.size();++i) A[i]+=A[i-1];
        int l_max = A[L-1];
        int m_max = A[M-1];
        int ans = A[L+M-1];
        
        for(int i=L+M;i<A.size();++i){
            l_max = max(l_max , A[i-M]-A[i-L-M]);
            m_max = max(m_max, A[i-L]- A[i-L-M]);
            int temp_max = max(l_max+A[i]-A[i-M], m_max+A[i]-A[i-L]);
            ans = max(ans,temp_max);
        }
        
        return ans;
        
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int L = stringToInteger(line);
        getline(cin, line);
        int M = stringToInteger(line);
        
        int ret = Solution().maxSumTwoNoOverlap(A, L, M);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

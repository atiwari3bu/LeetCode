class Solution {
public:
    int hIndex(vector<int>& citations) {
        /*https://leetcode.com/problems/h-index/discuss/70894/O(n)-time-C%2B%2B-solution-using-hash-table */
        int n = citations.size();
        
        if(n==0) return 0;
        vector<int> ans(n+1,0);
        
        for(int i=0;i<n;++i){
            if(citations[i]>=n) ans[n]++;
            else ans[citations[i]]++;
        }
        
        int count = 0;
        for(int i=n;i>=0;--i){
            count+=ans[i];
            if(count>=i) return i;
        }
        return 0;
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
        vector<int> citations = stringToIntegerVector(line);
        
        int ret = Solution().hIndex(citations);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

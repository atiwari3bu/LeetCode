class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff=0;
        for(auto iter=prices.begin();iter!=prices.end();++iter){
            for(auto iter1=iter;iter1!=prices.end();++iter1){
                //std::cout<<"Iter is "<<*iter<<" and iter1 is "<<*iter1<<std::endl;
                if(diff<(*iter1-*iter)) diff=*iter1-*iter;
            }
        }
        //std::cout<<"Difference is "<<diff<<std::endl;
        return diff;
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
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

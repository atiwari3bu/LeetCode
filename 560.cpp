class Solution {
public:
    /* Brute Force Solution  O(n^2) time and O(1) space*/
    
    /*
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();++i){
            int sum=nums[i];
            if(sum==k) ++count;
            for(int j=i+1;j<nums.size();++j){
                sum+=nums[j];
                if(sum==k) ++count;
            }
        }
        
        return count;
    }
    */
    /* O(n) time and O(n) space using map */
    
    int subarraySum(vector<int>& num,int k){
        unordered_map<int,int> mp;
        mp[0]++;
        int count=0;
        int sum=0;
        
        for(int i=0;i<num.size();++i){
            sum+=num[i];
            count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().subarraySum(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

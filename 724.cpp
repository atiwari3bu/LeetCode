class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0) return -1; // Edge case when nums size is 0
        int n=nums.size(); 
       
        for(int i=0;i+1<n;++i){ // Calculating presum for the loop
            nums[i+1]=nums[i+1]+nums[i];
        }
        
        if(nums[0]==nums[n-1]) return 0;  // Edge case 
        for(int i=1;i+1<n;++i){
            if(nums[i-1]==nums[n-1]-nums[i]) return i;
        }  
        if(n-2>=0 && nums[n-2]==0) return n-1; // Edge case
        return -1;
        
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().pivotIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

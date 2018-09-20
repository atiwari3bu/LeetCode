class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int i=0;
        int j=0;
        for(auto iter=nums.begin();iter!=nums.end();++iter){
            j=i+1;
            for(auto iter1=iter+1;iter1!=nums.end();++iter1){
                if((*iter)+(*iter1)==target){
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
                ++j;
            }
            ++i;
        }
        return v;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

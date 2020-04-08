class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> st(arr.begin(),arr.end());
        int count = 0;

        for(auto& num : arr){
            if(st.find(num+1)!=st.end()) ++count;
        }
        
        return count;
    }
};

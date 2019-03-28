class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> st;
        for (auto& number : nums){
            if(st.find(number)==st.end()){
                st.insert(number);
            }
            else{
                st.erase(number);
            }
        }
        return *st.begin();

				/* Using EXor logic i.e, if it is same then it becomes zero 
				* or else it becomes one */

				int res=0;
				for(int num:nums){
					res ^=num;
				}
				return res;
    }
};

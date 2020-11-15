class Solution {
    public:
    string removeDuplicates(string s, int k) {
        string ans;
        
        stack<pair<char,int>> st;
        for(auto& ch : s){
            if(st.empty()){
                st.push(make_pair(ch,1));
            }
            
            else{
                auto first_elem = st.top();
                char  first_ch = first_elem.first;
                int count = first_elem.second;

                if(first_ch == ch && (count+1) == k){
                    while(count--) st.pop();
                }
                else if(first_ch == ch){
                    st.push(make_pair(ch,++count));
                }
                else{
                    st.push(make_pair(ch,1));
                }
            }
        }
        
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }`
        return string(ans.rbegin(),ans.rend());

    }
};

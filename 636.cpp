class Solution {
public:
    struct log{
        int start;
        string func;
        int end;
    };
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<log> st;
        for(auto elem: logs){
            string temp1,temp2,temp3;
            stringstream entry(elem);
            getline(entry,temp1,':');
            getline(entry,temp2,':');
            getline(entry,temp3);
            
            log item {stoi(temp1),temp2,stoi(temp3)};
            if(item.func == "end"){
                int time=item.end - st.top().end + 1;
                ans[item.start]+=time;
                st.pop();
                if(!st.empty()){
                    ans[st.top().start]-=time;
                }
            }
            else{
                st.push(item);
                
            }
        }
        return ans;
    }

};

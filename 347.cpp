class Solution {
public:
    struct compare{
        template<typename T>
        bool operator()(T& elem1,T& elem2){
            return elem1.second>elem2.second;      
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int& val : nums) mp[val]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        
        for(auto& elem : mp){
            if(pq.size()<k){
                pq.push({elem.first,elem.second});
            }
            
            else{
                auto top_elem = pq.top();
                if(elem.second > top_elem.second){
                    pq.pop();
                    pq.push({elem.first,elem.second});
                }
            }
        }
        
        while(!pq.empty()){
            auto& top_elem = pq.top();
            ans.push_back(top_elem.first);
            pq.pop();
        }
        
        return ans;
    }
};

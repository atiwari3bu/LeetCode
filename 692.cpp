class Solution {
public:
   /* Priority Queue pq priority queue */ 
    
   struct compare{
       bool operator()(auto& a,auto& b){
            return a.second==b.second ? a.first<b.first : a.second>b.second;
       }
   };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> count;
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> pq;
        
        for(auto& word: words){
            count[word]++;
        }
        
        for(auto& elem : count){
            pq.emplace(make_pair(elem.first,elem.second));
            if(pq.size()> k) pq.pop();
        }

        vector<string>ans;
        while(!pq.empty()){
            ans.emplace_back(pq.top().first);
            pq.pop();
        }
          
        return vector<string>(ans.rbegin(),ans.rend()); 
    }
};

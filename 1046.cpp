class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        
        while(pq.size()>=1){
            int first_elem = pq.top();
            pq.pop();
            
            if(pq.empty()) return first_elem;
            int second_elem = pq.top();
            pq.pop();

            int rem = first_elem - second_elem;
            if(rem) pq.push(rem);
        }
        return pq.size()? pq.top() : 0;
    }
};

class Solution { 
public:
    struct Point{
        int x;
        int y;
        int dist;
        
        Point(int x,int y){
            this->x=x;
            this->y=y;
            this->dist = pow(x,2)+pow(y,2);
        }
    };
    
    struct compare{
        bool operator()(Point a,Point b){
            return a.dist<b.dist;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point,vector<Point>,compare> pq;
        
        for(int i=0;i<points.size();++i){
            Point temp = Point(points[i][0],points[i][1]);
            if(pq.size()<K){
                pq.push(temp);
            }
            else{
                Point tp = pq.top();
                if(tp.dist>temp.dist){
                    pq.pop();
                    pq.push(temp);
                }
            }
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty()){
            Point temp = pq.top();
            ans.push_back(vector<int>{temp.x,temp.y});
            pq.pop();
        }
        
        return ans;
        
    }
};

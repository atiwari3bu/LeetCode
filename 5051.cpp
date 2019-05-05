class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        set<pair<int,int>> s;
        for(int i=0;i<points.size();++i){
            auto temp=pair<int,int>(points[i][0],points[i][1]);
            if(s.find(temp)!=s.end()) return false;
            else s.insert(make_pair(points[i][0],points[i][1]));
        }
        
        float m1=INT_MAX,m2=INT_MAX;
        if(points[1][0] - points[0][0]!= 0) {
            m1=(points[1][1]-points[0][1]+0.0)/(points[1][0]-points[0][0]+0.0);
        }
        if(points[2][0] - points[1][0]!= 0) {
            m2=(points[2][1]-points[1][1]+0.0)/(points[2][0]-points[1][0]+0.0);
        }
       
        if(m1==m2) return false;
        return true;  
        
    }
};

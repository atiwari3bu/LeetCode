class Solution {
public:
    typedef vector<vector<int>> graph;
    
    enum state{VISITING,VISITED,UNTOUCHED};
    
    graph buildGraph(int numCourses,vector<pair<int,int>>& prerequisites){
        graph g(numCourses);
        for(auto& elem : prerequisites){
            g[elem.first].push_back(elem.second);
        }
        return g;
    }
    
    bool dfsVisit(vector<int>& ans,vector<state>& states,graph& g,int i){
        if(states[i]==VISITING){ // cycle detected
            return false;
        }
        if(states[i]==VISITED){  // Not going through that again
            return true;
        }
        
        states[i]=VISITING;
        for(int j=0;j<g[i].size();++j){
            if(!dfsVisit(ans,states,g,g[i][j])){
                return false;
            }
        }
        states[i]=VISITED;
        ans.push_back(i);
        
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        graph g = buildGraph(numCourses,prerequisites);
        vector<state> states(numCourses,UNTOUCHED);
        
        for(int i=0;i<numCourses;++i){
            if(states[i]==UNTOUCHED && !dfsVisit(ans,states,g,i)){
                ans.clear();
                return ans; 
            }
        }
        return ans; 
    }
};


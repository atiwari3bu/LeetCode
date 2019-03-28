class Solution {
public:
    enum state{COMPLETED,PARTIAL,BLANK};
    
    bool dfsVisit(vector<vector<int>>& graph,vector<state>& states,int i){
        if(states[i]==PARTIAL) return false;
        
        states[i]=PARTIAL;
        
        for(int v : graph[i]){
            if(!dfsVisit(graph,states,v)){
                return false;
            }
        }
        
        states[i]=COMPLETED;
        return true;
    }
    
    vector<vector<int>> buildGraph(int numCourses, vector<pair<int,int>> & prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto p:prerequisites){
            graph[p.second].push_back(p.first);
        }
        return graph;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph=buildGraph(numCourses,prerequisites);
        vector<state> states(numCourses,BLANK);
        
        for(int i=0;i<numCourses;++i){
            if(states[i]==BLANK){
                if(!dfsVisit(graph,states,i)){
                    return false;
                }
            }
        }
        return true;
    }
};

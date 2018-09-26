class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==(size_t)0) return "";
        auto iter=strs.begin();
        string first=*iter;
        string temp;
        int j;
        
        for(int i=0;i!=first.length();++i){
            for(auto iter=strs.begin()+1;iter!=strs.end();++iter){
                string str=*iter;
                if(first[i]==str[i]) {
                    ++j; 
                }
            }
            
            if(j==((int)(strs.end()-strs.begin()-1))){
                temp.push_back(first[i]);
                j=0;
            }   
            else break;
        }
        //cout<<temp<<endl;
        return temp;
    }
};

int main(){
  return 0;
}

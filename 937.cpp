class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>> letter_logs;
        vector<string> digit_logs;
        vector<string> ans;
        
        for(string& str : logs){
            string identifier;
            
            int i=0;
            
            while(i<str.length()){
                if(str[i]==' ') break;    
                identifier += str[i];
                ++i;
            }
            
            bool isWord = false;
            string rest_of_word;
            
            ++i; // to go ahead of the space character
            
            while(i<str.length()){
                if(islower(str[i])){
                    isWord = true;
                }
                rest_of_word +=str[i];
                ++i;
            }
            
            if(isWord){
                letter_logs.push_back({identifier,rest_of_word});
            }
            else digit_logs.push_back(str);
        }
        
        auto compare = [](auto& elem1,auto& elem2){
            return (elem1.second == elem2.second) ? elem1.first<elem2.first : elem1.second < elem2.second;
                
        };
        
        sort(letter_logs.begin(),letter_logs.end(),compare);
        
        for(auto& elem : letter_logs){ 
            elem.first+=' ';
            elem.first.append(elem.second);
            ans.push_back(elem.first);
        }
        
        for(auto& elem : digit_logs) {
            ans.push_back(elem);
        }
        
        return ans;
    }
};

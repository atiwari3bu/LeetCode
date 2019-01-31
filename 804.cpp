class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morsecode={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> alphabets;
        for(int i=0;i<26;++i){
            //std::cout<<(char)(97+i)<<std::endl;
            char temp=(char)(97+i);
            string temp1;
            temp1.push_back(temp);
            alphabets.push_back(temp1);
        }
        map<string,string> dict;
        
        for(auto iter=alphabets.begin(),iter1=morsecode.begin();iter!=alphabets.begin(),iter1!=morsecode.end();++iter,++iter1){
            //std::cout<<*iter<<" - "<<*iter1<<std::endl;
            dict.insert(pair<string,string>(*iter,*iter1));
        }
        
        vector<string> wordings;
        for(auto iter=words.begin();iter!=words.end();++iter){
            string s=*iter;
            string morse_code;
            for(int i=0;i<s.length();++i){
                string temp;
                temp.push_back(s[i]);
                //std::cout<<dict.find(temp)->second<<std::endl;
                morse_code+=(dict.find(temp)->second);
            }
            //std::cout<<morse_code<<std::endl;
            wordings.push_back(morse_code);
        }
        
        vector<string> unique_wordings;
        for(auto iter=wordings.begin();iter!=wordings.end();++iter){
            bool to_insert=true;
            for(auto iter1=unique_wordings.begin();iter1!=unique_wordings.end();++iter1){
                if(*iter==*iter1){
                    to_insert=false;
                    break;
                }
            }
            if(to_insert==true) unique_wordings.push_back(*iter);
        }
        
        if(words.size()==0) return 0;
        else return unique_wordings.size();
    }
};

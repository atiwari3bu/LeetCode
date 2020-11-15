class Solution {
public:
   string decodeString(int& curr,string s){
       int mult = 0;
       string word="";
       
       for(;curr<s.length();++curr){
           char ch = s[curr];
           
           if(ch == '['){
               string str = decodeString(++curr,s);
               for(;mult>0;--mult) word += str;
           }
           else if(isdigit(ch)){
               mult = mult*10 + (s[curr]-'0');
           }
           else if(ch ==']'){
               return word;
           }
           else{
               word += ch;
           }
       }
       
       return word;
       
   } 
    
    string decodeString(string s) {
        int curr = 0;
        return decodeString(curr,s);
    }
};

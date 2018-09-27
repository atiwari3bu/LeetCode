class Solution {
public:
    int sum=0;
    
    void calSum(string s,map<char,int> hash_map){
        for(int i=0;i!=s.length();++i){
            if((hash_map[s[i+1]]>hash_map[s[i]]) && (i+1!=s.length())){
                sum=sum+hash_map[s[i+1]]-hash_map[s[i]];
                ++i;
            }
            else{
                sum=sum+hash_map[s[i]];
            }
        }
    }
    
    int romanToInt(string s) {
        map<char,int> hash_map;
        hash_map.insert(pair<char,int>('I',1));
        hash_map.insert(pair<char,int>('V',5));
        hash_map.insert(pair<char,int>('X',10));
        hash_map.insert(pair<char,int>('L',50));
        hash_map.insert(pair<char,int>('C',100));
        hash_map.insert(pair<char,int>('D',500));
        hash_map.insert(pair<char,int>('M',1000));
        /*  For printing the hash map
        for(auto iter=hash_map.begin();iter!=hash_map.end();++iter){
            cout<<iter->first<<iter->second<<endl;
        }
        */
        
        calSum(s,hash_map);
        return sum;   
    }  
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}


int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

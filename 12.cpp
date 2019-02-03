class Solution {
public:
    string intToRoman(int num) {
        std::map<int,string> hash_map;
        hash_map.insert(pair<int,string>(1,"I"));
        hash_map.insert(pair<int,string>(4,"IV"));
        hash_map.insert(pair<int,string>(5,"V"));
        hash_map.insert(pair<int,string>(9,"IX"));
        hash_map.insert(pair<int,string>(10,"X"));
        hash_map.insert(pair<int,string>(40,"XL"));
        hash_map.insert(pair<int,string>(50,"L"));
        hash_map.insert(pair<int,string>(90,"XC"));
        hash_map.insert(pair<int,string>(100,"C"));
        hash_map.insert(pair<int,string>(400,"CD"));
        hash_map.insert(pair<int,string>(500,"D"));
        hash_map.insert(pair<int,string>(900,"CM"));
        hash_map.insert(pair<int,string>(1000,"M"));
        string s;
        
        auto iter=hash_map.rbegin();
        while(num>0){
            if(iter->first<=num){
                num-=iter->first;
                s+=iter->second;
            }
            else ++iter;
        }
        
        return s;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        num=44;
        
        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1};
        
        vector<int> ans = {1,1};
        vector<int> temp = {1,1};
        for(int i=2;i<=rowIndex;++i){
            for(int j=0;j+1<ans.size();++j){
                temp.insert(temp.begin()+j+1,ans[j]+ans[j+1]);
            } 
            ans=temp;
            temp={1,1};
        }
        
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int rowIndex = stringToInteger(line);
        
        vector<int> ret = Solution().getRow(rowIndex);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

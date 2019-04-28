class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> temp{a,b,c};
        sort(temp.begin(),temp.end());
        if(temp[1]-temp[0] ==1 && temp[2]-temp[1]==1) return vector<int>{0,0};
        int min =0 ,max =0 ;
        if(temp[1]-temp[0]<=2 || temp [2]-temp[1] <=2){
            min = 1;
        }
        else{
            min=2;
        }
        max =temp[2]-temp[0]-2;
        
        return vector<int>{min,max};
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
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        getline(cin, line);
        int c = stringToInteger(line);
        
        vector<int> ret = Solution().numMovesStones(a, b, c);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

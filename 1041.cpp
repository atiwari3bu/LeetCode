class Solution {
public:
    
    /* https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain */
    /* Directions directions */
    bool isRobotBounded(string instructions) {
        int x=0,y=0,i=1;
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        
        for(auto& ins : instructions){
            if(ins=='L') i=(i+1)%4;
            else if(ins=='R') i=(i+3)%4;
            else{
                x+=dir[i][0];
                y+=dir[i][1];
            }
        }
        
        return ((x==0 && y==0) || i!=1)? true : false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string instructions = stringToString(line);
        
        bool ret = Solution().isRobotBounded(instructions);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

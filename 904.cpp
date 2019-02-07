class Solution {
public:
    void printArray(int* arr,int start,int end){
        std::cout<<"----------------------"<<std::endl;
        std::cout<<"Start = "<<start<<", End = "<<end<<std::endl;
        std::cout<<"First = "<<arr[0]<<", Second = "<<arr[1]<<std::endl;
        std::cout<<"----------------------"<<std::endl;
    }
    
    bool inArray(int* arr,int val){
        if(arr[0]==val) return true;
        if(arr[1]==val) return true;
        return false;
    }
    
    void isMax(int& end,int& start,int& max){
        if((end-start)>max) max=end-start;
    }
    
    int totalFruit(vector<int>& tree) {
        int start=0;
        int end=0;
        int arr[2]={-1,-1};
        int max=0;
        for(int i=0;i<tree.size();++i){
            if(arr[0]==-1){ 
                arr[0]=tree[i];
                ++end;
                isMax(end,start,max);
            }
            else if(arr[1]==-1 && tree[i]!=arr[0]){
                arr[1]=tree[i];
                ++end;
                isMax(end,start,max);
            }
            else{
                bool isSame=inArray(arr,tree[i]);
                if(isSame==true){
                    ++end;
                    isMax(end,start,max);
                }
                else{
                    start=end-1;
                    while(tree[start-1]==tree[start]){
                        --start;
                    }
                    arr[0]=tree[start];
                    arr[1]=tree[end];
                    ++end;
                    isMax(end,start,max);
                }
            }
            printArray(arr,start,end);
        }
        return max;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> tree = stringToIntegerVector(line);
        tree={0,1,6,6,4,4,6};
        int ret = Solution().totalFruit(tree);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

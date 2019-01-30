
class Solution {  // This pattern is basically fibonacci series
public:
    int climbStairs(int n) 
    { 
    n=n+1;
    /* Declare an array to store Fibonacci numbers. */
    int f[n+2];   // 1 extra to handle case, n = 0 
    int i; 
  
     /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0; 
    f[1] = 1; 
  
    for (i = 2; i <= n; i++) 
        { 
      /* Add the previous 2 numbers in the series 
         and store it */
            f[i] = f[i-1] + f[i-2]; 
        } 
  
    return f[n]; 
    } 
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

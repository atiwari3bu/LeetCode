class Solution {
    public:
        /* Cycle detection using O(1) space */

        int digitSquareSum(int n) {
            int sum = 0, tmp;
            while (n) {
                tmp = n % 10;
                sum += tmp * tmp;
                n /= 10;
            }
            return sum;
        }

        bool isHappy(int n) {
            int slow, fast;
            slow = fast = n;
            do {
                slow = digitSquareSum(slow);
                fast = digitSquareSum(fast);
                fast = digitSquareSum(fast);
                if(fast == 1) return 1;
            } while(slow != fast);
            return 0;
        }


        /* My solution uses O(n) space */
        bool isHappy(int n) {

            unordered_set<int> st;
            int sum = 0;

            while(1){

                while(n!=0){
                    int last_digit = n % 10;
                    n = n / 10;
                    sum += (last_digit * last_digit);
                }

                if(sum == 1) return true;
                else if(st.find(sum)!=st.end()) return false;
                else{
                    st.insert(sum);
                    n = sum;
                    sum = 0;
                }
            }

            return false;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

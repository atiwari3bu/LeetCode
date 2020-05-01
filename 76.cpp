class Solution {
    public:
    /* O(n) time complexity and O(m) space complexity 
       n : length of the s string
       m : length of the t string
    */

    string minWindow(string s, string t) {
        unordered_map<char,int> pattern;
        for(char& ch : t) pattern[ch]++;

        int start = 0, end = 0;
        int count = t.length();
        int max_len = s.length()+1;
        string ans;

        while(end<s.length()){

            /* Expanding the end pointer*/
            char end_char = s[end];
            if(pattern.find(end_char)!=pattern.end() && --pattern[end_char]>=0){
                --count;
            }
            ++end; 

            /* The end would have substring + 1 */
            while(count==0){ // All the elements are found now time to move the start pointer
                
                /* The procedure of updating the ans */
                int new_length = end - start;
                if(new_length < max_len){
                    max_len= new_length;
                    ans = string(s.begin()+start,s.begin()+end);
                }

                /*Expanding the start pointer */
                char start_char = s[start];
                if(pattern.find(start_char)!=pattern.end() && ++pattern[start_char]>0){
                    ++count;
                }
                ++start;
            } 

        }

        return ans;
    }

    /* O(n^2) time complexity and O(n*m) space complexity 
       n : length of the s string
       m : length of the t string

    string minWindow(string s, string t) {
        int min_len = s.length()+1;
        string ans;

        unordered_map<char,int> pattern;
        for(char& ch : t) pattern[ch]++;

        for(int i=0;i<s.length();++i){
            unordered_map<char,int> pattern_copy = pattern;
            int j = i;

            while(j<s.length()){
                if(pattern_copy.empty()) {
                    break;
                }

                if(pattern_copy.find(s[j])!=pattern_copy.end()){
                    pattern_copy[s[j]]--;
                    if(pattern_copy[s[j]]==0) pattern_copy.erase(s[j]);
                }
                ++j;
            }

            int new_len = j-i;

            if(min_len> new_len && pattern_copy.empty()){
                ans = string(s.begin()+i,s.begin()+j);
                min_len = new_len;
            }
        }

        return ans;
    }
    */
};

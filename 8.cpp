class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        int index = str.find_first_not_of(' ');
        if(index >= str.length()) return 0;
        
        int isPositive = 1;
        if(str[index] == '-'){
            isPositive = -1;
            ++index;
        }
        else if(str[index] == '+'){
            isPositive = 1;
            ++index;
        }
        
        if(str[index]>'9' || str[index]<'0') return 0;
        
        while(index<str.length()){
            if(str[index] >= '0' && str[index] <='9'){
                ans = ans* 10 + (str[index] - '0');
                
                if(ans*isPositive >= INT_MAX) return INT_MAX;
                else if(ans*isPositive <= INT_MIN) return INT_MIN;
                
            }
            else break;
            
            ++index;
        }
            
        return isPositive*ans;
    }
};

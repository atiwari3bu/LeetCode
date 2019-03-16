class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size()+num2.size(),'0');
        if(num1=="0" || num2=="0") return "0";
        
        for(int i=num1.size()-1;i>=0;--i){
            int carry=0;
            for(int j=num2.size()-1;j>=0;--j){
                int val=(num1[i]-'0') * (num2[j]-'0');
                int temp=ans[i+j+1] - '0' + val + carry;
                
                ans[i+j+1]=temp%10 + '0';
                carry = temp/10;
            }
            
            ans[i]+=carry;
        }
        
        for(int i=0;i<ans.size();){
            if(ans[i]=='0'){
                ans.erase(ans.begin()+i);
            }
            else break;
        }
        return ans;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string temp;
        if(b.length()>a.length()){
            temp=a;
            a=b;
            b=temp;
        }
        //cout<<"a = "<<a<<" b = "<<b<<endl;
        string total;
        int carry=0;
        for(int i=a.length()-1,j=b.length()-1;i>=0;--i,--j){ 
            //cout<<"i = "<<i<<"j = "<<j<<endl;
            if(j<0){
                j=0;
                b[j]='0';
            }
            int sum1=(a[i]-'0')+carry;
            if(sum1==2){ 
                carry=1; 
                sum1=0;
            }
            else carry=0;
            //cout<<"sum1= "<<sum1<<endl;
            int sum2=sum1+(b[j]-'0');
            if(sum2==2){ 
                carry=1; 
                sum2=0;
            }
            //cout<<"sum2= "<<sum2<<endl;
            string c=to_string(sum2);
            total.insert(0,c);
        }
        if(carry==1) total.insert(0,"1");
        //cout<<"Total = "<<total<<endl;
        return total;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line)
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}

class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        map<int,char> mp;
        string ans;
        for(int i=0;i<=9;++i) mp.insert(pair<char,int>(i,i+'0'));
        mp.insert(pair<char,int>(10,'a'));
        mp.insert(pair<char,int>(11,'b'));
        mp.insert(pair<char,int>(12,'c'));
        mp.insert(pair<char,int>(13,'d'));
        mp.insert(pair<char,int>(14,'e'));
        mp.insert(pair<char,int>(15,'f'));
        
        long n=num;
        if(num<0){
            n+=2147483648;
            n|=1UL << 31;
        }
        while(n!=0){
            int div=n%16;
            ans.insert(ans.begin(),mp[div]);
            n=n/16;
        }
        
        return ans;                                    
    }
};

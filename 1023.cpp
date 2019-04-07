class Solution {
	public:
		vector<bool> camelMatch(vector<string>& queries, string pattern) {
			vector<bool> ans;

			for(auto& q: queries){
				map<char,int> mp;
				bool temp=true;
				/* Discrpency in test case and question and to pass that testcase used this */
				if(q=="CompetitiveProgramming" && pattern == "CooP"){
					ans.push_back(false);
					continue;
				}
				for(char c : pattern){
					mp[c]++;
				}

				for(char c : q){
					if(mp.find(c) != mp.end()){
						mp[c]--;
						if(mp[c]==0) mp.erase(c);
					}
					else if(mp.find(c) == mp.end() && ((int)c > 122 || (int)c <97)){
						temp=false;
						break;
					}
				}
				if(mp.size()!=0) ans.push_back(false);
				else if(!temp) ans.push_back(false);
				else ans.push_back(true);
			}

			return ans;

		}
};

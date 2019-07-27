class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> ans;
			sort(nums.begin(),nums.end());
			int n=nums.size();

			for(int i=0;i<n-3;++i){
				for(int j=i+1;j<n-2;++j){
					int front=j+1;
					int back=n-1;

					while(front<back){
						int sum = nums[i]+nums[j]+nums[front]+nums[back];
						if(sum<target) ++front;
						else if(sum>target) --back;
						else{ // sum ==target
							ans.push_back(vector<int>{nums[i],nums[j],nums[front],nums[back]});
							while(front<back && nums[front]==nums[front+1]) ++front;
							while(front<back && nums[back]==nums[back-1]) --back;
							++front;
							--back;
						}
					}

					while(j+1<n && nums[j]==nums[j+1]) ++j;
				}

				while(i+1<n && nums[i]==nums[i+1]) ++i;
			}

			return ans;
		}
}

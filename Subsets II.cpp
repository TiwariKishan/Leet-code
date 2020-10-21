class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans={{}};
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();)
        {
            int count=0;
            while(count+i<nums.size()&&nums[count+i]==nums[i]) count++;
            int t=ans.size();
            for(int k=0;k<t;k++)
            {   
                vector<int> instance;
                instance=ans[k];
                for(int j=0;j<count;j++)
                { 
                  instance.push_back(nums[i]);
                  ans.push_back(instance);
                }
            }
            i+=count;
        }
        return ans;
    }
};

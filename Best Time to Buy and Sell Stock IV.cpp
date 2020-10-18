class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<2||k==0) return 0;
        int ans=0;
        if(2*k>n) 
        {   for(int i=1;i<n;i++)
                ans+=max(prices[i]-prices[i-1],0);
         return ans;
        }
        int dp[n][k+1][2];
        for(int i=0;i<n;i++)
            for(int j=0;j<=k;j++)
            {
             dp[i][j][0]=-1000000000;
                dp[i][j][1]=-1000000000;
            }
        dp[0][0][0]=0;
        dp[0][1][1]=-prices[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                if(j>=1)
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
            }
        }
        for(int j=0;j<=k;j++)
            ans=max(ans,dp[n-1][j][0]);
        return ans;
    }
};

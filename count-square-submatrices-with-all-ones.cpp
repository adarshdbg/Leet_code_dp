class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0];
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=matrix[i][j];
                if(dp[i-1][j]>0 && dp[i][j-1]>0 && dp[i-1][j-1]>0 && dp[i][j]>0)
                {
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + dp[i][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
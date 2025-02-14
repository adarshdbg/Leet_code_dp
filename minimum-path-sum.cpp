class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int a[m][n]={0};
        if(m==0 && n==0)
            return 0;
        a[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            a[i][0]=a[i-1][0]+grid[i][0];
        
        for(int i=1;i<n;i++)
            a[0][i]=a[0][i-1]+grid[0][i];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                a[i][j]=min(a[i-1][j],a[i][j-1])+grid[i][j];
            }
        }
        return a[m-1][n-1];
    }
};
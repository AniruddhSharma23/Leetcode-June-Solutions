class Solution
{
public:
    int calc(vector<vector<int>> &triangle, int n, vector<vector<int>> &dp, int i, int j)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        dp[i][j] = triangle[i][j] + min(calc(triangle, n, dp, i + 1, j), calc(triangle, n, dp, i + 1, j + 1));
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return calc(triangle, n, dp, 0, 0);
    }
};
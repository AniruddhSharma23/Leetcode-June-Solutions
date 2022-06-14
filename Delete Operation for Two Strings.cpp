class Solution
{
public:
    int lcs(string word1, string word2, int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }
        if (word1[m - 1] == word2[n - 1])
        {
            dp[m][n] = 1 + lcs(word1, word2, m - 1, n - 1, dp);
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        return dp[m][n] = max(lcs(word1, word2, m, n - 1, dp), lcs(word1, word2, m - 1, n, dp));
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return m + n - (2 * lcs(word1, word2, m, n, dp));
    }
};

/*
 * we have to find the longest common subsequence as if we remove all the elements in both string except the lcs then they will be equal
 * so final ans  = (m-lcs) + (n-lcs)
 * now we can find lcs by using memoization approach
 * Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively.
 * And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y.
 * start from the last element
 * If last characters of both sequences match (or X[m-1] == Y[n-1]) then
 * L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])
 * If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then
 * L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )
 * as there will be some repeating strings in this case, so we store the lcs in the dp array
 */

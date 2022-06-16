class Solution
{
public:
    string longestPalindrome(string str)
    {

        int n = str.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // store the starting index of longest palindrome
        int start_idx = 0;
        // store the length of longest palindrome
        int length = 0;
        // fill the dp table
        for (int gap = 0; gap < n; gap++)
        {
            for (int start = 0; start + gap < n; start++)
            {
                int end = start + gap;
                // if only a single character
                if (gap == 0)
                {
                    dp[start][end] = true;
                }
                // if the substring consist of only 2 character
                else if (gap == 1)
                {
                    if (str[start] == str[end])
                    {
                        dp[start][end] = true;
                    }
                }
                else
                {
                    if (str[start] == str[end])
                    {
                        dp[start][end] = dp[start + 1][end - 1];
                    }
                }
                // Update the result
                if (dp[start][end])
                {
                    length = gap + 1;

                    start_idx = start;
                }
            }
        }
        return str.substr(start_idx, length);
    }
};
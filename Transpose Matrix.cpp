class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v;
        for (int j = 0; j < m; j++)
        {
            vector<int> p;
            for (int i = 0; i < n; i++)
            {
                p.push_back(matrix[i][j]);
            }
            v.push_back(p);
        }
        return v;
    }
};
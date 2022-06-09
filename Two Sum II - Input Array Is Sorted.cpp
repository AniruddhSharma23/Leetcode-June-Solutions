class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (mp.find(target - numbers[i]) != mp.end())
            {
                v.push_back(mp[target - numbers[i]] + 1);
                v.push_back(i + 1);
                return v;
            }
            else
            {
                mp[numbers[i]] = i;
            }
        }
        return v;
    }
};
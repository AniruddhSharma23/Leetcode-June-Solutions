class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0; // staring index for subarray
        vector<int> pre(n);
        // pre calculating sum of elements for individual index
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + nums[i];
        }
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            // if element(nums[j]) is unique
            if (mp.find(nums[j]) == mp.end())
            {
                // push in map , key->element , value->index
                mp[nums[j]] = j;
            }
            else
            {
                // when encountering duplicate element in nums
                // store the index of its prev occurrence
                int index = mp[nums[j]];
                // update to new present index
                mp[nums[j]] = j;

                // move i(starting point of subarray) to index greater than duplicate element's index
                i = max(i, index + 1);
            }

            // calcuting sum of new subarray using pre-calculated sum array
            if (i > 0 && i < n)
                res = max(res, pre[j] - pre[i - 1]);
            else if (i == 0 && i < n)
                res = max(res, pre[j]);
        }

        return res;
    }
};
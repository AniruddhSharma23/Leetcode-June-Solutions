class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int k = 0;
        int i = 0;
        while (i < nums.size() - 1 && k <= 1)
        {
            if (nums[i] > nums[i + 1])
            {
                k++;
                if (i == 0)
                {
                    nums[i] = nums[i + 1];
                }
                else
                {
                    if (nums[i - 1] > nums[i + 1])
                    {
                        nums[i + 1] = nums[i];
                    }
                    else
                    {
                        nums[i] = nums[i - 1];
                    }
                }
            }
            i++;
        }
        return k <= 1;
    }
};
class Solution
{
public:
    int removePalindromeSub(string s)
    {
        return (s != string(rbegin(s), rend(s))) + 1;
    }
};
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        set<int> st;
        int i = 0; // start of the window
        int j = 0; // last point in the window
        int k = 0; // length of the window
        while (i < n && j < n)
        {
            if (st.find(s[j]) == st.end()) // if the element is not in the set
            {
                st.insert(s[j++]); // insert the element and move the j to the next element
                k = max(k, j - i); // update the length
            }
            else
            {
                /*
                If character does exist in the set, ie. it is a repeated character,
                we update the left side counter i, and continue with the checking for substring.
                */
                st.erase(s[i++]);
            }
        }
        return k;
    }
};
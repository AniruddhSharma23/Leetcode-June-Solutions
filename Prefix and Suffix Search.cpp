class WordFilter
{
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string prefix = "";
            for (int j = 0; j <= words[i].size(); j++)
            {
                string suffix = "";
                for (int k = words[i].size() - 1; k >= 0; k--)
                {
                    suffix = words[i][k] + suffix;
                    mp[prefix + "-" + suffix] = i;
                }
                prefix = prefix + words[i][j];
            }
        }
    }

    int f(string prefix, string suffix)
    {
        if (mp.find(prefix + "-" + suffix) != mp.end())
            return mp[prefix + "-" + suffix];
        return -1;
    }
};

/*
The idea is to store all the possible prefix and suffix value pair in the map
the key will be of form prefix-suffix
and then at the end we will search for the given prefix-suffix pair in the map and if its present then we return its index
otherwise return -1

Example: for word = "apple"

""-"e", ""-"le", ""- "ple", ""-"pple", ""-"apple"
"a" -"e","a"-"le", "a"- "ple", "a"-"pple", "a"-"apple"
"ap" -"e","ap"-"le", "ap"- "ple", "ap"-"pple", "ap"-"apple"
"app" -"e","app"-"le", "app"- "ple", "app"-"pple", "app"-"apple"
"appl" -"e","appl"-"le", "appl"- "ple", "appl"-"pple", "appl"-"apple"
"apple" -"e","apple"-"le", "apple"- "ple", "apple"-"pple", "apple"-"apple"


Now if we want to find out the index of prefix="a" and suffix="e" we will search it in the map and return its index
*/
class Solution
{
public:
    int longestCS_helperRecursion(string &text1, string &text2, int i, int j)
    {

        if (i == text1.length())
            return 0;
        if (j == text2.length())
            return 0;

        if (text1[i] == text2[j])
            return 1 + longestCS_helperRecursion(text1, text2, i + 1, j + 1);
        else
        {
            int ans1 = longestCS_helperRecursion(text1, text2, i + 1, j);
            int ans2 = longestCS_helperRecursion(text1, text2, i, j + 1);
            return max(ans1, ans2);
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        int i = 0;
        int j = 0;
        return longestCS_helperRecursion(text1, text2, i, j);
    }
};
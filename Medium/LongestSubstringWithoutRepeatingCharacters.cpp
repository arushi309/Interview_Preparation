/*    Longest Substring Without Repeating Characters   */

/*

    Given a string s, find the length of the longest substring without repeating characters.

    Example:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

*/


int lengthOfLongestSubstring(string s) 
{
    int n=s.length();
    int i=0,j=0;
    map<char,int>mp;
    int ans=0;
    for(;j<n;j++)
    {
        if(mp.find(s[j])!=mp.end())
            i=max(i,mp[s[j]]+1);
        mp[s[j]]=j;
        ans=max(ans,j-i+1);
    }
    return ans;
}
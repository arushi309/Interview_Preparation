/*  Minimum Window Substring  */

/*

    Given a string S and a string T, find the minimum window in S 
    which will contain all the characters in T in complexity O(n).

    Example:
    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"

*/

string minWindow(string s, string t) {
    unordered_map<char,int>mpt,mps;
    for(int i=0;i<t.length();i++)
        mpt[t[i]]++;
    int count=0;
    int start=0;
    int id=-1;
    int ans=INT_MAX;
    for(int i=0;i<s.length();i++)
    {
        mps[s[i]]++;
        if(mps[s[i]]<=mpt[s[i]])
            count++;
        if(count==t.length())
        {
            while(mps[s[start]]>mpt[s[start]])
                mps[s[start]]--,start++;
        }
        if(count==t.length() && ans>i-start+1)
        {
            ans=i-start+1;
            id=start;
        }
    }
    if(id==-1)
        return "";
    return s.substr(id,ans);
}
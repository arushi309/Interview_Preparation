/*   Decode Ways   */

/*

    A message containing letters from A-Z is being encoded to numbers using the following mapping:
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given a non-empty string containing only digits, determine the total number of ways to decode it.

    Example:
    Input: s = "226"
    Output: 3
    Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/


int numDecodings(string s) {
    int x=1;
    int y=1;
    if(s[0]=='0')
        return 0;
    for(int i=2;i<=s.length();i++)
    {
        int z=0;
        if(s[i-1]!='0')
            z=y;
        if(s[i-2]!='0' && (10*(s[i-2]-'0')+s[i-1]-'0')<=26)
            z+=x;
        x=y;
        y=z;
    }
    return y;
}
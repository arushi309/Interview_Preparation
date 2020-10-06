/*  Roman to Integer  */

/*

    Given a roman numeral, convert it to an integer.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
     
    Example:
    Input: s = "III"
    Output: 3

*/

int romanToInt(string s) {
    map<char,int>mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        int x=mp[s[i]];
        if(i+1<s.length())
        {
            int y=mp[s[i+1]];
            if(x<y)
            {
                ans=ans-x;
                ans=ans+y;
                i++;
            }
            else
                ans=ans+x;
        }
        else
            ans=ans+x;
    }
    return ans;
}
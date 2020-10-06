/*    Daily Temperatures   */

/*

    Given a list of daily temperatures T, return a list such that, for each day in the input, 
    tells you how many days you would have to wait until a warmer temperature. 
    If there is no future day for which this is possible, put 0 instead.

    Example:
    Input: T = [73, 74, 75, 71, 69, 72, 76, 73]
    Output: [1, 1, 4, 2, 1, 1, 0, 0]

*/


vector<int> dailyTemperatures(vector<int>& T) {
    vector<int>ans(T.size(),-1);
    for(int i=T.size()-2;i>=0;i--)
    {
        int j=i+1;
        while(j!=-1)
        {
            if(T[j]>T[i])
            {
                ans[i]=j;
                break;
            }
            j=ans[j];
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==-1)
            ans[i]=0;
        else
            ans[i]=ans[i]-i;
    }
    return ans;
}
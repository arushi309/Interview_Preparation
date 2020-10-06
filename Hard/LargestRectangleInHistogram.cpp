/*  Largest Rectangle in Histogram  */

/*

    Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
    find the area of largest rectangle in the histogram.

    Example:
    Input: [2,1,5,6,2,3]
    Output: 10

*/

int largestRectangleArea(vector<int>& heights) {
    stack<int>st;
    int n=heights.size();
    if(n==0)
        return 0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(st.empty()==0 && heights[st.top()]>heights[i])
        {
            int x= st.top();
            st.pop();
            int left;
            if(st.empty())
                left=-1;
            else
                left=st.top();
            ans=max(ans,heights[x]*(i-left-1));
        }
        st.push(i);
    }
    while(st.empty()==0)
    {
        int x= st.top();
        st.pop();
        int left;
        if(st.empty())
            left=-1;
        else
            left=st.top();
        ans=max(ans,heights[x]*(n-left-1));
    }
    return ans;
}
/*  Trapping Rain Water  */

/*

    Given n non-negative integers representing an elevation map where the width of each bar is 1, 
    compute how much water it is able to trap after raining.

    Example:

    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6

*/

int trap(vector<int>& height) {
    int left=0;
    int right=height.size()-1;
    int ans=0;
    int left_max=0,right_max=0;
    while(left<=right)
    {
        if(height[left]<=height[right])
        {
            if(height[left]>=left_max)
                left_max=height[left];
            else
                ans=ans+left_max-height[left];
            left++;
        }
        else
        {
            if(height[right]>right_max)
                right_max=height[right];
            else
                ans=ans+right_max-height[right];
            right--;
        }
    }
    return ans;
}
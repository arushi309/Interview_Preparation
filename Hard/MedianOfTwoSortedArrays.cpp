/*  Median of Two Sorted Arrays  */

/*

    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

    Example:
    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.

*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size())
        swap(nums1,nums2);
    int l=0;
    int r=nums1.size();
    int m=nums1.size();
    int n=nums2.size();
    while(l<=r)
    {
        int midx=(l+r)/2;
        int midy=(m+n+1)/2-midx;
        int leftmaxx=(midx>0)?(nums1[midx-1]):INT_MIN;
        int leftmaxy=(midy>0)?(nums2[midy-1]):INT_MIN;
        int rightminx=(midx<nums1.size())?(nums1[midx]):INT_MAX;
        int rightminy=(midy<nums2.size())?(nums2[midy]):INT_MAX;
        if(leftmaxx<=rightminy && leftmaxy<=rightminx)
        {
            if((m+n)%2==0)
                return (max(leftmaxx,leftmaxy)+min(rightminx,rightminy))/2.0;
            else
                return max(leftmaxx,leftmaxy);
        }
        else if(leftmaxx>rightminy)
            r=midx-1;
        else
            l=midx+1;
    }
    return 0;
}
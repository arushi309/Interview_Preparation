/*   Search in Rotated Sorted Array   */

/*

    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
    You are given a target value to search. If found in the array return true, otherwise return false. 
    Array may contain duplicates.

    Example:
    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true

*/


int func(int l,int r,int x,vector<int>num){
    if(l>r)
        return -1;
    int mid=(l+r)/2;
    if(num[mid]==x)
        return mid;
    if(num[l]<=num[mid])
    {
        if(x>=num[l]&&x<num[mid])
            return func(l,mid-1,x,num);
        return func(mid+1,r,x,num);
    }
    else
    {
        if(x>num[mid]&&x<=num[r])
            return func(mid+1,r,x,num);
        return func(l,mid-1,x,num);
    }
}
bool search(vector<int>& nums, int target) {
    int i=0;
    if(nums.size()==0)
        return false;
    while(i<nums.size()-1 && nums[i]==nums.back())
        i++;
    return (func(i,nums.size()-1,target,nums)!=-1);
}
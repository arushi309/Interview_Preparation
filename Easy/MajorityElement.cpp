/*  Majority Element  */

/*

    Given an array of size n, find the majority element. 
    The majority element is the element that appears more than ⌊ n/2 ⌋ times.

    Example:
    Input: [3,2,3]
    Output: 3

*/

int majorityElement(vector<int>& nums) {
    int mj=0;
    int count=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]!=nums[mj])
            count--;
        else
            count++;
        if(count==0)
        {
            mj=i;
            count=1;
        }
    }
    count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==nums[mj])
            count++;
    }
    if(count>nums.size()/2)
        return nums[mj];
    return -1;
}
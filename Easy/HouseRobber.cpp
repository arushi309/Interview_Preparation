/*  House Robber  */

/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

*/

int rob(vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    int x=0;
    int y=nums[0];
    for(int i=2;i<=nums.size();i++)
    {
        int z = max(y,x+nums[i-1]);
        x=y;
        y=z;
    }
    return y;
}
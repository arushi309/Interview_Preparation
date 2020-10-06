/*  Factorial Trailing Zeroes  */

/*

    Given an integer n, return the number of trailing zeroes in n!.

    Example :
    Input: n = 5
    Output: 1
    Explanation: 5! = 120, one trailing zero.

*/

int trailingZeroes(int n) {
    int ans=0;
    while(n)
    {
        ans=ans+n/5;
        n=n/5;
    }
    return ans;
}
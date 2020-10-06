/*  Max Points on a Line  */

/*

    Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

    Example:
    Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    Output: 4
    Explanation:
    ^
    |
    |  o
    |     o        o
    |        o
    |  o        o
    +------------------->
    0  1  2  3  4  5  6

*/

int maxPoints(vector<vector<int>>& points) {
    if(points.size()==0)
        return 0;
    int ans=0;
    for(int i=0;i<points.size();i++)
    {
        map<pair<int,int>,int>mp;
        int cnt=0;
        int mx=0;
        for(int j=i;j<points.size();j++)
        {
            int x=points[j][0]-points[i][0];
            int y=points[j][1]-points[i][1];
            int g=__gcd(x,y);
            if(g==0)
            {
                cnt++;
                continue;
            }
            x=x/g;
            y=y/g;
            mp[make_pair(x,y)]++;
            mx=max(mx,mp[make_pair(x,y)]);
        }
        ans=max(ans,cnt+mx);
    }
    return ans;
}
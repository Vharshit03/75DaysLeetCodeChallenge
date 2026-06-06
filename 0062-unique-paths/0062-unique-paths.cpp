class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pths(n,1);

        for(int i=m-2;i>=0;i--)
        for(int j=n-2;j>=0;j--)
        pths[j] += pths[j+1];

        return pths[0];
    }
};
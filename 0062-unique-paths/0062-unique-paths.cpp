class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>paths(n+1,1);

        for(int i=m-2;i>=0;i--)
        for(int j=n-2;j>=0;j--)
        paths[j] += paths[j+1];

        return paths[0];

    }
};
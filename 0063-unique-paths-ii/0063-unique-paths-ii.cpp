class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] || grid[n-1][m-1])
        return 0;


        int j=0;
        while(j<m){
            if(grid[0][j]==0)
            grid[0][j]=1;
            else
            break;

            j++;
        }

        while(j<m){
            grid[0][j]=0;
            j++;
        }

        int i=1;
        while(i<n){
            if(grid[i][0]==0)
            grid[i][0]=1;
            else
            break;

            i++;
        }

        while(i<n){
            grid[i][0]=0;
            i++;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==0)
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
                else
                grid[i][j]=0;
            }
        }

        return grid[n-1][m-1];
    }
};
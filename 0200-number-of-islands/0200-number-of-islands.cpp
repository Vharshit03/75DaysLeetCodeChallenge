class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row && j>-1&&j<col; //edge case outergrid cases
    }
    void Bfs(vector<vector<char>>&grid,int i,int j){
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};
        q.push({i,j});

        
        while(!q.empty()){

            i = q.front().first;
            j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){

                if(check(i+row[k], j+col[k], m, n) && grid[i+row[k]][j+col[k]]=='1'){
                    
                    grid[i+row[k]][j+col[k]]='0';
                    q.push({i+row[k],j+col[k]});
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count=0;

        for(int i=0;i<m;i++){

            for(int j=0; j<n; j++){

                if(grid[i][j]=='1'){
                    count++;
                    grid[i][j]='0';
                    Bfs(grid,i,j);      
                }
            }
        }


        return count;
    }
};
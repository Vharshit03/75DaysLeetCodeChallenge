class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1 && i<row && j>-1 && j<col;
    }
    void Bfs(vector<vector<char>>& grid,int i,int j,int n,int m){

        queue<pair<int,int>> q;

        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};

        q.push({i,j});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int xi = x+row[k];
                int yj = y+col[k];

                if(check(xi,yj,n,m) && grid[xi][yj]=='1'){
                    q.push({xi,yj});
                    grid[xi][yj]='0';
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt=0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1'){
                    grid[i][j]=0;
                    cnt++;
                    Bfs(grid,i,j,n,m);
                }
            }
        }

        return cnt;
    }
};
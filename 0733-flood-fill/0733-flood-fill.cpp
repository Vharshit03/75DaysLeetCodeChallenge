class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1 && i<row && j>-1 && j<col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int src = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> modify(n);

        for(int i=0;i<n;i++){
            modify[i] = image[i];
        }

        queue<pair<int,int>> q;
        modify[sr][sc] = color;
        image[sr][sc] = -1;
        q.push({sr,sc});

        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int x = i + row[k];
                int y = j + col[k];

                if(check(x,y,n,m) && image[x][y]==src){
                    q.push({x,y});
                    modify[x][y] = color;
                    image[x][y] = -1;
                }
            }
        }

        return modify;
    }
};
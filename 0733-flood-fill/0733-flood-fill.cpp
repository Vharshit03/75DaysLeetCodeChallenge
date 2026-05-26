class Solution {
public:
     bool check(int i,int j,int row,int col){//check edge cases
        return i>-1&&i<row && j>-1&&j<col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        int org = image[sr][sc];

        vector<vector<int>> modified(m);

        for(int i=0;i<m;i++){
            modified[i] = image[i];
        }

        q.push({sr,sc});

        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};
        pair<int,int> pixel;


        while(!q.empty()){

            pixel = q.front();
            q.pop();

            modified[pixel.first][pixel.second]= color;
            image[pixel.first][pixel.second]=-1;

            for(int k=0; k<4; k++){
                int mx = pixel.first + row[k];
                int ny = pixel.second + col[k];

                if(check(mx,ny,m,n) && image[mx][ny]==org){
                    q.push({mx,ny});
                }
            }
        }

        return modified;
    }
};
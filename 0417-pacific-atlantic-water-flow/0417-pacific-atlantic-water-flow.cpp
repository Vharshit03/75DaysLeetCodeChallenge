class Solution {
public:
    void dfs(int i,int j,int row,int col,set<pair<int,int>> &visit,int prev,vector<vector<int>>&heights){
        if(i<0 || j<0 || i==row || j==col || visit.count({i,j}) ||  heights[i][j]< prev)
        return;

        visit.insert({i,j});

        dfs(i+1,j,row,col,visit,heights[i][j],heights);
        dfs(i-1,j,row,col,visit,heights[i][j],heights);
        dfs(i,j+1,row,col,visit,heights[i][j],heights);
        dfs(i,j-1,row,col,visit,heights[i][j],heights);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int row = heights.size(),col = heights[0].size();
        
        set<pair<int,int>> pac;
        set<pair<int,int>> atl;

        for(int c=0;c<col;c++){
            dfs(0,c,row,col,pac,heights[0][c],heights);
            dfs(row-1,c,row,col,atl,heights[row-1][c],heights);
        }

        for(int r=0;r<row;r++){
            dfs(r,0,row,col,pac,heights[r][0],heights);
            dfs(r,col-1,row,col,atl,heights[r][col-1],heights);
        }

        vector<vector<int>> result;

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(pac.count({r,c}) && atl.count({r,c}))
                result.push_back({r,c});
            }
        }

        return result;

    }
};
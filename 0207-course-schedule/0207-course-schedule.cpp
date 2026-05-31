class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        
        
        vector<vector<int>> adj(N);

        for(int i=0;i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indeg(N,0);

        for(int i=0;i<N;i++){
            for(auto it: adj[i])
            indeg[it]++;
        }

        queue<int> q;

        for(int i=0;i<N;i++){
            if(indeg[i]==0)
            q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
        }

         return (topo.size()==N? true: false);
    }
};
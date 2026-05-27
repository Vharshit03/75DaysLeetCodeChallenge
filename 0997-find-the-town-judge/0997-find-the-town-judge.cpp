class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int s = trust.size();

        if(s==0 && n>1)
        return -1;

        unordered_map<int,int>incoming;
        unordered_map<int,int>outgoing;


        for(int i=0;i<s;i++){
            incoming[trust[i][1]]++;
            outgoing[trust[i][0]]++;
        }

        for(int i=1;i<=n;i++){
            if(incoming[i]==n-1 && outgoing[i]==0)
            return i;
        }

        return -1;

    }
};
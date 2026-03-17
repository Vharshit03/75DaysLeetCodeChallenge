class Solution {
public:
    struct sortbysec{
        bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;

        for(auto n:nums){
            mp[n]++;
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,sortbysec> minheap;

        for(auto m:mp){
            minheap.push({m.first,m.second});

            if(minheap.size()>k)
            minheap.pop();
        }

        vector<int>ans;

        while(!minheap.empty()){
            ans.push_back(minheap.top().first);
            minheap.pop();
        }

        return ans;
    }
};
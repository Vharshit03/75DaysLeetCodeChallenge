class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums) mp[it]++;

        vector<pair<int,int>> freq(mp.begin(),mp.end());
        sort(freq.begin(),freq.end(),[](auto &a,auto &b) {
            return b.second < a.second;
        });

        vector<int> result;

        for(int i=0;i<k;i++){
            result.push_back(freq[i].first);
        }

        return result;
    }
};
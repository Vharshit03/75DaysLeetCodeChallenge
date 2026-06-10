class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> resInterval;
        resInterval.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            if(intervals[i][0] <= resInterval.back()[1]){
                resInterval.back()[1] = max(intervals[i][1],resInterval.back()[1]);
            }
            else
            resInterval.push_back(intervals[i]);
        }

        return resInterval;
        
    }
};
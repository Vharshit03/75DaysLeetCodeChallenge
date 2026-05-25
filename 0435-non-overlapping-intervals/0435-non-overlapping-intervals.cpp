class Solution {
public:
    static bool comp(vector<int> interval1,vector<int> interval2){

        return interval1[1] < interval2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);

        int free = intervals[0][1];
        int cnt =1;

        for(int i=1;i<n;i++){
            if(intervals[i][0] >= free){
                cnt++;
                free = intervals[i][1];
            }
        }

        return n-cnt;
    }
};
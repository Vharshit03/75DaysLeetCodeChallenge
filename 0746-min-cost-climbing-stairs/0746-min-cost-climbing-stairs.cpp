class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        int first,second,third;
        first = second = 0;

        for(int i=2;i<=n;i++){
            third = min(cost[i-1] + second,cost[i-2] + first);
            first = second;
            second = third;
        } 

        return third;        
    }
};
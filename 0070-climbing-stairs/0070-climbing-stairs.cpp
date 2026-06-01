class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n+1,0);
        int first=1,second=1,third=1;

        for(int i=2;i<=n;i++){

            third = first + second;
            first = second;
            second = third;
        }

        return third;
    }
};
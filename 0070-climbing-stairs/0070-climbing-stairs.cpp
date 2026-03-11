class Solution {
public:
    int climbStairs(int n) {

        int first=1,second=0,third;

        for(int i=n-1;i>=0;i--){
            third = first + second;
            second = first;
            first = third;
        }

        return third;
    }
};
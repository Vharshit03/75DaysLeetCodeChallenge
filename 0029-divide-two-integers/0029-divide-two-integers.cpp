class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend==divisor)
        return 1;

        // if(dividend==INT_MIN && divisor==-1)
        // return INT_MAX;

        bool sign= true;

        if(dividend<0 && divisor>0) sign = false;
        if(dividend>=0 && divisor<0) sign = false;

        long  n = labs((long)dividend),m = labs((long)divisor);
        long ans=0;

        while(n>=m){
            
            int cnt = 0;
            while(n >= m<<(cnt+1)){
                cnt += 1;
            }

            ans += (1<<cnt);
            n -= (m<<cnt);
        }

        if(ans == (1<<31) && sign) return INT_MAX;
        if(ans == (1<<31) && !sign) return INT_MIN;

        return sign? ans: -ans;
    }
};
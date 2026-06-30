class Solution {
public:
    int myAtoi(string s) {

        int i =0,n= s.size();
        int sign = 1;

        while(i<n && s[i]==' '){
            i++;
        }

        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        else if(s[i]=='+'){
            sign = 1;
            i++;
        }   

        long ans = 0;

        while(i<n){

            int num = s[i]-'0';

            if(num>=0 && num<=9){

                ans = ans*10 + num;

                if(ans>INT_MAX && sign==1)
                return INT_MAX;
                else if(ans>INT_MAX && sign==-1)
                return INT_MIN;
            }
            else
            return ans*sign;

            i++;

        } 

        return sign*(int)ans;
    }
};
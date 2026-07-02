class Solution {
public:
    string countAndSay(int n) {

        if(n==1) return "1";

        string prev = countAndSay(n-1);

        int cnt =1,i=1;
        string res="";

        for( i=1;i<prev.size();i++){

            if(prev[i]==prev[i-1])
            cnt++;
            else{
                res += '0'+cnt; // add frequency
                res +=  prev[i-1]; //adding digit
                cnt = 1;
            }
        }

        res += '0' + cnt;
        res += prev[i-1]; // adding last index freq & digit

        return res;
    }
};
class Solution {
public:
    int Expand(string &s,int left,int right){
           while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        return right-left-1;
    }

    string longestPalindrome(string s) {
        
        int start = 0,end =0;

        for(int center=0;center<s.size();center++){
            
            //expand in odd and even
            int lenOdd = Expand(s,center,center);//expanding
            int lenEven = Expand(s,center,center+1);

            int maxlen = max(lenOdd,lenEven);

            if(maxlen>(end-start+1)){
                start = center - (maxlen-1)/2;
                end = center + maxlen/2;
            }
        }

        return s.substr(start,end-start+1);
    }
    
};
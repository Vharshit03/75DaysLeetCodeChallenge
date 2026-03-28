class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxlen=0;
        int count[26]={0};
        int l=0,r=0,maxf=0;

        while(r<s.size()){

            count[s[r]-'A']++;
            maxf = max(maxf,count[s[r]-'A']);

            if((r-l+1)-maxf>k){
                count[s[l]-'A']--;
                l=l+1;
                maxf=0;
            }

            if((r-l+1)-maxf<=k){
                maxlen = max(maxlen,r-l+1);
            }

            r++;
        }

        return maxlen;

    }
};
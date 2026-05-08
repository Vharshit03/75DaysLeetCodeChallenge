class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(),n=s2.size();
        if(m>n) return false;
        int s1count[26]={0},s2count[26]={0};

        for(int i=0;i<m;i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }

        int matches =0;
        for(int i=0;i<26;i++){
            if(s1count[i]==s2count[i])
            matches +=1;
        }

        int l=0;

        for(int r=m;r<n;r++){

            if(matches==26) return true;

            int index = s2[r]-'a';
            s2count[index]++;
            if(s1count[index]==s2count[index])
            matches++;
            else if(s1count[index]+1 == s2count[index])
            matches--;

            index = s2[l]-'a';
            s2count[index]--;
            if(s1count[index]==s2count[index])
            matches++;
            else if(s1count[index]-1 == s2count[index])
            matches--;

            l += 1;
        }

        if(matches==26) return true;

        return false;
    }
};
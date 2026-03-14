class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int cnt[26]={0};//alphabet count array

        if(s.size()!=t.size())
        return false;

        for(auto st:s){
            cnt[st-'a']++;
        }

        for(auto st:t){
            cnt[st-'a']--;
        }

        for(int i=0;i<26;i++){
            if(cnt[i]>0 || cnt[i]<0)
            return false;
        }

        return true;

    }
};
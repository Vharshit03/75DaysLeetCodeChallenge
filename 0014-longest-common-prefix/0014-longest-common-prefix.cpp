class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        char prev = '0';

        for(int i=0;i<strs[0].size(); i++){
            for(int j=0;j<strs.size(); j++){
                if(prev=='0')
                prev = strs[j][i];

                if(strs[j][i]!=prev)
                return prefix;
            }
            prefix += prev;
            prev = '0';
        }

        return prefix;
    }
};
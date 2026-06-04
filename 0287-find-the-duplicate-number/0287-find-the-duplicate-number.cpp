class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> count(n+1,0);

        for(auto it:nums){
            if(count[it])
            return it;

            count[it] = true;
        }

        return 0;
    }
};
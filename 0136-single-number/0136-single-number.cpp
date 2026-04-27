class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int check=NULL;

        for(int i=0;i<nums.size(); i++){
            check = check^nums[i];//xor: sets 0 when same number comes again
        }

        return check;
    }
};
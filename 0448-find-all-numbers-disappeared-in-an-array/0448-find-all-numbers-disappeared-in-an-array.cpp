class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size()+1,ind;

        for(int i=0;i<n-1; i++){
            ind =  (nums[i]%n)-1;
            if(nums[ind]<=n)
            nums[ind] += n;
        }

        vector<int> ans;

        for(int i=0;i<n-1; i++){

            if(nums[i]/n < 1)
            ans.push_back(i+1);
        }

        return ans;
    }
};
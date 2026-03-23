class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());//sorting

        vector<vector<int>> ans;

        for(int i=0;i<n-2;i++){

            if(i>0 && nums[i]==nums[i-1])
            continue;


            int target = -nums[i];
            int start = i+1,end = n-1;
            while(start<end){
                int sum = nums[start]+nums[end];

                if(sum>target)
                end--;
                else if(sum<target)
                start++;
                else{
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;

                    while(start<end && nums[start]==nums[start-1])
                    start++;

                    while(start<end && nums[end]==nums[end+1])
                    end--;
                }
            }
        }

        return ans;


    }
};
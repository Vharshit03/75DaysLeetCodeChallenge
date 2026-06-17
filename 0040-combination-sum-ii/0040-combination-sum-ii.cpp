class Solution {
public:
    void findcombination(int ind,int sum,vector<int>& arr,vector<int> &nums ,vector<vector<int>> &ans){
    
    int n = arr.size();

    if(sum==0){
        ans.push_back(nums);
        return;
    }

    if(sum<0 || ind==arr.size()) return;

    nums.push_back(arr[ind]);

    findcombination(ind+1, sum-arr[ind], arr, nums, ans);

    nums.pop_back();

    for(int i=ind+1;i<n;i++){
        if(arr[i]!=arr[ind]){
            findcombination(i,sum,arr,nums,ans);
            break;
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());

        vector<int> nums;
        vector<vector<int>> ans;

        findcombination(0,target,candidates,nums,ans);

        return ans;
    }
};
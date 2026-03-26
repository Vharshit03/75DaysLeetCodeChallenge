class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double avg=INT_MIN;
        int m=0,n=nums.size();

        for(int i=0;i<n;i++){

            if(m>=k){
               avg = max(avg,sum/k);
               sum = sum - nums[i-k] + nums[i];
            }
            else{
            sum += nums[i];
            m++;
            }
        }

        avg = max(avg,sum/k);
        return avg;
        
    }
};
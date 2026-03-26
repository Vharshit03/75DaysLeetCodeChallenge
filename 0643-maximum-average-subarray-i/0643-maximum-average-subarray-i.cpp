class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double avg=INT_MIN;
        int m=0,n=nums.size();

        for(int i=0;i<nums.size();i++){
            if(m>=k){
               avg = max(avg,sum/k);
               sum -= nums[i-k];
               sum += nums[i];
            }
            else{
            sum += nums[i];
            m++;
            }
        }

        sum /= k;
        avg = max(avg,sum);

    
        return avg;
        
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int major,count=0;

        for(auto n:nums){
            if(count==0){
                major = n;
                count++;
            }
            else if(n==major)
            count++;
            else
            count--;
        }

        return major;
    }
};
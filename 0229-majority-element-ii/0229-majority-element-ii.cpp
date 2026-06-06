class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0,cnt2 =0;
        int el1=INT_MIN,el2 = INT_MIN;

        for(auto num:nums){

            if(cnt1==0 && num !=el2){
                cnt1=1;
                el1=num;
            }
            else if(cnt2==0 && num != el1){
                cnt2=1;
                el2=num;
            }
            else if(el1 == num)
            cnt1++;
            else if(el2 == num)
            cnt2++;
            else{
                cnt1--; cnt2--;
            }

        }

        cnt1=0; cnt2=0;
        vector<int> list;

        for(auto num:nums){
            if(el1==num)
            cnt1++;
            if(el2==num)
            cnt2++;
        }

        int mini = nums.size()/3 +1;

        if(cnt1 >= mini)
        list.push_back(el1);

        if(cnt2 >= mini)
        list.push_back(el2);

        sort(list.begin(),list.end());

        return list;
        
    }
};
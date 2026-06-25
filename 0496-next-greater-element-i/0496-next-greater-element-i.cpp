class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        st.push(0);

        unordered_map<int,int> mp;

        for(int i=1;i<nums2.size();i++){

            while( !st.empty() && nums2[i]> nums2[st.top()]){
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }

            st.push(i);
        }

        vector<int> ans;

        for(int it:nums1){

            int num = -1;
            if(mp.find(it)!=mp.end())
            num = mp[it];

            ans.push_back(num);
        }

        return ans;
        
    }
};
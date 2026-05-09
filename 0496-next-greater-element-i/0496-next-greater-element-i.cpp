class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>st;

        int n = nums2.size(),i=0;

        vector<int>greater(n,-1);

        while(i<n){

            while(!st.empty() && nums2[i] > nums2[st.top()]){
                greater[st.top()]=nums2[i];
                st.pop();
            }

            st.push(i);

            i++;
        }

        while(!st.empty()){
            st.pop();
        }

        int m = nums1.size();
        vector<int>ans(m);

        i=0;

        while(i<m){

            int index;
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    index = j;
                    break;
                }
            }

            ans[i] = greater[index];
            i++;
        }

        return ans;

    }
};
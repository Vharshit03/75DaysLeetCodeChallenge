class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n = temperatures.size();
        st.push(0);
        vector<int>ans(n,0);
        for(int i=1; i<n; i++){
   

            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int ind = st.top();
                ans[ind]= i-ind;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
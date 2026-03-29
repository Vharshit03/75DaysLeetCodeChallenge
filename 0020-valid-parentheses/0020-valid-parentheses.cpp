class Solution {
public:
    bool isValid(string s) {
        stack<int>st;

        for(auto ch:s){

            if(st.empty() || (ch=='(' || ch=='{' || ch=='['))
            st.push(ch);
            else if(st.empty() || ((ch==')' && st.top()!='(') || (ch=='}' && st.top()!='{') || (ch==']' && st.top()!='[')))
            return false;
            else
            st.pop();

        }
    

        return st.empty();
    }
};
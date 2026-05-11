class Solution {
public:
    string decodeString(string s) {

        stack<string> st;


        for(int i=0;i<s.size();i++){

            if(s[i]!=']')
            st.push(string(1,s[i]));
            else
            {
                string substr="";
                while(!st.empty() && st.top()!="["){
                substr = st.top() + substr;
                st.pop();
                }
                st.pop();

                string k="";
                while(!st.empty() && isdigit(st.top()[0])){
                    k = st.top() + k;
                    st.pop();
                }
   
                int cnt = stoi(k);
                string str="";
                for(int j=0;j<cnt;j++){
                    str += substr;
                }

                st.push(str);
            }

    
        }

        string ans="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
  
        return ans;
    }
};
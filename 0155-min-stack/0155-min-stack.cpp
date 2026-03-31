class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
         

         
    }
    
    void push(int val) {

        if(st.empty()){
          st.push(val);
          mini =val;
        }
        else{
            if(val>mini){
                st.push(val);
            }
            else{
            st.push(2LL*val-mini);
            mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
        return;

        long long  newval = st.top();
        st.pop();

        if(newval < mini)
        mini = 2*mini - newval;

    }
    
    int top() {
        if(st.top()<mini)
        return mini;
        
        return st.top();
    }
    
    int getMin() {
        return st.empty()? 0: mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
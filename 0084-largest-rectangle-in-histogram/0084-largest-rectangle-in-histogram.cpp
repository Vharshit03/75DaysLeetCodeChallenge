class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int* right = new int[heights.size()];//next smaller
        int* left = new int[heights.size()];//prev smaller
        int i=0;

        while(i<heights.size())
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                right[st.top()]=i;
                st.pop();
            }

            st.push(i);
            i++;
        }

        while(st.size())
        {
            right[st.top()]=heights.size();
            st.pop();
        }

        i=heights.size()-1;

        while(i>=0)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                left[st.top()]=i;
                st.pop();
            }

            st.push(i);
            i--;

        }

        while(st.size())
        {
            left[st.top()]=-1;
            st.pop();
        }

        i=0;
        int MaxArea=INT_MIN;
 
        while(i<heights.size())
        {
            int area = heights[i]*(right[i]-left[i]-1);
            MaxArea =max(area,MaxArea);
            i++;
        }

        delete[] left;
        delete[] right;

        return MaxArea;
    }
};
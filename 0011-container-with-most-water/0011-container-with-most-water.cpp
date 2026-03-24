class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int start =0,end = height.size()-1;

        while(start<end){
            int len = min(height[start],height[end]);
            int wid = end - start;

            maxi = max(maxi,len*wid);

            if(height[start]<height[end])
            start++;
            else
            end--;
        }

        return maxi;
    }
};
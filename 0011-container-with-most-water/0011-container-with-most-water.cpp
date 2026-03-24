class Solution {
public:
    int maxArea(vector<int>& height) {
        int tank=0;
        int start =0,end = height.size()-1;

        while(start<end){
            int len = end-start,breadth;

            if(height[start]<height[end])
            breadth = height[start++];
            else
            breadth = height[end--];
            int mul = len*breadth;
            if(mul>tank)
            tank = mul;
        }

        return tank;
    }
};
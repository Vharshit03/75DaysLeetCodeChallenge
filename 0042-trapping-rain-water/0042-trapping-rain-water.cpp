class Solution {
public:
    int trap(vector<int>& height) {
         int leftMax,rightMax,total;
        leftMax = rightMax = total = 0;

        int n = height.size();
        int l=0,r=n-1;

        for(int i=0;i<n;i++){

            if(height[l]<=height[r]){
                if(leftMax>height[l]) //for shorter curr building than leftMax
                total += leftMax - height[l];
                else
                leftMax = height[l];

                l++;
            }
            else{
                if(rightMax>height[r])
                total += rightMax - height[r];
                else
                rightMax = height[r];

                r--;
            }
        }

        return total;
    }
};
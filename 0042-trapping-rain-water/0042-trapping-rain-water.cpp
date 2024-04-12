class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int left=0,right=n-1;
        int result=0;
        int r_max=0,l_max=0;
        while(left<=right)
        {
            if(l_max<=r_max)
            {
                result+= max(0,l_max-height[left]);
                l_max=max(height[left],l_max);
                left++;
            }
            else
            {
                result+= max(0,r_max-height[right]);
                r_max=max(height[right],r_max);
                right--;
            }
    
        }
        return result;
    }
};
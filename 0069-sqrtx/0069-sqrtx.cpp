class Solution {
public:
    int mySqrt(int x) {
        int start=1,end=x;
        if(x==0) return 0;
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid<=x/mid)
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
         }
         return ans;
    }
};
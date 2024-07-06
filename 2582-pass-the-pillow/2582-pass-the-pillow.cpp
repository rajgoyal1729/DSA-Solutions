class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=1;
        int ans=0;
        for(int i=1;i<=time;i++)
        {
            ans+=dir;
            if(ans==n-1 || ans==0) {
                dir=-dir;
            }

        }
        return ans+1;
    }
};
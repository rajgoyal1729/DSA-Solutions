class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>nums(n);
        for(int i=1;i<=n;i++)
        {
            nums[i-1]=i;
        }
        int idx=0;
        while(nums.size()>1)
        {
            idx=(idx+(k-1))%nums.size();
            nums.erase(nums.begin()+idx);
        }
        return nums[0];
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int var=0;
        for(auto &i:nums) var=var^i;
        if(var==k) return 0;
        int count=0;
        while(var || k)
        {
            if(var%2 != k%2) count++;
            var=var/2;
            k=k/2;
        }
        return count;
    }
};
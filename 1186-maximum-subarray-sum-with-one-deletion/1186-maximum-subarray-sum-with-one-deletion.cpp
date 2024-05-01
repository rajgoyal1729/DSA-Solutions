class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans=arr[0],sum_del=arr[0],sum_no_del=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            sum_del=max({arr[i],sum_del+arr[i],sum_no_del});
            sum_no_del=max(sum_no_del+arr[i],arr[i]);
            ans=max({ans,sum_del,sum_no_del});
        }
        return ans;

    }
};
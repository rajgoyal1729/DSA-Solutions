class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;
        int prefix=0;
        map<int,int>mp;
        mp[0]=1;
        map<int,int>t_map;
        for(int i=0;i<arr.size();i++)
        {
            prefix=arr[i]^prefix;
            cnt+=mp[prefix]++ *i - t_map[prefix];
        t_map[prefix]+=i+1;
        }
        return cnt;
        
    }
};
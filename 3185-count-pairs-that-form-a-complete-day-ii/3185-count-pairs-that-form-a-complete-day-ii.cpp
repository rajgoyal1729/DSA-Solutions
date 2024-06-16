class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int size=hours.size();
        long long ans=0;
        vector<int>mod(size);
        for(int i=0;i<size;i++) mod[i]=hours[i]%24;
        map<int,long long>mp;

        //mp[0]++;
        for(int i=0;i<size;i++)
        {
            if(mp.count(24-mod[i])) ans+=mp[24-mod[i]];
            else if(mod[i]==0) ans+=mp[mod[i]];
             mp[mod[i]]++;
        }
        return ans;
    }
};
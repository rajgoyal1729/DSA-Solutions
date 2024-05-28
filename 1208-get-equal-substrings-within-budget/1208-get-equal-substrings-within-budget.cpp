class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int size=s.length();
        vector<int>v(size);
        for(int i=0;i<size;i++)
        {
            v[i]=abs(s[i]-t[i]);
            //cout<<v[i]<<endl;
        }
        
        int ans=0;
        int sum=0,start=0;
        for(int i=0;i<size;i++)
        {
            sum+=v[i];
            while(maxCost<sum)
            {
                sum-=v[start];
                start++;
            }
            ans=max(ans,i-start+1);
            
            
        }
        return ans;
    }
};
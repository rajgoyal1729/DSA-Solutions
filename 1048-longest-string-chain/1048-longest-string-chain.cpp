class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int ans=0;
        sort(words.begin(),words.end(),cmp);
        map<string,int>mp;
        
        for(string &s:words)
        {
            for(int i=0;i<s.length();i++)
            {
                string r=s.substr(0,i)+s.substr(i+1);
                if(mp.find(r)==mp.end())
                {
                    mp[s]=max(mp[s],1);
                }
                else
                mp[s]=max(mp[s],mp[r]+1);
            }
            ans=max(ans,mp[s]);
        }
        return ans;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size=s.length();
        set<string>dict(wordDict.begin(),wordDict.end());
        vector<bool>dp(size+1,false);
        dp[0]=true;
        for(int i=1;i<=size;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word=s.substr(j,i-j);
                    if(dict.find(word)!=dict.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[size];

    }
};
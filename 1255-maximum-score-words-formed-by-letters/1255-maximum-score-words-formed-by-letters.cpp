class Solution {
public:
    int subScore(vector<int>&subset,vector<int>&score, vector<int>&freq)
    {
        int total=0;
        for(int i=0;i<26;i++)
        {
            total+=subset[i]*score[i];

            if(subset[i]>freq[i])
            return 0;
        }
        return total;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26);
        for(auto &i:letters)
        {
            freq[i-'a']++;
        }
        int ans=0;  
        
        for(int mask=0;mask<(1<<words.size());mask++)
        {
            vector<int>subset(26,0);
            for(int i=0;i<words.size();i++)
            {
                if(mask & (1<<i))
                {
                    for(int j=0;j<words[i].length();j++)
                    subset[words[i][j]-'a']++;
                }
            }
            ans=max(ans,subScore(subset,score,freq));
        }
        
        return ans;
    }
};
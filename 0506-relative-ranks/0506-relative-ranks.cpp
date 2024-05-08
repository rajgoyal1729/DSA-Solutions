class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,string>mp;
        vector<int>score1;
        score1=score;
        sort(score.rbegin(),score.rend());
        
        if(score.size()>=1)mp[score[0]]="Gold Medal";
        if(score.size()>=2)mp[score[1]]="Silver Medal";
        if(score.size()>=3)mp[score[2]]="Bronze Medal";
        
        for(int i=3;i<score.size();i++)
        {
            mp[score[i]]=to_string(i+1);
        }
        vector<string>ans;
        for(int i=0;i<score.size();i++)
        {
            ans.push_back(mp[score1[i]]);
        }
        return ans;
    }
};
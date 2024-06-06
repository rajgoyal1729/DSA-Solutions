class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size=hand.size();
        if(size%groupSize) return 0;
        map<int,int>mp;
        for(auto i:hand) mp[i]++;
        while(!mp.empty())
        {
            int curr=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp[i+curr]==0) return false;
                mp[curr+i]--;
                if(mp[curr+i]<1) mp.erase(curr+i);
            }
        

        }
        return true;
    }
};
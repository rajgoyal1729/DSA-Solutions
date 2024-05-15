class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>one;
        vector<int>v;
        int diff;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1) one.push_back(i);
        }
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==0)
            {   
                 diff=INT_MAX;
                for(auto it:one)
                {
                    diff=min(diff,abs(it-i));
                }
            }
            v.push_back(diff);
        }
        return *max_element(v.begin(),v.end());
    }
};
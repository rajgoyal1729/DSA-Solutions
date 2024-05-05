class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        int sum=0;
        int i=0;
        sort(people.begin(),people.end());
        int j=people.size()-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit) 
            {
                i++;
                j--;
            }
            else j--;
            ans++;
            
        }
        return ans;
    
   
   
    }
};
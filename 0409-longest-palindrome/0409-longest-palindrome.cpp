class Solution {
public:
    int longestPalindrome(string s) {
        int len=s.length();
        map<char,int>mp;
        int count=0;
        int mini=INT_MAX;
        for(auto i:s) mp[i]++;
        for(auto it:mp)
        {
            if(it.second%2==0) continue;
            else{
                mini=min(mini,it.second);
                count++;
            }
        }
        if(count==1|| mini==INT_MAX) return len;
        return len-count+1;
    }
};
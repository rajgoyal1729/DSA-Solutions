class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
        int ans=0;
        int right=0,left=0;
        int size= s.length();
        while(right<size)
        {
            char c= s[right];
            mp[c]++;

            while(mp[c]>1)
            {
                char l = s[left++];
                mp[l]--;

            }
            ans =max(ans, right-left+1);
            right++;
        }
            return ans;
        

    }
};
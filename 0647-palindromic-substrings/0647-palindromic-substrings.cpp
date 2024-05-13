class Solution {
public:
    int manacher(string s,int i, int j)
    {
        int count=0;
        while(j<s.length() && i>=0 && s[i]==s[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        // Manacher's Algo
        int ans=0;
        for(int center=0;center<s.length();center++)
        {
            int oddAns=manacher(s,center,center);
            int evenAns=manacher(s,center,center+1);
            ans+=(evenAns+oddAns);
        }
        return ans;
    }
};
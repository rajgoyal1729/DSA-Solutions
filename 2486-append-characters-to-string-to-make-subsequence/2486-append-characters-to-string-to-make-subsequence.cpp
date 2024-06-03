class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=0;
        int len=t.length();
        int lens=s.length();
        int i=0,j=0;
        while(i<lens && j<len)
        {
            if(s[i]==t[j]) 
            {
                i++;
                j++;
            }
            else
            {
                ans=max(ans,j);
                //cout<<ans<<endl;
                i++;
            }
        }
        if(j>=len) return 0;
        ans=max(ans,j);
        return len-ans;
    }
};
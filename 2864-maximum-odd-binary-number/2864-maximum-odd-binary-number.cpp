class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        int count=0;
        int len=s.length();
        for(auto &i:s)
        {
            if(i=='1') count++;
        }
        if(count ==1)
        {
            while(len-1)
            {
                ans+='0';
                len--;
            }
            ans+='1';
            return ans;
        }
        else
        {
            int y=count-1;
            while(y--)
            {
                ans+='1';
            }
            int x=len-count;
            while(x--)
            {
                ans+='0';
                
            }
            ans+='1';
            return ans;
     
        }
        return {};
    }
};
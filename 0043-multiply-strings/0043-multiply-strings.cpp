class Solution {
public:
    /*string multiply_string( char &x, string &nums2)
    {
       /* int n=nums2.size();
        string ans="";
        
        int carry=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int digit=x-'0';
            int numdigit=nums2[i]-'0';
            int cal= numdigit*digit+carry;
            carry=cal/10;
            int dig=cal%10;
            ans=ans+char(dig+'0');
        }
        if(carry)
        {
            ans=ans+char(carry+'0');
        }
         
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    string add_string(string &s1, string &s2)
    {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ans="";
        int carry=0;
        int i=0,j=0;
        while(i<s1.size() && j<s2.size())
        {
            int d1=s1[i]-'0';
            int d2=s2[j]-'0';
            int digit=d1+d2+carry;
            int cal=digit%10;
            carry=digit/10;
            ans=ans+char(cal+'0');
            i++;
            j++;
        }
        while(i<s1.size())
        {
            int d1=s1[i]-'0';
            int digit=d1+carry;
            int cal=digit%10;
            carry=digit/10;
            ans=ans+char(cal+'0');
            i++;
        }
        while(j<s2.size())
        {
            int d2=s2[j]-'0';
            int digit=d2+carry;
            int cal=digit%10;
            carry=digit/10;
            ans=ans+char(cal+'0');
            j++;
        }
        if(carry)
        {
            ans=ans+char(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }*/
    string multiply(string num1, string num2) {
        /*if(num1=="0" || num2=="0")
        return "0";

         
        int n=num2.size();
        string ans= multiply_string(num2[n-1],num1);
        int count=1;
        for(int i=num2.size()-2;i>=0;i--)
        {
            string x= multiply_string(num2[i],num1);
            for(int i=0;i<count;i++)
            
            x.push_back('0');
            ans=add_string(ans,x);
            count++;
            
            
        }
        return ans;*/
        if(num1=="0" || num2=="0") return "0";
        int n=num1.length(),m=num2.length();
        vector<int>num(n+m);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                num[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                num[i+j]+=num[i+j+1]/10;
                num[i+j+1]%=10;
            }
        }
        int i=0;
        while(i<num.size() && num[i]==0) ++i;
        string ans;
        while(i<num.size()) ans.push_back(num[i++]+'0');
        return ans;
    }
};
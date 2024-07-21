class Solution {
public:
    int minChanges(int n, int k) {
        string num, kum;
        while(n)
        {
            char c= n%2+'0';
            num+=c;
            n/=2;
        }
        
        while(k)
        {
            char c= k%2+'0';
            kum+=c;
            k/=2;
        }
        
        int size1=num.length();
        int size2=kum.length();
        if(size1<size2) 
        {
            for(int i=size1;i<size2;i++) num+='0';
        }
        else
        {
            for(int i=size2;i<size1;i++) kum+='0';
        }
        reverse(num.begin(),num.end());
        reverse(kum.begin(),kum.end());
        //cout<<num<<" "<<kum;
        int ans=0;
        for(int i=0;i<num.length();i++)
        {
            if(num[i]=='1' && kum[i]=='0') {ans++;
            num[i]='0';}
        }
        if(num==kum) return ans;
        else return -1;
    }
};
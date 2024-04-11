class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool neg = 0;
        int i=0; 
        while(s[i]==' ') i++;
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') neg = 1;
            i++;
        }
        // we have reached the numeric part
        for(; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                if(!neg && ans>=(pow(2, 31)-1)){
                    ans=pow(2, 31)-1;
                    break;
                }//+2147483648 is invalid
                if(neg && ans>(pow(2, 31))){
                    ans = -1*(pow(2, 31));
                    break;
                }//-2147483648 is valid
                ans*= 10;
                ans += (s[i]-'0');
            }
            else break;
        }
        if(neg && ans>0) ans*=-1;
        if(ans>=pow(2, 31)-1) ans=pow(2, 31)-1;
        if(ans<=(-1*pow(2, 31)-1)) ans=-1*pow(2, 31);
        return ans;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        string ans;
        stack<char>st;
        for(int i=0;i<num.size();i++)
        {
            while(!st.empty() && num[i]<st.top() && k)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(k--) ans.pop_back();
        int start=0;
        //if(ans.size()==1 && ans[0]=='0') return ans;
        while(ans[start]=='0') start++;
        if(start==ans.size()) return "0";
        return ans.substr(start);
    }
};
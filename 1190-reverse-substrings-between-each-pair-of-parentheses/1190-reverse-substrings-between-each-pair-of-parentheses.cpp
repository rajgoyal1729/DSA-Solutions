class Solution {
public:
    string reverseParentheses(string s) {
        // m thak gya hu gin gin k
        stack<char> st;
        string ans;
        for (auto& i : s) {
            if (i != ')')
                st.push(i);
            else {
                string temp="";
                while (!st.empty() && st.top() != '(') {

                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for (auto& i : temp) {
                    st.push(i);
                }
                
            }

        }
        while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
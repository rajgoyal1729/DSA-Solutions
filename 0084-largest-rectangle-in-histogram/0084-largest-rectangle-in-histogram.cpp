class Solution {
public:
    vector<int>pse(vector<int>&heights)
    {
        vector<int>ans(heights.size(),-1);
        stack<int>st;
        int size=heights.size();
        for(int i=0;i<size;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nse(vector<int>&heights)
    {
        vector<int>ans(heights.size(),heights.size());
        stack<int>st;
        int size=heights.size();
        for(int i=size-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        vector<int>nse1=nse(heights);
        vector<int>pse1=pse(heights);
        int size=heights.size();
        for(int i=0;i<size;i++)
        {
            ans=max(ans,heights[i]*(nse1[i]-pse1[i]-1));
        }
        return ans;
    }
};
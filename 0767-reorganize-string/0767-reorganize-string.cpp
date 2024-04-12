class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        int len=s.length();
        for(auto &i:s) mp[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        
        if(pq.top().first>(len+1)/2) return "";
        string ans;
        while(pq.size()>1)
        {
            
            int f1=pq.top().first;
            char c1=pq.top().second;
            //cout<<c1<<" "<<f1<<endl;
            pq.pop();
           
            char c2=pq.top().second;
            int f2=pq.top().first;
            //cout<<c2<<" "<<f2<<endl;
            pq.pop();
            if(f1-1) pq.push({f1-1,c1});
            if(f2-1) pq.push({f2-1,c2});
            
            ans.push_back(c1);
            ans.push_back(c2);
        }
        if(pq.size()) {ans.push_back(pq.top().second); pq.pop();}
        return ans;

    }
};
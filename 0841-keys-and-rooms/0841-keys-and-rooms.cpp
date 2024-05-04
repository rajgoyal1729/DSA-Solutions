class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[node]=1;
        for(auto &i:adj[node])
        {
            if(!vis[i])
            dfs(i,vis,adj);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size());
        dfs(0,vis,rooms);
        for(auto &i:vis) if(i==0) return false;
        return true;
    }
};
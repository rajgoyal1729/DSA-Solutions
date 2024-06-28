class Solution {
public:
    int singleNumber(vector<int>& A) {
        int ans=0;
    for(auto &i:A) ans^=i;
    return ans;
    }
};
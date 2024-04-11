class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string>set;
        
        int size=s.length();
        if(size<k) return false;
        for(int i=0;i<=size-k;i++)
        {
            set.insert(s.substr(i,k));
        }
        return set.size()==(1<<k);
        

    }
};
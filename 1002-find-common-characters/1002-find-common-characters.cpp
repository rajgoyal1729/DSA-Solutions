class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        vector<int>hash1(26);
        vector<int>hash2(26);
        for(auto &c:words[0])
        hash1[c-'a']++;
        for(int i=1;i<words.size();i++)
        {
            for(auto &c: words[i]) hash2[c-'a']++;
        
        for(int i=0;i<26;i++)
        {
            hash1[i]=min(hash1[i],hash2[i]);
            hash2[i]=0;
        }
        }
        for(int i=0;i<26;i++)
        {
            if(hash1[i]>=0)
            {
                while(hash1[i]--)
                {
                    char c=i+'a';
                    string s;
                    s= c;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};


  
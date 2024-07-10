class Solution {
public:
    int minOperations(vector<string>& logs) {
        string remain="./";
        string back="../";
        string move="/";
        int count=0;
        for(string s:logs)
        {
            if(s.find(back)!=string::npos) count=max(0,count-1);
            else if(s.find(remain)!=string::npos) count=count;
            else count++;
        }
        if(count<0) return 0;
        return count;
    }
};
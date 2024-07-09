class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<double>time;
        double sum=customers[0][0];
        for(int i=0;i<customers.size();i++)
        {
            if(sum>=customers[i][0]){sum+=customers[i][1];
            int x=sum-customers[i][0];
            time.push_back(x);}
            else
            {
                sum=customers[i][0]+customers[i][1];
                time.push_back(customers[i][1]);
            }
        }
        double add=0;
        for(auto &i:time) add+=i;
        //cout<<add<<endl;
        //cout<<time.size();
        return (double) add/time.size(); 
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        //vector<int>ans(A.size());
        for(int i=A.size()-1;i>=0;i--)
        {
            if(i==A.size()-1)
            
                A[i]++;
                if(A[i]==10)
                {
                    A[i]=0;
                    if(i!=0)
                    {
                        A[i-1]++;
                    }
                    else
                    {
                        A[i]=1;
                        A.push_back(0);
                    }
                }
                
            
        }
        return A;
    }
};
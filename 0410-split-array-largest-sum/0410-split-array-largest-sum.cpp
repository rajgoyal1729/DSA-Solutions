class Solution {
public:
    //#include<bits/stdc++.h>
bool isValid(vector<int>&A,int B,int mid)
{
    int count=1;
    int sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum>mid){ count++;
        sum=A[i];
        }
    }
    return count<=B;
}

    int splitArray(vector<int>& A, int B) {
        int minPage= *max_element(A.begin(),A.end());
    int sum=accumulate(A.begin(),A.end(),0);
    int low=minPage;
    int high=sum;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(isValid(A,B,mid))
        {
            high=mid;
        }
        else low=mid+1;
    }
    return low;
    }
};
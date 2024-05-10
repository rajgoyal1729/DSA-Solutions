class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int size=arr.size();
        double left=0.0,right=1.0;
        while(left<right)
        {
            double mid= (left+right)/2;

            double maxfrac=0.0;
            int totalsmallfrac=0,numIdx=0, denIdx=0;
            int j=1;

            for(int i=0;i<size-1;i++)
            {
                while(j<size && arr[i]>=mid*arr[j]) j++;
                totalsmallfrac+= (size-j);
                if(j==size) break;
                double frac= (double) arr[i]/arr[j];
                if(frac>maxfrac) 
                {
                    maxfrac=frac;
                    numIdx=i;
                    denIdx=j;
                }
            }
                if(totalsmallfrac==k) return {arr[numIdx], arr[denIdx]};
                else if(totalsmallfrac<k)
                {
                    left=mid;
                }
                else right=mid;
            }
            
        
        return {};
        
    }
};
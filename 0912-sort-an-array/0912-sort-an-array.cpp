class Solution {
public:
// merge sort method 
        void merge(vector<int>&nums,int start,int mid,int end)
        {
            vector<int>left(mid-start+1);
            vector<int>right(end-mid);
            for(int i=0;i<mid-start+1;i++)
            {
                left[i]=nums[start+i];
            }
            for(int i=0;i<end-mid;i++)
            {
                right[i]=nums[mid+1+i];
            }
            int i=0,j=0,k=start;
            while(i<mid-start+1 && j<end-mid)
            {
                if(left[i]<=right[j])
                {
                    nums[k++]=left[i++];
                }
                else
                {
                    nums[k++]=right[j++];
                }
            }
            while(i<mid-start+1)
            {
                nums[k++]=left[i++];
            }
            while(j<end-mid)
            {
                nums[k++]=right[j++];
            }
        }
        void mergeSort(vector<int>&nums,int start,int end)
        {
            if(start>=end) return;
            int mid= start+(end-start)/2;
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
       
        mergeSort(nums,0,n-1);
        return nums;
    }
};
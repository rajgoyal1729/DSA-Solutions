class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // it uses time complexity of m+n(log(n+m))
        /*double ans;
        int size2= nums2.size();
        for(int i=0;i<size2;i++)
        nums1.push_back(nums2[i]);

        sort(nums1.begin(),nums1.end());
        int size1=nums1.size();
        if(size1%2==0)
        {
           ans= (nums1[size1/2]+nums1[size1/2 - 1])/2.0; 
        }
        else
        ans= nums1[size1/2];

        return ans;
        }*/
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            // Partition index for nums1
            int partitionA = (left + right) / 2;
            // Calculate partition index for nums2 based on the total length of both arrays
            int partitionB = (m + n + 1) / 2 - partitionA;
            
            // Calculate the maximum and minimum values on the left and right sides of the partitions
            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];
            
            // Check if the current partitions are the correct partitions
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // Calculate the median based on whether the total length is even or odd
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                // Adjust the partition for nums1 to move left
                right = partitionA - 1;
            } else {
                // Adjust the partition for nums1 to move right
                left = partitionA + 1;
            }
        }
        
        return 0.0; // Default return (shouldn't be reached in a valid case)
    }
    };

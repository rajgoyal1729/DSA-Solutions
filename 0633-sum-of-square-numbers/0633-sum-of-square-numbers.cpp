class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=0,right=sqrt(c);
        while(left<=right)
        {
            if(c<(left*left+right*right)) right--;
            else if(c>(left*left+right*right)) left++;
            else return true;
        }
        return false;
    }
};
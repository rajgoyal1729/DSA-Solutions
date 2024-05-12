class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0;
        int steps=0;
        while(sum<target)
        {
            steps++;
            sum+=steps;
        }
        int d=sum-target;
        if(d%2==0) return steps;
        while((sum-target)%2)
        {
            
            steps++;
            sum+=steps;
        }
        return steps;
        
    }
};
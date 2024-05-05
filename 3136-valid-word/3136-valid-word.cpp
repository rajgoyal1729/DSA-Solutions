class Solution {
public:
    bool isValid(string word) {
        int len=word.length();
        
        bool flag=0;
        int countV=0,countC=0,countD=0;
        int special=0;
        int countUV=0, countUC=0,countLC=0,countLV=0;
        for(auto &i:word)
        {
            flag=0;
            if(i>='0' && i<='9') {countD++; continue;}
            if(i=='A'  ||i=='E'||i=='I'|| i=='O'|| i=='U') {countV++; flag=1;countUV++;}
            else if(i=='a' || i=='e'|| i=='i' || i=='o' || i=='u') {countV++; flag=1 ; countLV++;}
            else if(i>'A' && i<='Z' && flag==0){ countC++; countUC++; }
            else if(i>'a' && i<='z' && flag==0) { countC++; countLC++;}
            else{ special++; len--;}
            
        }
        int countU;
        countU=countUC+ countUV;
        cout<<countD<<" "<<countC<<" "<<countV<<" "<<special;
       
         return (countD || countU) &&  (countC && countV) && special==0 && len>=3;
    }
};
class Solution {
public:
    bool isHappy(int n) {
        int new_num,num,rem;
        while(n>9){
            new_num=0;
            num=n;
            while(num){
                rem=num%10;
                new_num+=rem*rem;
                num/=10;
            }
            n=new_num;
        }
        if(n==1||n==7)
        return true;

        return false;
    }
};
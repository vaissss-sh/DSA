class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return bool(false);
        }
        if(x==0){
            return bool(true);
        }
        int rev_num=0;
        int n=x;
        while(x>0){
            if(rev_num > INT_MAX/10 || rev_num < INT_MIN/10){
                return bool(false);
            }
            int last_digit=x%10;
            x/=10;
            rev_num=(rev_num*10)+last_digit;
        }
        if(n==rev_num){
            return bool(true);
        }
        else 
        return bool(false); 

    }
};
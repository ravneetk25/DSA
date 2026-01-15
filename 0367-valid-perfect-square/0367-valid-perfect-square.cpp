class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int n = 2;
        while(num/n >= n)
        {
            if(num/n == n && num%n == 0)
                return true;
            if(num/n < n)
                break;
            ++n;
        }
        return false;
    }
};
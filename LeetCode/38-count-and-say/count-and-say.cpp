class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string prev = countAndSay(n-1);
        int count = 1 , i = 1;
        string res = "";
        for( i = 1 ; i < prev.size() ; i++){
            if(prev[i-1] == prev[i]) count++;
            else{
                res += '0' + count;
                res += prev[i-1];
                count=1;
            }
        }
        res += '0' + count;
        res += prev[i-1];

        return res;
    }
};
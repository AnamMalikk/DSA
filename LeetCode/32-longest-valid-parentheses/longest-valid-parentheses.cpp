class Solution {
public:
    int longestValidParentheses(string s) {
        // left to right
        int opening = 0;
        int closing = 0;
        int maxLen = 0;
        int startIdx = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                opening++;
            }
            else {
                closing++;
            }

            if(opening == closing) {
                int len = i-startIdx+1;
                maxLen = max(maxLen, len);
            }

            if(closing > opening) {
                startIdx = i+1;
                opening = 0;
                closing = 0;
            }
        }

        // right to left
        opening = 0;
        closing = 0;
        startIdx = s.size()-1;
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == ')') {
                opening++;
            }
            else {
                closing++;
            }

            if(opening == closing) {
                int len = startIdx-i+1;
                maxLen = max(maxLen, len);
            }

            if(closing > opening) {
                startIdx = i-1;
                opening = 0;
                closing = 0;
            }
        }

        return maxLen;
    }
};
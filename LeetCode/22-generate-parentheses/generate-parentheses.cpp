class Solution {
    vector<string> ret;
    

void generate(int idx, int cntOpen, int cntClose, int& n, int mask){
        if(cntOpen + cntClose == 2*n)
        {
            string s = "";
            for(int i = 0; i < idx; i++) 
                s += (mask & (1 << i))? '(':')';

            ret.push_back(s);
            return;
        }

        if(cntOpen < n)
            generate(idx+1, cntOpen+1,cntClose,n, mask | (1<<idx));
        
        if(cntClose < n && cntClose < cntOpen)
            generate(idx+1, cntOpen,cntClose+1,n,mask);
        

    }

public:
    vector<string> generateParenthesis(int n) {
        generate(0,0,0,n,0);
        return ret;
    }
};
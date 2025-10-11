class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++){
            if(um.find(s[i])!=um.end()){
                um[s[i]]++;
            }
            else{
                um[s[i]]=1;
            }
        }

        for(int i=0;i<t.length();i++){
            if(um.find(t[i])!=um.end()){
                um[t[i]]--;
            }
            else{
                return false;
            }
        }

        for (auto &p : um) {
            if(p.second!=0){
                return false;
            }
        }
        return true;
    }
};
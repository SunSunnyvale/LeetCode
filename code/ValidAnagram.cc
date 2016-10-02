class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.empty() && t.empty()){
            return true;
        }
        int len=s.length();
        if(len != t.length()){
            return false;
        }
        vector<int> a(26,0);
        for(int i=0;i<len;i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=0){
                return false;
            }
        }
        return true;
        
    }
};
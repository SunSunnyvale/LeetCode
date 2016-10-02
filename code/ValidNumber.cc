

class Solution {
    static vector<unordered_map<char, int> > DFA;
public:
    bool isNumber(string s) {
        int current_stat = 1;
        for(int i = 0; i < s.size(); i++) {
            char type;
            if(s[i] == ' ') {
                type = 'b';
            } else if(s[i] >= '0' && s[i] <= '9') {
                type = 'n';
            } else if(s[i] == 'e') {
                type = 'e';
            } else if(s[i] == '.') {
                type = 'd';
            } else if(s[i] == '+' || s[i] == '-') {
                type = 's';
            } else {
                return false;
            }
            current_stat = DFA[current_stat][type];
        }
        if(current_stat == 3 || current_stat == 5 || current_stat == 8 || current_stat == 9) {
            return true;
        }
        return false;
    }
};

/**
* Init DFA,
* where DFA[i] represent the qi state in DFA transition
* and DFA[i][ch] means the state we should go to when come up with character ch
*/
vector<unordered_map<char, int> > Solution::DFA = {
    {{}},
    {{'b',1},{'s',2},{'n',3},{'d',4}},
    {{'n',3},{'d',4}},
    {{'n',3},{'d',5},{'e',6},{'b',9}},
    {{'n',5}},
    {{'n',5},{'e',6},{'b',9}},
    {{'n',8},{'s',7}},
    {{'n',8}},
    {{'n',8},{'b',9}},
    {{'b',9}}
};

class Solution {
public:
    string fun(string str) {
        string res = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '#') {
                if (res.length() > 0)
                    res.erase(res.size() - 1, 1);
            }
            else
                res.push_back(str[i]);
        }
        return res;
    }
    
    bool backspaceCompare(string S, string T) {
        S = fun(S);
        T = fun(T);
        
        int s_length = (int)S.length();
        int t_length = (int)T.length();
        
        if(s_length != t_length)
            return false;
        
        if(s_length == 0 && t_length == 0)
            return true;
        
        
        for (int i = 0; i < s_length; i++) {
            if(S[i] != T[i])
                return false;
        }
        
        return true;
        
    }
};

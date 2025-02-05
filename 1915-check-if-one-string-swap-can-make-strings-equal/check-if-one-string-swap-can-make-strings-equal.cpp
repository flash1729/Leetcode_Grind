class Solution {
public:
    string swapChar(string s,int i,int j){
        swap(s[i],s[j]);
        return s;
    }

    bool areAlmostEqual(string s1, string s2) {
    string test;

    for(int i = 0;i < s1.length();i++){
        test = s1;
        for(int j = 0; j < s1.length();j++){
            
            test = swapChar(s1,i,j);

            if(test == s2){
                return true;
            }
        }
    }
    
    return false;
    }
};
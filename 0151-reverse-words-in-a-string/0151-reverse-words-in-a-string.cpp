class Solution {
public:
    string reverseWords(string s) {
        string result = "",temp = "";
        int len = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == ' ' && len == 0)
                continue;
            else if(s[i] == ' ' && len != 0){
                result = temp + " " + result; 
                len = 0;
                temp = "";
            }
            else{
                temp = temp + s[i];
                len++;
            }
        }
    

    if(temp != ""){
    result = temp + " " + result;
    }

    int n = result.size();
    return result.substr(0,n-1);
    }
};
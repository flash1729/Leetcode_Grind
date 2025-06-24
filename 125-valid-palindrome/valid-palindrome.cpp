class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";


        for(int i = 0; i < s.length();i++){
            char a = s[i];
            if(isalnum(a)){
                if(!isdigit(a)){
                    a = tolower(a);
                }
                temp.push_back(a);
            }
        }
        
        string temp2 = temp;

        reverse(temp.begin(),temp.end());

        if(temp == temp2){
            return true;
        }

        return false;
    }
};
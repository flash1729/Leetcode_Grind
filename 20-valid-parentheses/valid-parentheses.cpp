class Solution {
public:
    bool isValid(string s) {
        stack<char> track;

        for(char a : s){
            if(a == '(' || a == '[' || a == '{'){
                track.push(a);
            }
            else{
                if(track.empty()){
                    return false;
                }
                char temp = track.top();
                switch(a){
                    case ')':
                        if(temp == '('){
                            track.pop();
                        }else{
                            track.push(a);
                        }
                        break;
                    case ']':
                        if(temp == '['){
                            track.pop();
                        }else{
                            track.push(a);
                        }
                        break;
                    case '}':
                        if(temp == '{'){
                            track.pop();
                        }else{
                            track.push(a);
                        }
                        break;
                    default:
                        track.push(a);
                }
            }
        }

        if(track.empty())
            return true;

        return false;
    }
};
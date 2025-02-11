class Solution {
public:
    string cutPart(string s,int pos,int len){
        string res = s.substr(0, pos);
        res = res + s.substr(pos + len, s.length());

        return res;
    }

    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            int pos = s.find(part);
            cout<<pos<<endl;
            s = cutPart(s,pos,part.length());
            cout<<s<<endl;
        }

        return s;
    }
};
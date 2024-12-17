class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repeats = ceil(static_cast<double>(b.size()) / a.size());
        cout<<repeats<<" "<<b.size() / a.size()<<" "<<b<<endl;
        string repeated = "";
        for(int i = 0;i < repeats;i++){
            repeated += a;
        }

        if(repeated.find(b) != string::npos){
            return repeats;
        }

        repeated += a;
        cout<<repeats + 1<<endl;
        if(repeated.find(b) != string::npos){
            return repeats + 1;
        }

        return -1;
    }
};
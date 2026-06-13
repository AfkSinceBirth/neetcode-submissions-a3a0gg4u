class Solution {
public:
    //#123#<string>#0#
    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs){
            int n = s.size();
            string sizeEncoding = "#" + to_string(n) + "#";
            ans += sizeEncoding;
            ans += s;
        }
        ans += "#0#";
        return ans;
    }

    vector<string> decode(string s) {
        bool readString = true;
        vector<string> ans;
        string str = "";
        int k = 0;
        bool ignoreFirst = true;
        for(char c: s){
            if(c=='#' && k==0) {
                readString = !readString;
                if(readString){
                    k = stoi(str);
                }
                else {
                    if(!ignoreFirst) ans.push_back(str);
                    else ignoreFirst = !ignoreFirst;
                    k=0;
                }
                str = "";
                continue;
            }
            str += c;
            if(k) k--;
        }
        return ans;
    }
};

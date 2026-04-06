class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            string lenStr = to_string(s.size());
            string prefix = string(3 - lenStr.size(), '0') + lenStr;
            encoded += prefix + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = s.size();

        while (i < n) {
            string lenStr = s.substr(i, 3);
            int len = stoi(lenStr);
            i += 3; 
            string content = s.substr(i, len);
            result.push_back(content);
            i += len;
        }
        
        return result;
    }
};
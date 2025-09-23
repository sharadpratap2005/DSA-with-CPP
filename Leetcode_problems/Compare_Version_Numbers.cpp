class Solution {
public:
    vector<string> getTokens(string& v) {
        // store the tokens as a string in vector t and return it.
        vector<string> t;
        stringstream s(v);
        string token;
        while (getline(s, token, '.')) {
            t.push_back(token);
        }
        return t;
    }
    int compareVersion(string version1, string version2) {
        /*In this problem we will use the stringstream to deliminate the string
          in various tokens based on '.'  We will store the tokens of string
          in vector and compare them for version1 and version2*/
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);
        int n1 = v1.size();
        int n2 = v2.size();
        int n = max(n1, n2);
        // now compare the v1 and v2
        for (int i = 0; i < n; i++) {
            int a = (i < n1 ? stoi(v1[i]) : 0);
            int b = (i < n2 ? stoi(v2[i]) : 0);
            if (a < b)
                return -1;
            if (a > b)
                return 1;
        }
        return 0;
    }
};

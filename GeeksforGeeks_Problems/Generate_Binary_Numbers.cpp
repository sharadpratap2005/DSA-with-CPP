class Solution {
  public:
string toBinary(int n) {
    bitset<32> b(n);
    string s = b.to_string();
    // remove leading zeros
    s.erase(0, s.find_first_not_of('0'));
    return s.empty() ? "0" : s;
}
    vector<string> generateBinary(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            ans.push_back(toBinary(i));
        }
        return ans;

    }
};

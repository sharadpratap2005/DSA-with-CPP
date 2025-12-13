/*This is a easy problem and straightforward. Tricky part in this problem is to sort the final answers based on the given condition in problem. for this we used priority queue and pair vector array to sort the final answers using sorting compartor. */

class Solution {
public:
    // check if the code[i] string is valid alphanumeric
    bool check_code(string& s) {
        if (s.empty())
            return false;

        for (auto ch : s) {
            if (isalnum(ch) || ch == '_')
                continue;
            else
                return false;
        }
        return true;
    }
    // check if the businessLine[i] is valid category
    bool check_businessLine(string& s) {
        if (s == "electronics" || s == "grocery" || s == "pharmacy" ||
            s == "restaurant")
            return true;

        return false;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        // declare the pair vector array for store businessline[i] and code[i]
        // that are valid
        vector<string> ans;
        vector<pair<string, string>> v;
        for (int i = 0; i < n; i++) {
            if (check_code(code[i]) && check_businessLine(businessLine[i]) &&
                isActive[i]) {
                v.push_back({businessLine[i], code[i]});
            }
        }
        // Now according thw given problem we have to sort the valid coupons
        // based on given condition

        // declare priority queue
        unordered_map<string, int> priority;
        priority["electronics"] = 0;
        priority["grocery"] = 1;
        priority["pharmacy"] = 2;
        priority["restaurant"] = 3;

        // now sort based on priority
        sort(v.begin(), v.end(),
             [&](pair<string, string>& a, pair<string, string>& b) {
                 if (a.first != b.first)
                     return priority[a.first] < priority[b.first];

                 return a.second < b.second;
             });

        for (auto& it : v) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

class Solution {
public:
    // alice will always win except vowel count is zero in a string
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    bool doesAliceWin(string s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i]))
                count++;
        }
        if (count == 0)
            return false;

        return true;
    }
};

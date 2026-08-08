class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> hash1;
        unordered_map<char, char> hash2;
        for (int i = 0; i < s.size(); i++) {
            if (hash1.find(s[i]) == hash1.end() &&
                hash2.find(t[i]) == hash2.end()) {
                hash1[s[i]] = t[i];
                hash2[t[i]] = s[i];
            } else if (t[i] == hash1[s[i]]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
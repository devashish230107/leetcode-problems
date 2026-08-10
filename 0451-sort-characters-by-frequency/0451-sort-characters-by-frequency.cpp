class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        string ans;
        for (int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
        }
        char maxChar;
        int maxVal = 0;
        while (!hash.empty()) {
            char maxChar;
            int maxVal = 0;
            for (auto it : hash) {
                if (it.second > maxVal) {
                    maxVal = it.second;
                    maxChar = it.first;
                }
            }
            for (int i = 0; i < maxVal; i++) {
                ans += maxChar;
            }
            hash.erase(maxChar);
        }
        return ans;
    }
};
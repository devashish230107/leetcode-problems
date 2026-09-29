class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorr ^= nums[i];
        }
        int rightmostone = (xorr & xorr - 1) ^ xorr;
        int b1 = 0, b2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((rightmostone & nums[i]) == 0) {
                b1 ^= nums[i];
            } else {
                b2 ^= nums[i];
            }
        }
        return {b1, b2};
    }
};
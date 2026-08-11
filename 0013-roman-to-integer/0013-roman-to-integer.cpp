class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char, int> store = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};                           
        for (int i = n-1; i >=0; i--) {
            int val=store[s[i]];
            if(i!=n-1 && store[s[i+1]]>store[s[i]]){
                ans-=val;
            }
            else{
                ans+=val;
            }
        }
        return ans;
    }
};
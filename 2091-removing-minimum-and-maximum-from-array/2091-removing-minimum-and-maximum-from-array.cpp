class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxelement=INT_MIN;
        int minelement=INT_MAX;
        int minindex=-1;
        int maxindex=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxelement){
                maxelement=nums[i];
                maxindex=i;
            }
            if(nums[i]<minelement){
                minelement=nums[i];
                minindex=i;
            }
        }  
        maxelement=max(maxindex,minindex);
        minelement=min(maxindex,minindex);
        return min(min(minelement+1+n-maxelement,maxelement+1),n-minelement);
    }
};
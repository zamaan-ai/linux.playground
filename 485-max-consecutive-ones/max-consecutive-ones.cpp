class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxcount = 0;
    int currentcount = 0;

    for (int i =0; i < nums.size(); i++){
        if(nums[i]==1){
            currentcount++;
            if(currentcount>maxcount){
                maxcount=currentcount;
            }
        }
        else{
            currentcount = 0;
        }
    }
    return maxcount;
    }
};
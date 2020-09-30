class Solution {
public:    
    int firstMissingPositive(vector<int>& nums) {
        vector<int> visit(nums.size() + 2);
        int temp = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0)
                continue;
            
            if(nums[i] <= nums.size()){
                visit[nums[i]] = 1;
            }
            
        }
        
        for(int i = 1; i < nums.size() + 2; i++){
            if(visit[i] == 0)
                return i;
        }
        
        return temp;
    }
};
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort( nums.begin(), nums.end() );
        
        int sum {};
        for( size_t i { 0 }; i < nums.size(); i += 2 )
        {
            sum += nums[i];
        }
        
        return sum;
    }
};
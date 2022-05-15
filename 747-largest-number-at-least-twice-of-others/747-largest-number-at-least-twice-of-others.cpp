class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex {};
        for( auto i { 0 }; i < nums.size(); ++i )
        {
            if( nums[i] > nums[maxIndex] )
            {
                maxIndex = i;
            }
        }
        
        for( auto i { 0 }; i < nums.size(); ++i )
        {
            if( (i != maxIndex) && (nums[i] * 2 > nums[maxIndex]) )
            {
                maxIndex = -1;
                break;
            }
        }
        
        return maxIndex;
    }
};
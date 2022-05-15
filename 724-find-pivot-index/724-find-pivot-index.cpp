class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        // The sum of all elements
        int totalSum {}; 
        for( auto const& num : nums )
        {
            totalSum += num;
        }
        
        // Find the pivot index
        int pivotIndex { -1 };
        int leftSum    {};
        for( auto i { 0 }; i < nums.size(); ++i )
        {
            if( i > 0 )
            {
                leftSum += nums[i-1];
            }
            
            auto const rightSum { totalSum - leftSum - nums[i] };
            
            if( leftSum == rightSum )
            {
                pivotIndex = i;
                break;
            }
        }
        
        return pivotIndex;
    }
};
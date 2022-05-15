class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i { 0 };
        int j { (int)numbers.size() - 1 };
        
        while( i < j )
        {
            int sum { numbers[i] + numbers[j] };
            
            if( sum == target )
            {
                break;
            }
            else if( sum > target )
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        
        return { i + 1, j + 1 };
    }
};
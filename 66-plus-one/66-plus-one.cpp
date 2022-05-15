class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Go through the digits from the back to add 1
        bool carryOver {};
        for( size_t i { digits.size() - 1 }; i != -1; --i )
        {
            auto const incrementedVal { digits[i] + 1 };
            if( incrementedVal == 10 )
            {
                carryOver = true;
                digits[i] = 0;
            }
            else
            {
                carryOver = false;
                digits[i] = incrementedVal;
                break;
            }
        }
        
        if( carryOver )
        {
            digits.insert( digits.begin(), 1 );
        }
        
        return digits;
    }
};
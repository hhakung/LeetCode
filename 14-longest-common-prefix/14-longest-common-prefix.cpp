class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix {};
        
        auto shortestLength { strs[0].length() };
        for( auto const& str : strs )
        {
            auto const length { str.length() };
            if( length < shortestLength )
            {
                shortestLength = length;
            }
        }
        
        for( size_t i { 0 }; i < shortestLength; ++i )
        {
            bool areEqual { true };
            char character { strs[0][i] };
            for( size_t j { 1 }; j < strs.size(); ++j )
            {
                if( strs[j][i] != character )
                {
                    areEqual = false;
                    break;
                }
            }
            
            if( (prefix.length() == i) && areEqual )
            {
                prefix += character;
            }
            else
            {
                break;
            }
        }
        
        return prefix;
    }
};
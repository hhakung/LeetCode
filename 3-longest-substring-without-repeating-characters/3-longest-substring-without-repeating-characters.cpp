class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLength { 0 };
        for( auto i { 0 }; i < s.length(); ++i )
        {
            string tempSubstring { s[i] };
            
            if( i != s.length() - 1 )
            {
                for( auto j { i + 1 }; j < s.length(); ++j )
                {
                    if( tempSubstring.find( s[j] ) == std::string::npos )
                    {
                        tempSubstring += s[j];
                        
                        if( tempSubstring.length() > longestLength )
                        {
                            longestLength = tempSubstring.length();
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if( tempSubstring.length() > longestLength )
                {
                    longestLength = tempSubstring.length();
                }
            }
        }
        
        return longestLength;
    }
};
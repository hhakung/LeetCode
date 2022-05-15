class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle.length() == 0 )
        {
            return 0;
        }
        
        auto const found { haystack.find( needle ) };
        
        if( found != std::string::npos )
        {
            return (int)found;
        }
        else
        {
            return -1;
        }
    }
};
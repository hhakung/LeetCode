class Solution {
public:
    vector<string> GetNeighboringStrings( string const& currentString, std::set<string> const& deadEndsStrings )
    {
        vector<string> neighboringStrings {};
        
        int firstDigit  { currentString[0] - '0' };
        int secondDigit { currentString[1] - '0' };
        int thirdDigit  { currentString[2] - '0' };
        int fourthDigit { currentString[3] - '0' };
        
        string temp1 { std::to_string( (firstDigit == 0) ? 9 : (firstDigit - 1) ) };
        temp1 += currentString.substr( 1, 3 );
        if( deadEndsStrings.find( temp1 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp1 );
        }
        
        string temp2 { std::to_string( (firstDigit == 9) ? 0 : (firstDigit + 1) ) };
        temp2 += currentString.substr( 1, 3 );
        if( deadEndsStrings.find( temp2 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp2 );
        }
        
        string temp3 { currentString[0] };
        temp3 += { std::to_string( (secondDigit == 0) ? 9 : (secondDigit - 1) ) };
        temp3 += currentString.substr( 2, 2 );
        if( deadEndsStrings.find( temp3 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp3 );
        }
        
        string temp4 { currentString[0] };
        temp4 += { std::to_string( (secondDigit == 9) ? 0 : (secondDigit + 1) ) };
        temp4 += currentString.substr( 2, 2 );
        if( deadEndsStrings.find( temp4 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp4 );
        }
        
        string temp5 { currentString.substr( 0, 2 ) };
        temp5 += { std::to_string( (thirdDigit == 0) ? 9 : (thirdDigit - 1) ) };
        temp5 += currentString[3];
        if( deadEndsStrings.find( temp5 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp5 );
        }
        
        string temp6 { currentString.substr( 0, 2 ) };
        temp6 += { std::to_string( (thirdDigit == 9) ? 0 : (thirdDigit + 1) ) };
        temp6 += currentString[3];
        if( deadEndsStrings.find( temp6 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp6 );
        }
        
        string temp7 { currentString.substr( 0, 3 ) };
        temp7 += { std::to_string( (fourthDigit == 0) ? 9 : (fourthDigit - 1) ) };
        if( deadEndsStrings.find( temp7 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp7 );
        }
        
        string temp8 { currentString.substr( 0, 3 ) };
        temp8 += { std::to_string( (fourthDigit == 9) ? 0 : (fourthDigit + 1) ) };
        if( deadEndsStrings.find( temp8 ) == deadEndsStrings.end() )
        {
            neighboringStrings.push_back( temp8 );
        }
        
        return neighboringStrings;
    }
    
    int openLock(vector<string>& deadends, string target) {
        std::set<string> deadEndsStrings {};
        for( auto const& deadend : deadends )
        {
            deadEndsStrings.insert( deadend );
        }
        
        std::queue<string> stringsToLookAt {};
        std::set<string> visitedStrings {};
        int numTurns { 0 };
        
        if( deadEndsStrings.find( "0000" ) != deadEndsStrings.end() )
        {
            return -1;
        }
        
        stringsToLookAt.push( "0000" );
        visitedStrings.insert( "0000" );
        
        while( !stringsToLookAt.empty() )
        {
            auto const queueSizeAtThisPoint { (int)stringsToLookAt.size() };
            for( auto i { 0 }; i < queueSizeAtThisPoint; ++i )
            {
                auto const currentString { stringsToLookAt.front() };
                if( currentString == target )
                {
                    return numTurns;
                }
                
                // Get the neighboring strings
                auto const neighboringStrings { GetNeighboringStrings( currentString, deadEndsStrings ) };
                
                for( auto const& neighbor : neighboringStrings )
                {
                    if( visitedStrings.find( neighbor )  == visitedStrings.end() )
                    {
                        stringsToLookAt.push( neighbor );
                        visitedStrings.insert( neighbor );
                    }
                }
                
                stringsToLookAt.pop();
            }
            
            ++numTurns;
        }

        return -1;
    }
};
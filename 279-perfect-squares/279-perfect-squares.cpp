class Solution {
public:
    void GetNeighboringIntegers( int const currentInteger, std::queue<int>& integersQueue )
    {
        for( int i { 1 }; i <= currentInteger / 2; ++i )
        {
            if( sqrt( i ) == (int)( sqrt( i ) ) )
            {
                integersQueue.push( currentInteger - i );
            }
        }
    }
    
    int numSquares(int n) {
        std::queue<int> integersQueue {};
        integersQueue.push( n );
        auto numAdditions { 0 };
        
        while( !integersQueue.empty() )
        {
            auto const currentQueueSize { (int)integersQueue.size() };
            
            for( auto i { 0 }; i < currentQueueSize; ++i )
            {
                auto const currentInteger { integersQueue.front() };
                if( sqrt( currentInteger ) == (int)( sqrt( currentInteger ) ) )
                {
                    return numAdditions + 1;
                }
                
                GetNeighboringIntegers( currentInteger, integersQueue );
                integersQueue.pop();
            }
            
            ++numAdditions;
        }
        
        return -1;
    }
};
class Solution {
public:
    void checkNeighboringNodes( vector<vector<char>>& grid, 
                               int const numRows, 
                               int const numCols, 
                               int const i, 
                               int const j )
    {
        if( grid[i][j] == '0' )
        {
            return;
        }
        
        grid[i][j] = '0';
        
        if( i > 0 )
        {
            checkNeighboringNodes( grid, numRows, numCols, i - 1, j );
        }
        
        if( i < numRows - 1 )
        {
            checkNeighboringNodes( grid, numRows, numCols, i + 1, j );
        }
        
        if( j > 0 )
        {
            checkNeighboringNodes( grid, numRows, numCols, i, j - 1 );
        }
        
        if( j < numCols - 1 )
        {
            checkNeighboringNodes( grid, numRows, numCols, i, j + 1 );
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islandsCount {};
        
        auto const numRows { (int)grid.size() };
        auto const numCols { (int)grid[0].size() };
        for( auto i { 0 }; i < numRows; ++i )
        {
            for( auto j { 0 }; j < numCols; ++j )
            {
                // go through the neigboring nodes
                if( grid[i][j] == '1' )
                {
                    checkNeighboringNodes( grid, numRows, numCols, i, j );
                    ++islandsCount;
                }
            }
        }
        
        return islandsCount;
    }
};
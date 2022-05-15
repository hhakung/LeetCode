class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result {};
        
        int const numRows  { (int)(mat.size())     };
        int const numCols  { (int)(mat[0].size())  };
        int const numHeads { numRows + numCols - 1 };
        
        bool goingUpwards { true };
        int  headCount    {};
        int  rowIdx { 0 };
        int  colIdx { 0 };
        while( headCount < numHeads )
        {
            if( goingUpwards )
            {
                // store the current element
                result.push_back( mat[rowIdx][colIdx] );
                
                if( (rowIdx == 0) && (colIdx < numCols) && (colIdx + 1 < numCols) )
                {
                    // if the top row has been reached, go right
                    ++colIdx;
                        
                    // flip the direction
                    goingUpwards = false;
                    
                    // increase the headCount
                    ++headCount;
                }
                else if( (colIdx == numCols - 1) && (rowIdx >= 0) && (rowIdx + 1 < numRows) )
                {
                    // if the rightmost column has been reached, go down
                    ++rowIdx;
                    
                    // flip the direction
                    goingUpwards = false;
                    
                    // increase the headCount
                    ++headCount;
                }
                else if( (colIdx == numCols - 1) && (rowIdx == numRows - 1) )
                {
                    // increase the headCount
                    ++headCount;
                }
                else
                {
                    rowIdx = rowIdx - 1;
                    colIdx = colIdx + 1;
                }
            }
            else
            {
               // store the current element
                result.push_back( mat[rowIdx][colIdx] );
                
                if( (rowIdx == numRows - 1) && (colIdx < numCols) && (colIdx + 1 < numCols) )
                {
                    // if the bottom row has been reached, go right
                    ++colIdx;
                        
                    // flip the direction
                    goingUpwards = true;
                    
                    // increase the headCount
                    ++headCount;
                }
                else if( (colIdx == 0) && (rowIdx >= 0) && (rowIdx + 1 < numRows) )
                {
                    // if the leftmost column has been reached, go down
                    ++rowIdx;
                    
                    // flip the direction
                    goingUpwards = true;
                    
                    // increase the headCount
                    ++headCount;
                }
                else if( (colIdx == numCols - 1) && (rowIdx == numRows - 1) )
                {
                    // increase the headCount
                    ++headCount;
                }
                else
                {
                    rowIdx = rowIdx + 1;
                    colIdx = colIdx - 1;
                }
            }
        }
        
        return result;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result {};
        
        // direction
        // 0: go right
        // 1: go down
        // 2: go left
        // 3: go up
        int direction {};
        
        int topMostRow    {};
        int leftMostCol   {};
        int bottomMostRow { (int)(matrix.size())    - 1 };
        int rightMostCol  { (int)(matrix[0].size()) - 1 };
        
        int rowIdx {};
        int colIdx {};
        while( (topMostRow <= bottomMostRow) && (leftMostCol <= rightMostCol) )
        {
            result.push_back( matrix[rowIdx][colIdx] );
            
            switch( direction )
            {
                case 0:
                {
                    // go right
                    if( colIdx == rightMostCol )
                    {
                        // go down
                        ++rowIdx;
                        ++topMostRow;
                        ++direction;
                    }
                    else
                    {
                        ++colIdx;
                    }
                }
                break;
                case 1:
                {
                    // go down
                    if( rowIdx == bottomMostRow )
                    {
                        // go left
                        --colIdx;
                        --rightMostCol;
                        ++direction;
                    }
                    else
                    {
                        ++rowIdx;
                    }
                }
                break;
                case 2:
                {
                    // go left
                    if( colIdx == leftMostCol )
                    {
                        // go up
                        --rowIdx;
                        --bottomMostRow;
                        ++direction;
                    }
                    else
                    {
                        --colIdx;
                    }
                }
                break;
                case 3:
                {
                    // go up
                    if( rowIdx == topMostRow )
                    {
                        // go right
                        ++colIdx;
                        ++leftMostCol;
                        direction = 0;
                    }
                    else
                    {
                        --rowIdx;
                    }
                }
                break;
            }
        }
        
        return result;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int const lengthA { (int)a.length() };
        int const lengthB { (int)b.length() };
        
        // make the strings to be the same length by preppending zeros 
        if( lengthA > lengthB )
        {
            b.insert( 0, lengthA - lengthB, '0' );
        }
        else
        {
            a.insert( 0, lengthB - lengthA, '0' );
        }
        
        // add the strings together
        int carryOver {};
        for( auto i { (int)a.length() - 1 }; i >= 0; --i )
        {
            int const sum = (a[i] - '0') + (b[i] - '0') + carryOver;
            
            if( sum > 1 )
            {
                carryOver = 1;
                
                if( lengthA > lengthB )
                {
                    a[i] = (sum % 2) + '0';
                }
                else
                {
                    b[i] = (sum % 2) + '0';
                }
            }
            else
            {
                carryOver = 0;
                
                if( lengthA > lengthB )
                {
                    a[i] = sum + '0';
                }
                else
                {
                    b[i] = sum + '0';
                }
            }
        }
        
        if( carryOver == 1 )
        {
            if( lengthA > lengthB )
            {
                a.insert( 0, "1" );
                return a;
            }
            else
            {
                b.insert( 0, "1" );
                return b;
            }
        }
        else
        {
            if( lengthA > lengthB )
            {
                return a;
            }
            else
            {
                return b;
            }
        }
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto tmp1 { l1 };
        auto tmp2 { l2 };
        bool add1 { false };
        std::vector<int> integers;
        
        // Get the sum, storing each digit as an element in the vector
        while( (tmp1 != nullptr) || (tmp2 != nullptr) )
        {
            int val1 { 0 };
            int val2 { 0 };
            
            if( tmp1 != nullptr )
            {
                val1 = tmp1->val;
            }
            
            if( tmp2 != nullptr )
            {
                val2 = tmp2->val;
            }
            
            auto sum { val1 + val2 };
            
            integers.push_back( 0 );
            auto const lastIdx { integers.size() - 1 };
            if( add1 )
            {
                sum += 1;
            }
            
            if( sum >= 10 )
            {
                add1 = true;
                integers[lastIdx] += sum % 10; 
            }
            else
            {
                add1 = false;
                integers[lastIdx] += sum;
            }
            
            if( tmp1 != nullptr )
            {
                tmp1 = tmp1->next;
            }
            
            if( tmp2 != nullptr )
            {
                tmp2 = tmp2->next;
            }
        }
        
        // if the add1 is set to true at this point, we need to append one more element to the vector
        if( add1 )
        {
            integers.push_back( 1 );
        }
        
        // Create the node using the vector
        ListNode* result = nullptr;
        
        if( integers.size() != 0 )
        {
            for( auto i { (int)integers.size() - 1 }; i >= 0; --i )
            {
                ListNode* tmpNode = new ListNode;
                tmpNode->val      = integers[i];
                tmpNode->next     = result;
                result            = tmpNode;
            }
        }
        
        return result;
    }
};
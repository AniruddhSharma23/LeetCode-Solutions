Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/discuss/1800390/c-explanation-time-o1-space-o1-0ms-100-faster 


C++ Explanation | Time O(1) | Space O(1) | 0ms & 100% Faster

Method:
//
// * Firstly we find the average of high and low and save it in a variable k
// * Case 1:
//      * when both high and low are even
//      * In this case ans would be directly the average which is k here
//      * Example:
//          * high =6 low = 2
//          * k = 2 (numbers are 3,5)
// * Case 2:
//      * When one of the high or low is odd and other is even
// * Case 3:
//      * When both high and low are odd
// * For Case 2 and 3:
//      * we just have to account for the one extra odd value
//      * so we check if it is the 2nd or 3rd case
//      * If it is then add 1 to k
//      * Example:
//              * low = 3 high =6
//              * k = 1+1 =2 (numbers: 3,5)
//              * low = 2 high =5
//              * k = 1+1 =2 (numbers: 3,5)
//              * low = 3 high =9
//              * k = 3+1 =2 (numbers: 3,5,7,9)
// * Thus all cases are handled
// * Finally, return k

Time Complexity: O(1)
//          * As, we are only finding an average between two given numbers
//          * Hence, constant Time complexity
Space Complexity: O(1)
//          * As, we have created only one extra variable to store the result
//          * Hence, constant Space complexity

Code:

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int k = (high - low) / 2;
        if (high % 2 != 0 || low % 2 != 0)
        {
            k += 1;
        }
        return k;
    }
};

// Happy Coding :-)

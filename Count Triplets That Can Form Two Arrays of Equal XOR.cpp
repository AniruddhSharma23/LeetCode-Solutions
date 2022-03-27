
C++ Solution using XOR

    // Method:
    //  From the array we choose three index (i,j,k) such that =>
    // a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
    // b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
    // and a==b
    // As we know that when two numbers are equal then there Xor is 0
    // i.e a^b=0
    // Thus, we only have to find two positions i and k such that xor of all the values between them is 0.
    // So we first created a variable count to store the number of pairs
    // Then, we run a loop from i=0 to i = arr.size()-1 as j is greater than i but can be equal to or less than k so at the end i can't go to the last position
    // we store the value of arr[i] in a variable a
    // Then, we run a loop from j=i+1 to the end to find these pairs
    // Now, we find the arr[j] such that it's xor with a is 0 and we keep updating a every time
    // Now, when we found such j the number of triplets possible will be j-i
    // because, let's take an example
    // if we found i=0 and j=3
    // Then the pair can be
    //(0,1,3)
    //(0,2,3)
    //(0,3,3)
    // which is 3 = j-i
    // As, j can be equal to k but will always be greater than i
    // Hence, it's always gonna be j-i
    // Finally, return the count variable

    Code :
``` class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int count = 0;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int a = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                a = a ^ arr[j];
                if (a == 0)
                {
                    count += j - i;
                }
            }
        }
        return count;
    }
};
```

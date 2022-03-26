Concatenation of Array in C++


**Method:**
*  We create a vector array v with same values and length as nums
*  Then, we use the insert function of the vector class in C++
* The insert function accepts three parameters specified as below:
	* position – It specifies the position at which insertion is to be done in vector. (v.end() in this case)
	* iterator1 – It specifies the starting position from which the elements are to be inserted(nums.begin() in this case)
	* iterator2 – It specifies the ending position till which elements are to be inserted(nums.end() in this case)
* Then, we return the vector v
* **Time complexity: O(n) as n elements are inserted**



**Code:**
```
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>v = nums;
        v.insert(v.end(), nums.begin(),nums.end());
        return v;
    }
};
```
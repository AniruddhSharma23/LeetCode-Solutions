C++ Solution || Time O(n) || Constant extra space || Explained || Short

**Method:**
* as all the elements are in the range of 1 to n
* we keep updating the nums[abs(nums[i])-1] by multiplying it by -1
* we do this because if a number gets repeated then its abs[nums[i]) will be same and we will go to the same location once again i.e. nums[abs(nums[i])-1]  but this time this value is already negative hence we know that this element has appeared more than once so we add this in our vector
* Example:
	* nums[i] = [4,3,2,7,8,2,3,1]
	* i=0, nums[abs(nums[0])-1] = nums[3] =7 which is positive hence we change nums[3] to -7
	* when i=2 nums[abs(nums[i])-1] = 3 so we change it to -3
	* similarly till i=5 the new updated nums will be [4,-3,-2,-7,8,2,-3,-1]
	* now when i=5 nums[abs(nums[5])-1] = -3 which is negative which means this nums[i] has already occured so we add abs(nums[i]) =2 in v
	* and as we can observe 2 occurs more than once
	* Similar approach can be followed for rest of the numbers
* **Time Complexity: O(n)**
	* as the for loop runs at most n times

**Code:**

```
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0){
                v.push_back(abs(nums[i]));
            }else{
                nums[abs(nums[i])-1]*=-1;
            }     
        }
        return v;
    }
};
```
Happy Coding :-)

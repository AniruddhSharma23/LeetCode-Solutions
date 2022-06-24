class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        long long lsum = 0;
        long long rsum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++)
        {
            rsum -= nums[i];
            if (lsum == rsum)
                return i;
            lsum += nums[i];
        }
        return -1;
    }
};

/*
* For arr[] =  [ 1 , 7 , 3 , 6 , 5 , 6 ]
* Initial Sum = 28
* The idea is to store the right and left sum in rsum and lsum respectively
* Initially rsum = total sum and lsum=0
* Now we start from the first element and remove it from the rsum
* Now we check if this is element is a pivot or not i.e. whether lsum = rsum
* not that rsum and lsum doesn't include the pivot and that's why we subtracted it before performing the check
* Now, if it isin't a pivot then we store this element in lsum and move to the next index
* at last if we didn't find any pivot then we return -1

* Procedure for above array:
    (1) lsum = 0 , rsum = 27(subtracted index 0 value)
        now they are not equal from starting index 0  => now at next iteration lsum increases
    (2) lsum=1 , rsum = 20(subtracted index 1 value)
    (3) lsum=8 , rsum = 17(subtracted index 2 value)
    (4) lsum=11 , rsum = 11(subtracted index 3 value)
            now,
            lsum = 1+7+3 == rsum = 5+6
            and index value is now 3 so we return 3
*/
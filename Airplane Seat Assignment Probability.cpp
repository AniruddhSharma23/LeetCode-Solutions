class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        if (n == 1)
            return 1;
        return 0.5;
    }
};
/*

**Approach:**

* let the first person be alex and the nth person be bob
* now, there can be three cases
* **Case A:**
    * alex sits at his own seat
    * nth seat = empty
* **Case B:**
    * alex sits at your seat
    * nth seat = non_empty
* **Case C:**
    * alex sits at a random seat (seat_no!=1 && seat_no!=n)
* Now, the trick is to notice that Case C will never affect the ans
* why?
* **let's take an example**
* say there are 7 seats
    * if alex took the 1st seat
        * bob will be able to sit at your seat
    * if alex sit at 7th seat
        * bob won't be able to sit at your seat
    * if alex sits at a random pos, let's say at 4
    * so now our task is to find if bob can sit on his seat or not
    * so the prob is same but now we need to check for the 4th person instead of alex
    * because the 2nd and 3rd person will sit in their respective seats only
    * so the possible scenerios that determines whether bob will sit at 7th pos or not are still 2 only
        *  if 4th person took the 1st seat
            * bob will be able to sit at your seat
        * if 4th person took the 7th seat
            * bob won't be able to sit at your seat
        * if he takes any random position then we follow the same approach but for a different individual this time
* so no matter what our outcome is determined by two cases only
* **Case A:**
    * the kth person sits at 1st seat
    * bob get his seat
* **Case B:**
    *  the kth person sits at nth seat
    *  bob doesn't get his seat
* now the probability of choosing the 1st and nth seat is same
* i.e there are only two possible cases and the probability of there occurence is same
* **so probability of bob sitting on his seats is clearly = 1/2**
*/
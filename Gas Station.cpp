C++ Solution || Time O(n) || Space O(1) || Fully Explained || Short & Sweet

**Method:**
* let's consider an example of 10 stations
	* let's denote the gas-cost value for each station as a,b,c,d,e,f,g,h,i,j respectively
	* the curr_gas store these a,b,c,etc.
	* the start = 0 i.e. we are starting from the index=0 i.e. the 1st station
	* now let's suppose at the 6th station is the first point where gas-cost becomes negative
	* i.e. a+b+c+d+e+f = -ve =k(say)
	* now the logic is that we can surely say that none of the intermediate station from 1 to 6 can be the starting point
		* proof:
			* let's prove it by contradiction
			* let's say 3rd station is the valid starting point
			* now, if at 6th value became negative that means all the previous one are positive right(i.e. a+b+c+d+e = +ve)
			* so if we start from c then
				* c+d+e+f = k-(a+b)
				* here lhs must be +ve as 3rd station is the valid point
				* in the rhs k = -ve, a+b = +ve
				* -ve -(+ve) = -ve hence rhs will be negative always
				* thus lhs!=rhs  contradiction and hence the next possible station will be after 6 for sure
				* hence when we encounter curr_gas<0 we shift start to i+1;
* now for the prev_gas it stores a+b+c+d+e+f
* as we are now gonna start fresh from g
* and the loop runs till j
* at last if suppose g to j sum is positive then curr_gas = g+h+i+j
* and in order to check we must add a to f in it which we had already store in prev_gas
* so the total is curr_gas+prev_gas and it must be positive for the travel
* **Time Complexity: O(n)**
	* n = number of gas stations
	* as the loop runs only n times
* **Space Complexity: O(1)**
	* as we created 3 variable only
	* hence the space complexity is linear

**Code:**

```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gas =0;
        int prev_gas =0;
        int start =0;
        for(int i=0;i<gas.size();i++){
            curr_gas+= gas[i]-cost[i];
            if(curr_gas<0){
                start=i+1;
                prev_gas+=curr_gas;
                curr_gas=0;
            }
        }
        if(curr_gas+prev_gas >=0){
            return start;
        }
        return -1;
    }
};
```

*Happy Coding :-)*
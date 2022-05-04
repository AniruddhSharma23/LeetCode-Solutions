/*
Method:

    as we know that sum of piles is odd so there can't be a draw
    now if both players play optimally, then we can say that alice will always pick the pile with highest number of stone
    and as alice gets the first chance, so the sum of alice piles will always be greater than bob one even if bob also chooses the pile with highest number of stone
    example:
    for piles = [5,3,4,5]
        let's arrange them for better understanding
        piles = [3,4,5,5]
        now alice will take 5 obv
        so piles = [3,4,5]
        let's say bob take 5
        so piles=[3,4]
        then alice will take 4 and bob will take 3 after that
        so in the end
        alice = 5+4; bob=3+5
        and if bob is stupid enough to pick pile with less number of stone then also alice win
        so in any case it is a win win situation

Time and Space Complexity: O(1)
*/

// Code:

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};
class Solution
{
public:
    bool divisorGame(int n)
    {
        // if the number is 1 then Alice can't win so false
        if (n == 1)
        {
            return false;
        }

        /*
        Tabulation method:
        create a dp array of size n+1
        each dp[i] depicts the chance of alice winning the game
        as we will store that if in the process alice arrive at a particular number i then will it be in his favour or not
        because there can be multiple x<n such that n%x=0 so we have to choose precisely which one to take so that at the end alice win
        we store dp[i] =1 when alice wins and dp[i]=0 when bob wins
        */
        vector<int> dp(n + 1, 0);

        // now check for numbers greater than 1 and less than or equal to n
        for (int i = 2; i <= n; i++)
        {
            // the factors of i will lie in the range 1 to sqrt(i)
            for (int j = 1; j <= sqrt(i); j++)
            {
                /*
                now if j is a factor of i then bob will get the number i-j and we want bob to loose so the dp[i-j] must be 0
                if both of these conditions are true then only alice can choose this j as the factor
                and if it is then we set dp[i] as 1 indicating that choosing this j is in his favour
                */
                if ((i % j == 0) && dp[i - j] == 0)
                {
                    dp[i] = 1;
                }
            }
        }
        // now if for the given number we have dp[n] as 1 then it means Alice wins so we return true otherwise return false
        if (dp[n] == 1)
        {
            return true;
        }
        return false;
    }
};
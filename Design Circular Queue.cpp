class MyCircularQueue
{
private:
    vector<int> v;
    int n, f, r;

public:
    /*
       resize the array to size=k
       set maxSize as n and its value as k
       set front as f and its value as 0
       set rear as r and its value as -1
    */
    MyCircularQueue(int k)
    {
        v.resize(k);
        n = k;
        f = 0;
        r = -1;
    }
    /*
       now if the array is full then we can't insert so return false
       else
       we insert at pos = r+1 ( because r points to the position where the last element is)
       but r can go out of the range therefore we take %n, so that if we are at the last position then
       we can go back to 1st position
       set v[r] as value and return true
    */
    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        r = (r + 1) % n;
        v[r] = value;
        return true;
    }
    /*
       now if the array is empty then we can't delete so return false
       else
       we delete at pos = f ( because f points to the position where the first element is)
       and hence now we move f 1 index forward
       but f can go out of the range therefore we take %n, so that if we are at the last position then
       we can go back to 1st position
       if(f==r), then it means we have only 1 element left in the array and thus we reset the values of r and f
    */
    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        if (f == r)
        {
            f = 0;
            r = -1;
        }
        else
        {
            f = (f + 1) % n;
        }

        return true;
    }
    /*
       now if the array is empty then we can't get the front element so return -1
       else
       we return element at pos = f ( because f points to the position where the first element is)
    */
    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return v[f];
    }
    /*
      now if the array is empty then we can't get the rear element so return -1
      else
      we return element at pos = r ( because r points to the position where the last element is)
   */
    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return v[r];
    }
    /*
       check if r=-1, (because r points to the position where the last element is)
       and if r=-1 then we know by our initial values that the array is empty
    */
    bool isEmpty()
    {
        return (r == -1);
    }
    /*
       check if f and r at the same location, (because r points to the position where the last element is)
       and (because f points to the position where the first element is)
       but this is true in case of empty string too, so we have to check if its not empty too
    */
    bool isFull()
    {
        return (!isEmpty() && (f == ((r + 1) % n)));
    }
};

> Date: 01 March 2020
># Recursion
The process in which a function calls itself is known as recursion and the corresponding function is called the recursive function.
## Head Recursion
    void RecursiveFunction(int n)
    {
        if(n > 0)
        {
            RecursiveFunction(n-1);
            /* task 1 */           
        }
    }
In head recursion, the recursive function is called before executing any tasks.

## Tail Recursion
    void RecursiveFunction(int n)
    {
        if(n > 0)
        {                
            /* task 1 */           
            RecursiveFunction(n-1);
        }
    }
In head recursion, the recursive function is called after executing any tasks.

### Time and space complexity
----
```
void RecursiveFunction(int n)
{
    if(n > 0)
    {
        /* task 1 */               
        
        RecursiveFunction(n-1);
    }
}
```
In the above example, let RecursiveFunction() have a time complexity of T(n).
Task 1 - 3 have a time complexity of 1 each, so 3.  
  * The function call to `RecursiveFunction(n-1)` is not just another task, it's a call to a function that has a time complexity of `T(n)`.
Therefore this function must have a time complexity of T(n-1).

* Total time complexity,
  * `T(n) = T(n-1) + 1 -> n > 0`
  * `T(n) = 1          -> n = 0`
* For first recursive call,
  * `T(n) = T(n-1) + 1`
* For second recursive call,
  * `T(n) = T(n-2) + 2`
* For kth recursive call
  * `T(n) = T(n-k) + k`
* When k = n,
  * `T(n) = T(n-n) + n`
  * `T(n) = T(0) + n`
  * `T(n) = 1 + n`
  * `T(n) = O(n)`

### Tail recursion vs Loop
----
For a simple recursion given below,
```
void RecursiveFunction(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        RecursiveFunction(n-1);
    }
}
```
*   Time complexity = `O(n)`
*   Space complexity = `O(n)`
*   Space complexity is `O(n)` because for each function call, a separate activation record is created in stack.

On the other hand, for a loop,
```
void Loop(int n)
{
    while(n > 0)
    {
        printf("%d", n--);
    }
}
```

*   Time complexity = `O(n)`
*   Space complexity = `O(1)`
    Space complexity is `O(1)` because only one activation record is created in stack.

### Head recursion vs Loop
----
For a simple recursion given below,
```
void RecursiveFunction(int n)
{
    if (n > 0)
    {                
        RecursiveFunction(n-1);
        printf("%d", n);
    }
}
```
*   Time complexity = O(n)
*   Space complexity = O(n)
    Space complexity is O(n) because for each function call, a separate activation record is created in stack.
    Some compilers at higher optimization levels, convert tail recursion to a simple loop to save space.

On the other hand, for a loop,
```
void Loop(int n)
{
    int i = 0;
    while(i < n)
    {
        printf("%d", i++);
    }
}
```
Note that it cannot be converted to a loop as easy as that for tail recursion.
*   Time complexity = `O(n)`
*   Space complexity = `O(1)`
*   Space complexity is `O(1)` because only one activation record is created in stack.

## Tree recursion
*   Linear recursion  
        If in a recursive function, the function is only called once, then it's called a **linear recursion**.
*   Tree recursion  
        The recursive function is calling itself more than once.
        It cannot be categorized as tail or head recursion.
    ```
    void RecursiveFunction(int n)
    {
        if(n>0)
        {
            printf("%d", n);
            RecursiveFunction(n-1);
            RecursiveFunction(n-1);
        }
    }
    ```
    *   Time complexity = `O(2^n)`
    *   Space complexity = `O(n)`

## Indirect Recursion
*  A recursive cycle consisting of multiple recursive functions.
```
void Second_RF(int n)
{
    if(n > 0)
    {
        /* Some code */
        First_RF(n-1);
    }
}
void First_RF(int n)
{
    if(n > 0)
    {
    /* Some code */
    Second_RF(n/2);
    }
}
```
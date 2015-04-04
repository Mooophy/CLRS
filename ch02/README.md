##Ex2.1-1
```cpp
algorithm begin:
  {31,[41],59,26,41,58} (index = 1) ->
  {31,41,[59],26,41,58} (index = 2) ->
  {[26],31,41,59,41,58} (index = 3) ->
  {26,31,41,[41],59,58} (index = 4) ->
  {26,31,41,41,[58],59} (index = 5)
end

```
##Ex2.1-2
 * A functor for comparison can be passed in to specify order direction, such as `std::greater<T>` or `std::less<T>`
 * Implementation: `insertion_sort.hpp`
 * Test: `test_insertion_sort.cpp`

##Ex2.1-3
 * Pseudocode:
```cpp
Linear-Search(arr, val)
1 for i = 0 to arr.length - 1
2   if val == arr[i]
3     return i
4 return Nil
```
 * Loop invariant:
```cpp
At the start of each iteration of the for loop, no item preceeding arr[i] is equal to val.
```
 * Proof:
 
```cpp
I: 
  i = 0 -> 
  nothing preceeds index 0 ->
  trivially, no item preceeding index 0 is equal to val. ->
  I holds.
  
M: 
  suppose it holds for i = 0 to k. For i = k + 1, to continue the loop, arr[k + 1] must be unequal to val. ->
  after this iteration the loop invariant holds for i = k + 1. ->
  M holds.
  
T:
  the termination conditions are either that i is equal to arr.length or that the item equal to val is found. ->
  for the first case, all items preceeding index arr.lengh, aka the entire array at this moment, are unequal to val, so Nil is returned; for the second case, the index that points to the value equal to val will be returned. ->
  both case return results as desired. ->
  T holds.

I and M and T -> 
this algorithm is correct.  
```
 
##Ex2.1-4
 * Problem description:
```cpp
Input: two arrays lhs and rhs which store two n-bit binary numbers respectively
Output: one array that stores an n+1-bit binary number, such that it is equal to the sum of lhs and rhs 
```
 * Pseudocode:
```cpp
Add-Binary-Numbers(lhs, rhs)
1 def sum as an array with sum.length = lhs.lengh + 1
2 def carry = 0
3 for i = lhs.lengh - 1 to 0
4   sum[i + 1] = (carry + lhs[i] + rhs[i]) % 2
5   carry = (carry + lhs[i] + rhs[i]) / 2
6 sum[0] = carry
7 return sum
```
* Implementation : `add_binary_numbers.hpp`
* Test : `test_add_binary_numbers.cpp`

##Ex2.2-1
```cpp
\theta(n^3)
```

##Ex2.2-2
 * Pseudocode:
```cpp
Selection-Sort(arr)
1 for i = 0 to arr.length - 2     <-  c1 x (n - 1)
2   def index_for_min = arr[i]    <-  c2 x (n - 2)
3   for j = i to arr.length - 1   <-  c3 x (n - 2) x n / 2
4     if arr[min] > arr[j]        <-  c4 x (n - 2) x (n / 2 - 1)
5       index_for_min = j         <-  time belongs to range [0, c5 x (n - 2) x (n / 2 - 1)]
6     swap arr[i] and arr[min]    <-  c6 x (n - 2) x (n / 2 - 1)  
7 return arr                      <-  c7
```

 * Loop invariant:
```cpp
At the start of each iteration of the for loop, 
all items in range [0, i) are less than any item in range [i, length - 1); 
Also items in range [0, i) have been sorted.
```
 * With n = arr.length, when i == n - 1 , only one item left in range[n - 1, n). If this algorithm runs n times, what it does in the last run will always be swap (arr[arr.length - 1], arr[arr.length - 1]). Hence, n - 1 times is enogh. 
 * Time complexity:
```cpp
For best case, time complexity for line 5 equals to 0. Total time required : \theta(n^2)
For worst case, time complexity for line 5 equals to c5 x (n - 2) x (n / 2 - 1). Total time required : \theta(n^2)
```
 * Implementaion: `selection_sort.hpp`
 * Test: `test_selection_sort.cpp`

##Ex2.2-3
 * n/2 elements need to be checked on average.
 * For worst case, n elements need to be checked.
 * For average-case, `theta(n/2) -> theta(n)`
 * For worst case, `theta(n)`

##Ex2.2-4
Not sure about this question.Perhaps a precheck can be carried out to see if the input is desired already.

##Ex2.3-1
```cpp
     {3, 9, 26, 38, 41, 49, 52, 57}
  {3, 26, 41, 52}       {9, 38, 49, 57}
{3, 41}   {26, 52}    {38, 57}    {9, 49}     
{3} {41}  {52}  {26}  {38}  {57}  {9} {49}
```

##Ex2.3-2
 * Implementation: `merge_sort.hpp`
 * Test: `test_merge_sort.cpp`

##Ex2.3-3
```cpp
basis:
  n = 1   
  ->  LHS = 2 and RHS = 2 x lg(2) = 2 x 1 = 2   
  ->  LHS == RHS
  
induction:
  suppose: the equaltion is correct for n = 2^k, where k > 1.   
  ->  T(2^k) = 2^k x lg(2^k)
             = (2^k) x k    --  eq2  
  
  for n = k + 1:
  LHS = 2T(2^(k+1)/2) + 2^(k+1)
      = 2T(2^k)       + 2^(k+1)
    using eq2:
      = 2k(2^k)       + 2^(k+1)
      = k(2^(k+1))    + 2^(k+1)
      = (2^(k+1)) x (k+1)
              
  RHS = (2^(k+1)) x lg(2^(k+1)) 
      = (2^(k+1)) x (k+1)
  
  LHS = RHS
  ->  This equation is correct.
```

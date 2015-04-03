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

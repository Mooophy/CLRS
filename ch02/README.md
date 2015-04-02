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
 * For source : `insertion_sort.hpp`
 * For test : `test_insertion_sort.hpp`

##Ex2.1-3
 * pseudocode:
```cpp
Linear-Search(arr, val)
1 for i = 0 to arr.length - 1
2   if val == arr[i]
3     return i
4 return Nil
```
 * loop invariant:

 ```cpp
At the start of each iteration of the for loop, 
all items preceeding arr[i] have been compared with val, 
but none is equal to it.
 ```
 * proof:
 
```cpp
I: 
  i = 0 -> 
  nothing preceeds arr[0] ->
  trivially, all items preceeding arr[i] have been compared with val, but none is equal to it. ->
  it is true prior to the first iteration of the loop.
  
M: 
  Suppose it holds for i = k. For i = k + 1, to continue the loop arr[k + 1] must be unequal to val. ->
  after this iteration the loop invariant for i = k + 1. ->
  the second property holds.
  
T:
  the termination conditions are either i is equal to arr.length or the first item that is equal to val is found. ->
  for the first case, all items in arr are unequal to val and Nil is returned; for the second case, the index that points to the value equal to val will be returned. ->
  both case return the result desired. ->
  the third property holds.

Hence this algorithm is correct.  
```
 

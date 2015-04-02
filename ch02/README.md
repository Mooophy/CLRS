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
  Linear-Search(arr, value)
1   for i = 0 to arr.length - 1
2     if value == arr[i]
3       return i
4   return Nil
```
 * loop invariant:

 ```cpp
At the start of each iteration of the for loop, 
all items stored in subarray arr[0..i] have been compared with value, 
but none is equal to it.
 ```
 * proof:
 
```cpp

```
 

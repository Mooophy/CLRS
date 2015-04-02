##Ex2.1-1
```cpp
begin:
  {31,[41],59,26,41,58} -> {31,41,[59],26,41,58} -> {[26],31,59,41,58} -> {26,31,41,[59],58} -> {26,31,41,[58],59} -> {26,31,41,58,59}
end
```
##Ex2.1-2
 * A functor for comparison can be passed in to spicify order direction, such as `std::greater<T>` or `std::less<T>`
 * For source : `insertion_sort.hpp`
 * For test : `test_insertion_sort.hpp`

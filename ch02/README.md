2 Getting Started
--------------------------------------------------------
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
##Ex2.1-2 [Insertion Sort](src/insertion_sort.hpp) | [Test](test/test_insertion_sort.cpp)
 * A functor for comparison can be passed in to specify order direction, such as `std::greater<T>` or `std::less<T>`

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
 
##Ex2.1-4 [Implementation](src/add_binary_numbers.hpp) | [Test](test/test_add_binary_numbers.cpp)
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

##Ex2.2-1
```cpp
\theta(n^3)
```

##Ex2.2-2 [Selection Sort](src/selection_sort.hpp) | [Test](test/test_selection_sort.cpp)
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

##Ex2.3-2 [Merge Sort](src/merge_sort.hpp) | [Test](test/test_merge_sort.cpp)

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

##Ex2.3-4
 * Pseudocode:
```cpp
Insertion-Sort-by-Recursion(arr)  
    if arr.length < 2                                           //theta(1)
        return arr                                              //theta(1)
    else                                                        //theta(1)
        arr = Insertion-Sort-by-Recursion(arr[:-1]) + arr[-1]   //T(n - 1) + theta(1)
        def key = arr[-1]                                       //theta(1)
        def curr = arr.length - 1                               //theta(1)
        for (curr = arr.length - 1 to 1) and (arr[curr] > key)  //O(n - 1)
            arr[curr + 1] = arr[curr]                           //O(n - 2)
        arr[curr + 1] = key                                     //theta(1)
        return arr                                              //theta(1)
```
  * Recurrence:
```cpp
T(n) = theta(1)         , if n = 1
     = T(n - 1) + O(n)  , if n > 1
```

##Ex2.3-5
 * Pseudocode:
```cpp
Binary-Search-by-Recursion(arr, val)    
  low = 0
  high = arr.length - 1
  while low <= high       //T(n/2)
    mid = (low + high)/2
    if arr[mid] > val
      high = mid - 1
    else if arr[mid] < val
      low = mid + 1
    else
      return mid
  return Nil
```
 * Proof for time complexity
```cpp
From the pseudocode
->  T(n) = T(n/2) + theta(1)  
->  T(n) = theta(lg(n))
```

##Ex2.3-6
 * No. lines 5 - 7 from Insertion-Sort are doing two things: Firstly, it finds the correct position to insert; Secondly, it pushes elements with greater value backwards. For an arrry, binary search can't improve the pushing part, For a linked list, binary seach can't handle the first task.   
  
##Ex2.3-7
* Pseudocode
```python
#Combine sorting and binary search together.
Are-There-Two-Elements-That-Have-Sum-As-Specified(set, sum)
  set.sort() #O(n lg n)
  for curr = 0 to set.length - 1 #O(n)
    if Nil != binary_search(arr = set[curr:], val = sum - set[curr]) #O(n lg n)
      return true
  return false
```

##Problem 2-1 Merge-Sort + Insertion-Sort
 *  a. Time complexity for sorting n/k sublists with insertion sort:  
```cpp
    (n/k) x theta(k^2) = theta(nk)
```
 *  b. Time complexity for merging all sublists
 
```cpp
As shown in Figure 2.5:
    it takes theta(n) to merge each level in recursion tree. 
    total height of the recursion is theta(lg(n))
    merging start from the first level to lg(k):
        theta(n(lg(n) - lg(k))) = theta(n(lg(n/k)))
Hence, it takes T(n) = theta(n(lg(n/k))) to merge the sublists.
```
 *  c. k = lg(n) is the largest value that meets requirement.
```cpp

T(n) = theta(n + n x lg(n)) , if k = 1
  This is exact merge sort with no optimization.
  
T(n) = theta(n x lg(n) + n x lg(n / lg(n))), if k = lg(n)
  Since n is supposed to be greater than 2, the first term n x lg(n) is the significant part.
  Anything greater than lg(n) will make the first term greater than theta(n x lg(n)) and the second term is always postive.
  Hence the largest value is k = lg(n)
```
 * d. The desired value can be found by testing values from range [1, lg(n)].

##Problem 2-2 Bubble-Sort
 * a. One more thing need to prove is that no item in A has been deleted nor item added into A'.In another word, A' must be a permutation of A.
 * b. Loop invariant and its proof for lines 2-4
```cpp
Loop invariant:
  Prior to each iteration of the for loop, A[j] = min(s) , where set s = { x | x <- A[j, A.length] } .

Proof  
I:
  Prior to the first iteration
  ->  j = A.length, s = { x | x <- A[A.length, A.length] } 
  ->  A[A.length] is the only element in s
  ->  I holds.
  
M:
  Let loop invariant holds before j = k
  ->  A[k] = min(s), where s = { x | x <- A[k, A.length] } -- equation 1
  
  The semantics of lines 3 and 4   
  ->  swap A[k] and A[k-1], if A[k] < A[k - 1]
  ->  decrement k to k - 1
  
  Applying equation 1
  ->  j becomes k - 1
  ->  A[k - 1] = min(s), where s = { x | x <- A[k - 1, A.length] }
  ->  loop invariant holds before next iteration
  ->  M holds.
  
T:
  Termination condition is j = i
  ->  A[i] = min(s), where s = { x | x <- A[i, A.length] }
  ->  this property is useful and exactly expected
  ->  T holds.
  
I and M and T -> loop invariant holds 
```

 * c. Loop invariant and its proof for lines 1-4
```cpp
Loop invariant:
  Prior to each iteration of the for loop, 
  all elements in subarray [ : i - 1] are smaller than anything in subarray [i : ],
  and are sorted.

Proof
I:
  Prior to the first iteration, [ : i - 1] is empty
  ->  I holds.
  
M:
  Suppose LI holds before i = i
  ->  all elements in subarray A[ : i - 1] are smaller than anything in subarray A[i : ], and are sorted.
  
  Applying the property T from part b and above
  ->  A[i] = max( left_set ), A[i] = min( right_set )
        where   left_set  = { x | x <- A[ : i ]}
                right_set = { x | x <- A[ i : ]}
              
      increment i to i + 1
  ->  LI holds before next iteration
  
T:
  i = A.length is the termination condition
  ->  subarray A[ : A.length - 1] has been sorted and A[A.length], the only element in subarray A[A.length, A.length], is greater than or equal to the largest element in A[ : A.length - 1]
  ->  A is sorted.
  
I.M.T -> LI holds.  
```

 * d. time complexity = theta(n^2). Insertion-Sort is better. Because for average case and best case Insertion-Sort doesn't have to carry out theta(n) for its nested loop. whereas Bubble-Sort has to do so for any case.

##Problem 2-3 Horner’s rule [Implementation](src/polynomial.hpp) | [Test](test/test_polynomial.cpp)
 * Time complexity : theta(n)
 * pseudocode
```python
Naive-Polynomial-Evaluation(arr, x)
  y = 0
  for i = 0 to arr.length - 1
    X = 1
    for k = i downto 1
      X *= x
    y += X * arr[i]
  return y
```

 * LI and proof
```cpp
(To avoid Greek letter Sigma, here is using sum(head, tail)() function instead)
L.I.:
  At the start of each iteration of the for loop of lines 2–3,
  y = sum(k = 0, k = n - (i + 1)) (a(k + i + 1) * x ^ k)
  
I.:
  Prior to the first iteration, 
    y = sum(k = 0, k = -1) (a(k + i + 1) * x ^ k)
    upper limit is lower than lower limit, this equation is meaningless, y = 0
  Hence, I holds.

M.:
  Suppose L.I. holds before i = i
    y = sum(k = 0, k = n - (i + 1)) (a(k + i + 1) * x ^ k)
    
    by line 2 - 3,            LHS becomes:
      y = a(i) + x * y
        = a(i) + x * ( a(i + 1) + a(i + 2) * x + ... + a(n) * x^(n - i - 1)
        = a(i) + a(i + 1) * x + a(i + 2) * x^2 + ... + a(n) * x^(n - i)
        
    when i = i - 1            RHS becomes
      sum(k = 0, k = n - i) (a(k + i) * x ^ k)  
        = a(i) + a(i + 1) * x + a(i + 2) * x^2 + ... + a(n) * x^(n - i)
      
  LHS = RHS, hence M holds for next iteration.
  
T.:
  The termination condition is i = -1
  y = sum(k = 0, k = n - (-1 + 1)) (a(k - 1 + 1) * x ^ k)
    = sum(k = 0, k = n) (a(k) * x ^ k)
  Hence, T holds.
  
L.I. holds.
```

 * As shown above, this code fragment correctly evaluates a polynomial.

##Problem 2-4 Inversions [Implementation](src/find_inversions.hpp) | [Test](test/test_find_inversions.cpp)
 *  Five inversions:
```cpp
{2,1}, {3,1}, {8,1}, {6,1}, {8,6}
```
 * set {n, n-1, n-2, ...,2, 1}, i.e. numbers in descending order has most inversions.
```
number of inversions = n(n - 1)/2
```
 * As shown below, the expression `A[i] > key` in line 5 Insertion-Sort is in essence checking for an inversion. So a function can be made to describe the relationship between the running time and number of inversions:
```cpp
T(n) = theta(number_of_inversions + n)
```
 * Algorithm to find inversions in theta(n(lg(n))):
```cpp
Modify Merge-Sort as following:
1 Pass count as a reference or a pointer into procedure Merge and Merge-Sort
2 add statement : count += n1 - i into Merge between line 16 and line 17
```

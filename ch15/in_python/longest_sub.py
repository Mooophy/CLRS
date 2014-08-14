#from SO : 
#	http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
#	O(n^2) version

def dynamic_programming_solution(sequence):                                      
  longest_subsequence_ending_with = []                                           
  backreference_for_subsequence_ending_with = []                                 
  current_best_end = 0                                                           
  for curr in range(len(sequence)):                                         
    # It's always possible to have a subsequence of length 1.                    
    longest_subsequence_ending_with.append(1)                                    
    # If a subsequence is length 1, it doesn't have a backreference.             
    backreference_for_subsequence_ending_with.append(None)                       
    for prev in range(curr):                                           
      subsequence_length_through_prev = (longest_subsequence_ending_with[prev] + 1)
      # If the prev_elem is smaller than the current elem (so it's increasing)   
      # And if the longest subsequence from prev_elem would yield a better       
      # subsequence for curr_elem.                                               
      if (sequence[prev] < sequence[curr] and subsequence_length_through_prev > longest_subsequence_ending_with[curr]):
        # Set the candidate best subsequence at curr_elem to go through prev.    
        longest_subsequence_ending_with[curr] 		= subsequence_length_through_prev
        backreference_for_subsequence_ending_with[curr]	= prev         
    # If the new end is the best, update the best.                               
    if (longest_subsequence_ending_with[curr] > longest_subsequence_ending_with[current_best_end]):                      
      current_best_end = curr

  # Output the overall best by following the backreferences.
  ret = []                                                          
  current_backreference = current_best_end                                       
  while current_backreference is not None:                                       
    ret.append(sequence[current_backreference])                     
    current_backreference = backreference_for_subsequence_ending_with[current_backreference]

  #for debug	
#  print(backreference_for_subsequence_ending_with)
  ret.reverse()                                                     
  return ret  

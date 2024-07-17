class Solution:
    def sumZero(self, n: int) -> List[int]:
        # Initialize an empty list to store our unique numbers
        unique_numbers = list(range(1, n))
      
        # Add the negative of their sum to the list to ensure the final sum is zero
        # This works because the sum of all numbers from 1 to n-1 is (n-1)*n/2, so adding
        # its negative will cancel out the sum, resulting in zero.
        unique_numbers.append(-sum(unique_numbers))
      
        # Return the list of numbers which will sum to zero
        return unique_numbers
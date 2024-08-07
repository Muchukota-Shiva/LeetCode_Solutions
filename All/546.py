from functools import lru_cache

class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        # Using LRU cache to store results of subproblems
        @lru_cache(None)
        def dfs(start, end, continuous_count):
            # no boxes are left, so return 0 points
            if start > end:
                return 0
          
            # Skip the boxes that are the same from the end, increasing the continuous count.
            # This step merges the later operations for the same color boxes.
            while start < end and boxes[end] == boxes[end - 1]:
                end -= 1
                continuous_count += 1
          
            # Initialize the score by removing the last box (and all its continuous equals)
            # and solve the subproblem without the last box
            score = dfs(start, end - 1, 0) + (continuous_count + 1) ** 2
          
            # Try to merge with the same color boxes by finding a box of the same
            # color between the start and end pointers and then combine them
            for middle in range(start, end):
                if boxes[middle] == boxes[end]:
                    # Potentially increase the score by merging the box at 'middle'
                    # with the same color boxes at the end
                    score = max(score, dfs(middle + 1, end - 1, 0) + dfs(start, middle, continuous_count + 1))
            return score

        # Call the DFS for the whole array
        total_score = dfs(0, len(boxes) - 1, 0)
      
        # Clear the cache after computation to free memory
        dfs.cache_clear()
      
        return total_score
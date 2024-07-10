class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        if not nums:
            return

        # find the first decreasing element from the end
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        # if i is not the first element, swap nums[i] with the next larger element
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        # reverse the elements after the swapped element
        nums[i + 1:] = nums[i + 1:][::-1]

"""
what i did in class for this 
def next_permutation(arr):
    # Find the rightmost element which is smaller than its next element
    n = len(arr)
    i = n - 2
    while i >= 0 and arr[i] >= arr[i + 1]:
        i -= 1

    if i == -1:
        # If no such element is found, then the array is in descending order
        arr.reverse()
    else:
        # Find the rightmost element which is larger than arr[i]
        j = n - 1
        while arr[j] <= arr[i]:
            j -= 1

        # Swap the found elements arr[i] and arr[j]
        arr[i], arr[j] = arr[j], arr[i]

        # Reverse the elements from i+1 to end of the array
        arr[i + 1:] = reversed(arr[i + 1:])

    return arr

def main(): 
    # Do not edit this part of the code
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        
        result = next_permutation(arr)
        
        for num in result:
            print(num, end=" ")
        print()

if __name__ == "__main__":
    main()

"""
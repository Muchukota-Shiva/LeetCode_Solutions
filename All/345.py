class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        st, ls = 0, len(s) - 1
        char_list = list(s)


        while st < ls:
            while st < ls and char_list[st] not in vowels:
                st += 1
            while st < ls and char_list[ls] not in vowels:
                ls -= 1
            if st < ls:
                char_list[st], char_list[ls] = char_list[ls], char_list[st]

                st += 1
                ls -= 1
        return "".join(char_list)
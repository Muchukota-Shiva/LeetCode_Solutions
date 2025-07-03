class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        answer = defaultdict(list)

        for s in strs:
            key=''.join(sorted(s))

            answer[key].append(s)

        return list(answer.values())
        
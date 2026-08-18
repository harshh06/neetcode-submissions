class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        mp = defaultdict(list)
        n = len(beginWord)

        for word in wordList:
            for i in range(n):
                p = word[:i] + '*' + word[i+1:]
                mp[p].append(word)

        vis = {beginWord}
        q = deque([beginWord])
        res = 1
        while q:
            q_size = len(q)
            for _ in range(q_size):
                word = q.popleft()
                if word == endWord:
                    return res
                for i in range(n):
                    p = word[:i] + '*' + word[i+1:]
                    for relatedWord in mp[p]:
                        if relatedWord not in vis:
                            vis.add(relatedWord)
                            q.append(relatedWord)
            res += 1
        return 0


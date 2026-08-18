class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        mp = defaultdict(list)
        
        def wordDiffByOne(word1: str, word2: str) -> bool:
            cnt = 0
            for i in range(len(word1)):
                if word1[i] != word2[i]:
                    cnt += 1
            return True if cnt == 1 else False
        wordList.append(beginWord)
        for word in wordList:
            for relatedWord in wordList:
                if word != relatedWord and wordDiffByOne(word, relatedWord):
                    mp[word].append(relatedWord)

        vis = set()
        q = deque([beginWord])
        res = 1
        while q:
            q_size = len(q)
            for _ in range(q_size):
                word = q.popleft()
                vis.add(word)
                if word == endWord:
                    return res
                for relatedWord in mp[word]:
                    if relatedWord not in vis:
                        q.append(relatedWord)
            res += 1
        return 0


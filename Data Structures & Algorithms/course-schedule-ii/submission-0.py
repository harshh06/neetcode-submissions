class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        order = []
        indegree = [0] * numCourses
        mp = defaultdict(list)
        for a, b in prerequisites:
            mp[b].append(a)
            indegree[a] += 1

        q = deque(i for i in range(numCourses) if indegree[i] == 0)

        while q:
            v = q.popleft()
            order.append(v)
            for u in mp[v]:
                indegree[u] -= 1
                if indegree[u] == 0:
                    q.append(u)
        
        return order if len(order) == numCourses else []
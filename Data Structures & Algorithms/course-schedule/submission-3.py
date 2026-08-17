class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        mp = defaultdict(list)
        for a, b in prerequisites:
            mp[b].append(a)
        vis = [0] * numCourses
        
        def isCycle(course: int) -> bool:
            vis[course] = 1
            for adjCourse in mp[course]:
                if not vis[adjCourse]:
                    if isCycle(adjCourse):
                        return True
                elif vis[adjCourse] == 1:
                    return True
                elif vis[adjCourse] == 2:
                    continue #do nothing!! 
            vis[course] = 2
            return False
        
        for course in range(numCourses):
            if not vis[course]:
                if not vis[course] and isCycle(course):
                    return False
        return True

            
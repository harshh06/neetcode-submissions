class TimeMap:

    def __init__(self):
        self.mp = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        vals = self.mp[key]
        lo, hi = 0, len(vals)
        while lo < hi:
            mid = (lo + hi) // 2
            if vals[mid][0] > timestamp:
                hi = mid
            else: lo = mid + 1
        if lo - 1 >= 0:
            return vals[lo-1][1]
        else:
            return ""

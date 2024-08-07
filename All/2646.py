class Solution:
    def minimumTotalPrice(self, n: int, edges: List[List[int]], price: List[int], trips: List[List[int]]) -> int:
        def dfs(current_node: int, parent_node: int, destination: int) -> bool:
            #dfs question so dfs
            trip_count[current_node] += 1
            if current_node == destination:
                return True
          
            path_exists = any(
                neighbor != parent_node and dfs(neighbor, current_node, destination)
                for neighbor in graph[current_node]
            )
          
            if not path_exists:
                trip_count[current_node] -= 1
              
            return path_exists
        
        def dfs_min_price(current_node: int, parent_node: int) -> (int, int):
            full_price = trip_count[current_node] * price[current_node]
            half_price = full_price // 2

            for neighbor in graph[current_node]:
                if neighbor != parent_node:
                    min_full, min_half = dfs_min_price(neighbor, current_node)
                    full_price += min(min_full, min_half)
                    half_price += min_full

            return full_price, half_price

        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
          

        trip_count = Counter()
        for start, end in trips:
            dfs(start, -1, end)

        full_price, half_price = dfs_min_price(0, -1)
        return min(full_price, half_price)
        
        
from queue import PriorityQueue

def optimal_merge(files):
    
    pq = PriorityQueue()
    for file in files:
        pq.put(file)
    
    total_cost = 0  
    
    while pq.qsize() > 1:

        first = pq.get()
        second = pq.get()
        
        merge_cost = first + second
        total_cost += merge_cost
        
        pq.put(merge_cost)
    
    return total_cost

# Example usage:
file_sizes = [4, 3, 2, 6]
print("Minimum cost to merge files:", optimal_merge(file_sizes))
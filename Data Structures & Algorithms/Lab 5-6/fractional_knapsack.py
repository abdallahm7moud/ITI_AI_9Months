def fractional_knapsack(items, capacity):
    
    ratios = [(v/w, v, w) for v, w in items]

    ratios.sort(reverse=True)
    
    total_value = 0
    for ratio, value, weight in ratios:
        if capacity >= weight:

            total_value += value
            capacity -= weight
        else:

            total_value += value * (capacity / weight)
            break
    return total_value

items = [(70, 10), (140, 20), (180, 30)]  # (value, weight)
capacity = 50
print(f"Maximum value: {fractional_knapsack(items, capacity)}")
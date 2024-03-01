def weighted_event_scheduling(events: list[tuple[int, int]], weights: list[int]):
    # array[i]-1 represents the index in events the time is associated with, positive for enter, and negative for exit

    # O(n)
    array = [i for i in range(1, len(events)+1)] + [
        -i for i in range(1, len(events)+1)
    ]
    # O(n log n)
    array = sorted(
        array, key=lambda i: events[i - 1][0] if i > 0 else events[-i - 1][1]
    )

    # O(n)
    exits = {}
    for i in range(len(array)):
        if array[i] < 0:
            exits[-array[i]] = i

    # O(n)
    dp = [0] * len(array)

    # O(n)
    for t in range(len(dp) - 1):
        if array[t] > 0:  # if entering
            # either take the enter
            dp[exits[array[t]]] = max(dp[exits[array[t]]], dp[t] + weights[array[t] - 1])

        dp[t + 1] = max(dp[t + 1], dp[t])

      
    return dp[-1]


times = [(0,100), (2,50), (30,150), (60,95), (110,190), (120,150), (191,200)]
weights = []
for a,b in times:
    weights.append(b-a+1)

print(weighted_event_scheduling(times, weights))

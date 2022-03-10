from heapq import heappop, heappush

INF = int(1e9)
graph = [[]]

def preprocess(n, fares):
    global graph
    graph = [[] for i in range(n+1)]

    for fare in fares:
        src, dst, cost = fare[0], fare[1], fare[2]
        graph[src].append([dst, cost])
        graph[dst].append([src, cost])

def dijkstra(src, dst):
    global graph
    n = len(graph)
    dist = [INF for i in range(n)]
    dist[src] = 0
    pq = [[0,src]]

    while pq:
        w, x = heappop(pq)
        if dist[x] < w:
            continue

        for item in graph[x]: 
            nx, ncost = item[0], item[1]
            ncost += w
            if ncost < dist[nx]:
                dist[nx] = ncost

                heappush(pq, [ncost, nx])
    return dist[dst]

def solution(n, s, a, b, fares):
    preprocess(n, fares)

    cost = dijkstra(s, a) + dijkstra(s, b)
    for i in range(1, n+1):
        cost = min(cost, dijkstra(s, i) + dijkstra(i, a) + dijkstra(i,b))
    return cost
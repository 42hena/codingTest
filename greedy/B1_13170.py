#B1 13170 떨어진 수정 success (greedy)
import sys
from math import ceil
input = sys.stdin.readline

#마나 수정의 수 N(1 ≤ N ≤ 1,000)
#마나가 응집된 마나 수정의 강도 순위를 나타내는 K(1 ≤ K ≤ N)
#둔 망치의 최대 파워 P(1 ≤ P ≤ 2,000)
#폭발 위험이 있는 힘 차이 W(1 ≤ W ≤ P)
N, K, P, W = map(int, input().split())
#N, K는 필요 없음... 몇 번째가 폭발하는지 알 수 있기 떄문에 그것만 W만큼 뚜들기면 됨
print(ceil(P / W))
# 참고 : https://www.acmicpc.net/problem/1041
# 문제의 그림에 있는 전개도와 같은 주사위들로 N * N * N의 정육면체를 만드려고 함
# 주사위를 자유롭게 회전시키고 쌓을 때, 보이는 다섯 면에 적힌 수들의 합의 최솟값을 구하는 문제

N = int(input())
a,b,c,d,e,f = map(int,input().split())

# center : 주사위 중 한 면이 보이는 경우 -> 4*(N - 1)(N - 2) + (N - 2)^2개 
# edge : 주사위 중 두 면이 보이는 경우 -> 4*(N - 1)(N - 2)개 
# corner : 주사위 중 세 면이 보이는 경우 -> 4개
# 위 세 경우의 수들의 합이 곧 총 합의 최솟값이 됨
center = min(a,b,c,d,e,f)
edge = min(a+b, a+c, a+e, a+d, f+c, f+e, f+d, f+b, c+b, b+d, d+e, e+c)
coner = min(a+c+e, a+b+c, a+b+d, a+d+e, f+b+c, f+b+d, f+d+e, f+e+c)

if N == 1:
    print(a+b+c+d+e+f-max(a,b,c,d,e,f))
else:
    N -= 2
    print((center*(N**2)*5) + 4*(N*center) + coner*4 + edge*(N*8+4))
    
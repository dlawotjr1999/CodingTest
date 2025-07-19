N = int(input())
a,b,c,d,e,f = map(int,input().split())

center = min(a,b,c,d,e,f)
edge = min(a+b, a+c, a+e, a+d, f+c, f+e, f+d, f+b, c+b, b+d, d+e, e+c)
coner = min(a+c+e, a+b+c, a+b+d, a+d+e, f+b+c, f+b+d, f+d+e, f+e+c)

if N == 1:
    print(a+b+c+d+e+f-max(a,b,c,d,e,f))
else:
    N -= 2
    print((center*(N**2)*5)+4*(N*center)+coner*4+edge*(N*8+4))
    
# 출처: https://lazypazy.tistory.com/161 [Redddy's Devlog:티스토리]
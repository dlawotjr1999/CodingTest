T = int(input()) + 1

for tc in range(1,T):
    N = int(input())
    print(f'#{tc}', end=' ')
    while N > 3:
        N = N // 2 + 1
        N = N // 2 - 1 

    if N >= 2 or N==0: 
        print('Alice')

    else:
        print('Bob')
from sys import stdin

input = stdin.readline

n,m,k = map(int, input().split())
board = [[0]*m for _ in range(n)]

blocks = []

for _ in range(k):
    r,c = map(int, input().split())
    block = [list(map(int, input().split())) for _ in range(r)]
    blocks.append(block)
def solv():
    answer = 0
    for block in blocks:
        for _ in range(4):
            cnt = insert_block(block)
            if cnt != 0:
                answer += cnt
                break
            block = rotate_block(block)
    print(answer)
def insert_block(block):
    global board

    r,c = len(block),len(block[0])
    for sx in range(n-r+1):
        for sy in range(m-c+1):
            if board[sx][sy] == 0 or block[0][0] == 0:
                cnt = 0
                flag = False
                for x in range(r):
                    for y in range(c):
                        if block[x][y] == 1:
                           if board[sx+x][sy+y] == 0:
                               cnt += 1
                               board[sx+x][sy+y] = 1
                           else:
                               flag = True
                               break
                    if flag:
                        break
                if flag:
                    rollback_board(cnt, sx, sy, r, c, block)
                else:
                    return cnt
    return 0
def rollback_board(cnt,sx,sy,r,c,block):
    global board

    tmp = 0
    if tmp == cnt:
        return

    for x in range(r):
        for y in range(c):
            if block[x][y] == 1:
                board[sx+x][sy+y] = 0
                tmp += 1

                if tmp == cnt:
                    return
def rotate_block(block):
    r,c = len(block),len(block[0])
    tmp = [[0]*r for _ in range(c)]

    for x in range(r):
        for y in range(c):
            tmp[y][r-x-1] = block[x][y]
    return tmp

solv()
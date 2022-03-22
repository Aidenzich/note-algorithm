
# move a over b: clear blocks above a, then move a on the top of the pile
# pile a onto b: clear blocks above b, then move a and blocks above a onto b
# pile a over b: move a and blocks above onto b's pile



N, M = list(map(lambda x: int(x), input().split()))
 
blocks = {}
positions = {}


    




for block_num, idx in enumerate(range(N), start=1):
    # print(block_num)
    blocks[block_num] = [block_num]
    positions[block_num] = [block_num, 1]

for i in range(M):
    move_arr = input().split()
    a = int(move_arr[1])
    b = int(move_arr[3])
    act = move_arr[0]
    pos = move_arr[2]

    # move a onto b: clear the blocks above a and b, then move a onto b
    if (act == "move" and pos == "onto"):
        move_block_state = positions[a]
        to_block_state = positions[b]
        print(blocks[move_block_state[0]])
        for idx2, elem2 in enumerate(reversed(blocks[move_block_state[0]])):
            # print(a)
            if i == a:
                del blocks[idx2]
                blocks[b].append(a)
                break
            
            blocks[elem2].append(elem2)
            
            del blocks[idx2]

        




        # 註 目前只把空間畫出來，為了速度方便，需要用外的arr來紀錄block n 的位置
        print()

    if (act == "move" and pos == "over"):
        print(0)

    if (act == "pile" and pos == "onto"):
        print(0)

    if (act == "pile" and pos == "over"):
        print(0)

print(blocks)
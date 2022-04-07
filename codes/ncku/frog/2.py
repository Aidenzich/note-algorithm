
n = input()

for i in range(int(n)):
    (rock_num, river_len) = input().split()
    dictionary = {'b': [], 's': []}
    for j in rock_num:
        input_list = input().split()
        pos = input_list[1::2]
        size = input_list[0::2]

        for (idx, k) in enumerate(size):
            dictionary[k].append(int(pos[idx]))

        b_pos = dictionary['b']
        b_pos.append(0)
        b_pos.append(int(river_len))

        b_pos = list(set(b_pos))
        b_pos.sort()
        diff = [b_pos[n] - b_pos[n - 1] for n in range(1, len(b_pos))]
        print(max(diff))

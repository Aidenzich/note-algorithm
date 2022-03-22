t = input()

for i in range(int(t)):
    data = input()
    u, v = data.split()
    u = int(u)
    v = int(v)
    found = False
    x = 0
    y = 0
    while found != True:
        if (x == 0 and y == 0):
            y += 1
        x = - y * pow(u, 2) / pow(v, 2);
        if (x == int(x)):
            found == True
            break
        else:
            y+= 1
    print(f"{int(x)} {y}\n")
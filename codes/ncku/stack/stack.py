

stack = []
def PUSH():
    stack.append([])

def DUP():
    temp = stack[-1].deepcopy()
    stack.append(temp)
    
def UNION():
    temp1 = stack.pop()
    temp2 = stack.pop()
    tmp2_len = len(temp2)
    for i in temp1:
        if i not in temp2[:tmp2_len]:
            temp2.append(i)
    temp2 = sorted(temp2)
    stack.append(temp2)

def INTERSECT():
    temp1 = stack.pop()
    temp2 = stack.pop()
    intersect_elem = [x for x in temp1 if x in temp2]
    stack.append(sorted(intersect_elem))    
    
def ADD():
    temp1 = stack.pop()
    temp2 = stack.pop()
    
    if temp1 not in temp2:
        temp2.append(temp1)
    temp2 = sorted(temp2)
    stack.append(temp2)

N = int(input())

for _ in range(N):
    oper = input()    
    if oper[0] == "P":
        PUSH()        
    if oper[0] == "I":
        INTERSECT()
    if oper[0] == "A":
        ADD()
    if oper[0] == "D":
        DUP()
    if oper[0] == "U":
        UNION()

    print(len(stack[-1]))
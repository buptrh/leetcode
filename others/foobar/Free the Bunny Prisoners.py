from math import factorial

def calculate_combinations(n, r):
    if r <= 0 or n <= 0 or n-r <= 0:
        return 1;
    return factorial(n) // factorial(r) // factorial(n-r)

def findComb(comb, path, n, start, end):
    if len(path) == n:
        if (tuple(path) not in comb):
            comb.add(tuple(path))
            return True;
        else:
            return False;
    for i in range(start, end): 
        path.append(i)
        if findComb(comb, path, n, i+1, end):
            return path
        path.pop(len(path)-1)

    
def answer(num_buns, num_required):
    # your code here
    keyCount = calculate_combinations(num_buns, num_required-1);
    
    res = [];
    comb = set(tuple([100, 100, 100]));

    for j in range(0, num_buns):
        arr = []
        res.append(arr);

    for i in range(0, keyCount):
        path = [];
        findComb(comb, path, num_buns - num_required + 1, 0, num_buns)
        print(i, path)
        for j in path:
            res[j].append(i);
    return res


# Inputs:
#     (int) num_buns = 2
#     (int) num_required = 1
# Output:
#     (int) [[0], [0]]

# Inputs:
#     (int) num_buns = 5
#     (int) num_required = 3
# Output:
#     (int) [[0, 1, 2, 3, 4, 5], [0, 1, 2, 6, 7, 8], [0, 3, 4, 6, 7, 9], [1, 3, 5, 6, 8, 9], [2, 4, 5, 7, 8, 9]]

# Inputs:
#     (int) num_buns = 4
#     (int) num_required = 4
# Output:
#     (int) [[0], [1], [2], [3]]
print answer(5,3)
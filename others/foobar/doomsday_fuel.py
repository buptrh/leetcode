import fractions
from itertools import compress

def lcm(a, b):
    if b > a:
        a, b = b, a
    if a % b == 0:
        return a
    mul = 2
    while a*mul % b != 0:
        mul += 1
    return a*mul
    
def gcd(x, y): # very fast
   return x if y == 0 else gcd(y, x%y)
   
def answer(m):
    # your code here
    row = len(m);
    sums = {}
    poss = []
    res = []
    resMap = {}
    totalMultiply = 1;
    for i in range(0, row):
        sum = 0;
        for j in m[i]:
            sum += j;
        sums[i] = sum;
        poss.append(float(0));
    poss[0] = float(1);
    for time in range(10000):
        newPoss = [float(0.0) for n in range(row)]
        for i in range(0, row):
            if sums[i] == 0:
                newPoss[i] += poss[i];
            else:
                for j in range(0, row):
                    val = float(m[i][j]) * float(poss[i])/float(sums[i]);
                    newPoss[j] += val;
        poss = newPoss;
        # print(time, poss)
    totalPoss = float(0)
    for i in range(0, row):
        if sums[i] == 0:
            res.append(poss[i]);
            totalPoss += poss[i];
    
    numerators = []
    denominators = []
    for i in res:
        numerator = fractions.Fraction(i).limit_denominator()
        numerators.append(numerator.numerator)
        denominators.append(numerator.denominator)
    # print(numerators)
    # print(denominators)
 
    denominator = 1
    for i in denominators:
        denominator = lcm(denominator, i)
    # print(denominator)
    ansers = []
    for i in res:
        ansers.append(int(round(i*denominator)))
    ansers.append(denominator)
    return ansers


m =[[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]

print(answer(m))

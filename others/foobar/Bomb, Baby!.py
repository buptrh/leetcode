
def answer(M, F):
    # your code here
    m = int(M)
    f = int(F)
    count = 0
    while True:
        if m == 1 and f == 1:
            return str(count);
        elif m == f or m <= 0 or f <= 0:
            return "impossible";
        elif m > f:
            count += m/f
            m = m % f
            if m == 0:
                m += f;
                count -= 1;
        else:
            count += f/m
            f = f % m
            if f == 0:
                f += m;
                count -= 1;
        # print(m, f)
    return "impossible"

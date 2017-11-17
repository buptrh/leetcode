def answer(xs):
    # your code here
    dpMax = [xs[0]];
    dpMin = [xs[0]];
    res = xs[0];
    for i, v in enumerate(xs):
        if i == 0:
            continue;
        dpMax.append(max(0, xs[i]));
        dpMin.append(min(0, xs[i]));
        dpMax[i] = max(dpMax[i], max(dpMax[i-1]*v, dpMin[i-1]*v));
        dpMin[i] = min(dpMin[i], min(dpMax[i-1]*v, dpMin[i-1]*v));
        dpMax[i] = max(dpMax[i], dpMax[i-1]);
        dpMin[i] = min(dpMin[i], dpMin[i-1]);
        res = max(res, dpMax[i]);
    return res;

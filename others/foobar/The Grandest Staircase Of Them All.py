def answer(n):
    # your code here
    dp = [[0 for x in range(n+1)] for y in range(n+1)] 
    
    for i in range(1, n):
        dp[i][1] = 1
        
    for i in range(1,n+1):
        for j in range(2, i+1):
            dp[i][j] = dp[i-j][j] + dp[i-j][j-1]
            # print(i, j, dp[i][j])
            
            
    res = 0;
    for i in range(2, n):
        res += dp[n][i]
    return res

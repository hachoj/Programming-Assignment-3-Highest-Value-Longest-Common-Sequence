# Programming Assignment 3

Harrison Chojnowski: `46524954`

Pranav Annapareddy: `21340719`

**Running our code:**

The executable is actually saved to the repo so you can just run:
```bash
./hvlcs < data/example.in
```
from the project root.

If you need to recompile the script, you will need a valid C++ compiler. Then you can run,
```bash
g++ -o hvlcs src/main.cpp src/hvlcs.cpp
```
and then repeat the command above.

Assume the inputs follow the same format as given in the project specifications, namely:

```
3
a 2
b 4
c 5
aacb
caab
```
Where the first line has the number of chars `n`, the next next `n` lines have the char followed by its value. Then the two char sequences.

# Written Questions

## Question 1:
![image](out/hvlcs_runtime.png)

## Question 2:

`OPT(i, j)` is the maximum value common subsequence between the first `i` characters of the sequence `A` and the first `j` characters of the sequence `B`. 

The base cases are `OPT(0, j)` and `OPT(i, 0)` which both trivially equal `0`.

Recurrence cases:
There are three possibilities within `OPT(i, j)`.
1. `A[i]` is not in the optimal subsequence so `OPT(i-1, j)` is the same as `OPT(i, j)`.
2. `B[j]` is not in the optimal subsequence so similarly, `OPT(i, j-1)` is equal to `OPT(i, j)`
3. `A[i]` and `B[j]` are in the optimal subsequence, further, that implies that `A[i] == B[j]`.


So from that there are two recurrences, if `A[i] != B[j]` Then the case where both are optimal is impossible so you have `OPT(i, j) = max(OPT(i-1, j), OPT(i, j-1))`.
If `A[i] == B[j]` then you have 
`OPT(i, j) = max(OPT(i-1, j), OPT(i, j-1), OPT(i-1, j-1) + v(A[i]))`.

This works because the recurrence covers all possible cases which includes the base cases, so the rest of the table could be filled out from those.


## Question 3

(I like pythonesque pseudocode)

```python
HVLCS(A, B, v):
    n = len(A)
    m = len(B)
    dp[n][m] init to 0
    
    for i = 1 -> n:
        for j = 1 -> m:
            if A[i] == B[j]: 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + v[A[i]])
            else:                
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][m] 
```

`len(A)` and `len(B)` is $O(1)$ (or inefficiently $O(n)$/$O(m)$ but either way it won't matter given the loop later)
init `dp` is $O(nm)$ since you access all `nm` values
The double for loop is $O(nm)$ and then times whatever the inside is which we'll cover now.
The inside of the double loop has the if statement as $O(1)$ since array access is $O(1)$ and all the subsequent array accesses are also $O(1)$ with `max` also being $O(1)$ given it's a max between at most 3 values.

Therefore the whole double loop is just $O(nm)$ since it's filled with only $O(1)$ operations.

Therefore, the whole function is $O(nm)$.

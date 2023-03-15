def fib_a(n): 
    if n <= 1:
        return n
    
    seq = [0, 1]

    for i in range(n):
        seq.append(seq[-1] + seq[-2])
    
    return seq[n]

def fib_b(n):
    if n <= 1:
        return n
    
    p2 = 0
    p1 = 1

    for _ in range(n-1):
        p2, p1 = p1, p1 + p2

    return p1


def fib_c(n):
    if n <= 1:
        return n
    
    return fib_c(n-1) + fib_c(n-2)

print(fib_a(21))
print(fib_b(21))
print(fib_c(21))

print(fib_a(10))
print(fib_b(10))
print(fib_c(10))
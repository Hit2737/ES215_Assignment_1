import random
import time

def matmul(N, A, B, C):
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]

sizes = [64, 128, 256, 512, 1024]

time_int = []
time_dbl = []

print("Integer matrix multiplication")
for size in sizes:
    A = [[random.randint(1, 10000) for _ in range(size)] for _ in range(size)]
    B = [[random.randint(1, 10000) for _ in range(size)] for _ in range(size)]
    C = [[0 for _ in range(size)] for _ in range(size)]

    start = time.process_time()
    matmul(size, A, B, C)
    stop = time.process_time()
    
    time_taken = stop - start
    print("Time taken for size", size, "is", time_taken)
    time_int.append(time_taken)
    
print()
print("Double matrix multiplication")
for size in sizes:
    A = [[random.uniform(1,10000) for _ in range(size)] for _ in range(size)]
    B = [[random.uniform(1,10000) for _ in range(size)] for _ in range(size)]
    C = [[0 for _ in range(size)] for _ in range(size)]

    start = time.process_time()
    matmul(size, A, B, C)
    stop = time.process_time()

    time_taken = stop - start
    print("Time taken for size", size, "is", time_taken)
    time_dbl.append(time_taken)

with open("data2py.txt", "w") as file:
    for i in range(5):
        file.write(str(time_int[i]) + " ")
        file.write(str(time_dbl[i]) + "\n")
        print(time_int[i], end=" ")
        print(time_dbl[i])
    print()


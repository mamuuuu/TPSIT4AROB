import random
import time

n = 1000000
 
l = [random.uniform(0.,1.) for _ in range (n)]
print(l)

start = time.time()
max = l[0]
for elem in l:
    if elem > max:
        max = elem

print(max)

end = time.time()

print(f"Tempo tot: {end-start} ")
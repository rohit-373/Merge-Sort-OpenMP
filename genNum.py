import random

n = 250000
a = -100000000
b = 100000000

f = open("numbers.txt", "w")
f.write(str(n) + "\n")
for i in range(n):
    f.write(str(random.randint(a, b)) + " ")
f.close()

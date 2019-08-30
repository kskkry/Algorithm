import numpy as np
import matplotlib.pyplot as plt

#ARC054 "Moore's law"
p = int(input())
sum_time = []
st_time = []
st = 0

def function(n):
    return pow(2,n/1.5)

for i in range(1000):
    st_time.append(st)
    if i == 0:
        sum_time.append(p)
    else :
        sum_time.append(st + p/function(st))
    st += 1

plt.plot(st_time, sum_time)
plt.show()

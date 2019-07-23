
#問題文のすぬけ数の挙動が気になったのでグラフ化してみたら
#意外な動きをしていたので保存

#import numpy as np
import matplotlib.pyplot as plt
x = 10
def calc(x):
    up = x
    down = int(0)
    while int(x) > 0:
        down += int(x % 10)
        x /= 10
    return float(up/down)

list_x = []
list_y = []
for i in range(100000):
    list_x.append(x)
    list_y.append(calc(x))
    x += 1

plt.plot(list_x,list_y)
plt.show()

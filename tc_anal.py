#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def func(x, a, b, c, d):
    return a * np.power(x + b, 3) * np.power(np.log2(x + c), 1) + d 

points = []
with open("./times.txt", "r") as f:
    for line in f.readlines():
        l, t = map(int, line.split())
        points.append((l, t))

points = np.array(points)

# get x and y vectors
x = points[:,0]
y = points[:,1]

plt.plot(x, y, 'g^', label="data")

popt, pcov = curve_fit(func, x, y)
plt.plot(x, func(x, *popt), 'r-',
         label='fit: a=%5.3f, b=%5.3f, c=%5.3f, d=%5.3f' % tuple(popt))


plt.ylabel("Time")
plt.xlabel("Input size")
plt.xlim([x[0]-1, x[-1] + 1])
plt.legend()
plt.show()

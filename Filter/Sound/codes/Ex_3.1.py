import matplotlib.pyplot as plt
import numpy as np

n=np.array([0,1,2,3,4,5])
x=np.array([1,2,3,4,2,1])
plt.xlabel('$n$')
plt.ylabel('$x(n)$')
plt.stem(n,x)
plt.grid()
plt.show()
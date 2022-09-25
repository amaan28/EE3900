import numpy as np
x=np.array([2,-1])
h=np.array([-1,2,1])
#Toeplitz matrix
#t=np.array([[-1,0],[2,-1],[1,2],[0,1]])  from scipy.linalg.toeplitz(c,r)
hconv=np.zeros((4,1))

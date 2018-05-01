import numpy as np
import matplotlib.pyplot as plt
import glob
import imageio


a= np.loadtxt("t1.txt")
n= np.shape(a)[0]-1



x = a[:,0]
y = a [:,1]

plt.plot(x,y)
	

plt.savefig("cuerda.png")



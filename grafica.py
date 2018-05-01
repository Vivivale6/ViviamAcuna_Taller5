import numpy as np 

import matplotlib.pyplot as plt 

datos = np.loadtxt("t2.txt")

a=datos[:,0]
b=datos[:,1]
c=datos[:,2]

h=512;
x= np.linspace(-h,h,1000)
y= np.linspace(-h,h,1000)
X,Y= np.meshgrid(x,y)

u,v = np.meshgrid(x,y)


plt.streamplot(X,Y,u,v)
plt.imshow(datos)

plt.savefig("placas.pdf")

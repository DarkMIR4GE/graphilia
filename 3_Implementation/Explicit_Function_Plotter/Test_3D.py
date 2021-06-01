import matplotlib.pyplot as plt
import numpy as np
import sys
import Decode
import Code


minX = -1
maxX = 1
minY = -1
maxY = 1
precX = 500
precY = 500
prec = 10e-3

x = np.linspace(minX, maxX, precX)
y = np.linspace(minY, maxY, precY)
z = []

#Inp_expr = input('f(x,y) = ')
#Inp_expr = '(0.4^2-(0.6-(x^2+y^2)^0.5)^2)^0.5'   #torus
Inp_expr = 'sin(10*(x^2+y^2))/10'                #ripple
#Inp_expr = '1/(15*(x^2+y^2))'                    #tube
#Inp_expr = 'sin(5*x)*cos(5*y)/5'                 #bumps
#Inp_expr = '(x^2+y^2)^0.5'                       #cone
#Inp_expr = '(sgn(-.65-x)+sgn(-.35-x)+sgn(-.05-x)+sgn(.25-x)+sgn(.55-x))/7' #stairs
#Inp_expr = '1-abs(x+y)-abs(y-x)'                 #pyramid
#Inp_expr = '.75/exp((x*5)^2*(y*5)^2)'            #intersecting fence
#Inp_expr = 'sgn(x*y)*sgn(1-(x*9)^2+(y*9)^2)/9'   #windmill
#Inp_expr = '.1-sgn(sgn((x*12)^2-9)+sgn((y*12)^2-9)-2)/2' #cross
#Inp_expr = 'sgn(x)*atan(x*80)/6*sgn(-y-x+1)*sgn(-y+x+1)*5-1.01' #paper plane

#Inp_expr = wg.Text(value = 'Name')
#display(Inp_expr)

if (Code.braceChk(Inp_expr)):
    Infx_expr = Code.codeInp(Inp_expr)
    Postfx_expr = Code.Infix_2_Postfix(Infx_expr)
else:
    sys.exit()

y_tmp = np.ndarray(len(x))
for yi in y:
    y_tmp[:] = yi
    z = np.append(z, Decode.value(Postfx_expr, x, y_tmp))
X = np.outer(np.ones_like(y),x)
Y = np.outer(y,np.ones_like(x))
Z = np.reshape(z,(len(x),len(y)))

fig = plt.figure(figsize = (12,7))
ax = fig.gca(projection = '3d')
ax.plot_surface(X, Y, Z, cmap = 'viridis')
ax.set_xlabel('X', fontsize = 15)
ax.set_ylabel('Y', fontsize = 15)
ax.set_zlabel('Z', fontsize = 13)
plt.grid()
plt.show()

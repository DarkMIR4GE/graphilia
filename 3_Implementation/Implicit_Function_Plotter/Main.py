import matplotlib.pyplot as plt
import numpy as np
import sys
import Decode
import Code


minX = -10
maxX = 10
minY = -10
maxY = 10
precX = 500
precY = 500
prec = 10e-3

x = np.linspace(minX, maxX, precX)
y = np.linspace(minY, maxY, precY)
Inp = input('Expression : ')

expr_1 = []
flag = 0
for t in Inp:
    if (t == '='):
        expr_1.append('-')
        expr_1.append('(')
        flag = 1
    elif (t != ' '):
        expr_1.append(t)
if (flag):
    expr_1.append(')')

if (Code.braceChk(Inp)):
    expr_2 = Code.codeInp(expr_1)
    expr_3 = Code.Infix_2_Postfix(expr_2)
else:
    sys.exit()

y_tmp = np.ndarray(len(x))
x_plt = y_plt = []
for yi in y:
    y_tmp[:] = yi
    val = Decode.value(x, y_tmp, expr_3)
    root_x = [x[i] for i in range(len(val)) if np.abs(val[i])<prec]
    root_y = np.ndarray(len(root_x))
    root_y[:] = yi
    x_plt = np.append(x_plt, root_x)
    y_plt = np.append(y_plt, root_y)

plt.figure(figsize = (12,6))
plt.axvline(0, color = 'green')
plt.axhline(0, color = 'green')
plt.plot(x_plt, y_plt, color = 'brown')
plt.grid()
plt.show()

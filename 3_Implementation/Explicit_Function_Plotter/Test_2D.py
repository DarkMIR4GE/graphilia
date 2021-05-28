import matplotlib.pyplot as plt
import numpy as np
import Decode
import Code


Min = -10
Max = 10
prec = 500

x = np.linspace(Min, Max, prec)
while (1):
    Inp_expr = input('f(x) = ')
    #Inp_expr = '1+{cos(x^2+x)^2.2}*e^pi'
    #Inp_expr = 'd(tan(sec(x^3)))/d(x)'
    
    if (Code.braceChk(Inp_expr)):
        Infx_expr = Code.codeInp(Inp_expr)
        Postfx_expr = Code.Infix_2_Postfix(Infx_expr)
    y = Decode.value(Postfx_expr, x)
    
    fig = plt.figure(figsize=(10,5))
    ax = fig.add_subplot(111)
    ax.cla()
    if (max(x) > 0) and (min(x) < 0):
        ax.axvline(0, color = 'green')
    if (max(y) > 0) and (min(y) < 0):
        ax.axhline(0, color = 'green')
    ax.plot(x, y, color = 'brown')
    ax.set_xlabel('x', fontsize = 13)
    ax.set_ylabel('f(x)', fontsize = 13)
    ax.grid()
    plt.show()
    c = input('continue (y/n)? ')
    if (c == 'n'):
        break


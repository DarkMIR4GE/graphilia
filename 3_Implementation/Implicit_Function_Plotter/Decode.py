import numpy as np


def un_Optr(optr, oprnd):
    if (optr == '~'):
        Out = -oprnd

    elif (optr == 'sin'):
        Out = np.sin(oprnd)
    elif (optr == 'cos'):
        Out = np.cos(oprnd)
    elif (optr == 'tan'):
        Out = np.tan(oprnd)
    elif (optr == 'sec'):
        Out = 1/np.cos(oprnd)
    elif (optr == 'cosec'):
        Out = 1/np.sin(oprnd)
    elif (optr == 'cot'):
        Out = 1/np.tan(oprnd)

    elif (optr == 'asin'):
        Out = np.asin(oprnd)
    elif (optr == 'acos'):
        Out = np.acos(oprnd)
    elif (optr == 'atan'):
        Out = np.atan(oprnd)
    elif (optr == 'asec'):
        Out = np.arccos(1/oprnd)
    elif (optr == 'acosec'):
        Out = np.arcsin(1/oprnd)
    elif (optr == 'acot'):
        Out = np.arctan(1/oprnd)

    elif (optr == 'sinh'):
        Out = np.sinh(oprnd)
    elif (optr == 'cosh'):
        Out = np.cosh(oprnd)
    elif (optr == 'tanh'):
        Out = np.tanh(oprnd)
    elif (optr == 'asinh'):
        Out = np.arcsinh(oprnd)
    elif (optr == 'acosh'):
        Out = np.arccosh(oprnd)
    elif (optr == 'atanh'):
        Out = np.arctanh(oprnd)

    elif (optr == 'exp'):
        Out = np.exp(oprnd)
    elif (optr == 'ln'):
        Out = np.log(oprnd)
    elif (optr == 'log'):
        Out = np.log10(oprnd)
    elif (optr == 'sqrt'):
        Out = np.sqrt(oprnd)
    elif (optr == 'log'):
        Out = np.log10(oprnd)

    elif (optr == 'ceil'):
        Out = np.ceil(oprnd)
    elif (optr == 'floor'):
        Out = np.floor(oprnd)
    elif (optr == 'abs'):
        Out = np.fabs(oprnd)
    elif (optr == 'fact'):
        Out = np.factorial(oprnd)
    elif (optr == 'sgn'):
        Out = np.sign(oprnd)
    elif (optr == 'fract'):
        Out = oprnd - np.floor(oprnd)
    elif (optr == 'gcd'):
        Out = np.gcd(oprnd)

    elif (optr == 'd'):
        Out = np.diff(oprnd)
        Out = np.append(Out, np.nan)

    return Out


def bin_Optr (optr, oprnd1, oprnd2):
    if (optr == '+'):
        Out = oprnd1 + oprnd2
    elif (optr == '-'):
        Out = oprnd1 - oprnd2
    elif (optr == '*'):
        Out = oprnd1 * oprnd2
    elif (optr == '/'):
        Out = oprnd1 / oprnd2
    elif (optr == '^'):
        Out = oprnd1 ** oprnd2
    return Out


def value(x, y, expr): #gets value of the expression for diff values of x
    stack = []
    for a in expr:
        if (type(a) == float):
            stack.append([a]*len(x))
        elif(a == 'x'):
            stack.append(x)
        elif(a == 'y'):
            stack.append(y)
        elif (a.isalpha()) or (a == '~'):   #unarOutoperations
            oprnd = np.append([], stack.pop())
            stack.append(un_Optr(a, oprnd))
        else:                               #binarOutoperations
            oprnd2 = np.append([], stack.pop())
            oprnd1 = np.append([], stack.pop())
            stack.append(bin_Optr(a, oprnd1, oprnd2))
    Out= stack.pop()
    return Out

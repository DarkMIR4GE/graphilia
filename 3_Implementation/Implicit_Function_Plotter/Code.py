import numpy as np


def codeInp(In):
    i = 0       #index of input In
    Out = []
    while (i < len(In)):

        if (In[i].isdigit() or In[i]=='.'): #to store numerical values in a array
            temp = []
            while ((In[i].isdigit()) or (In[i]=='.')):
                temp.append(In[i])
                i += 1
                if (i>=len(In)):
                    break
            Out.append(float(''.join(temp)))
            i -= 1

        elif (In[i] in 'xyz+-*/^()'): #assuming no fn start with x
            Out.append(In[i])

        elif (In[i] == '['):    #Greatest integer function
            Out.append('floor')
            Out.append('(')
        elif (In[i] == '{'):    #Fractional part function
            Out.append('fract')
            Out.append('(')
        elif (In[i] in ']}'):
            Out.append(')')

        elif (In[i].isalpha()): #to code function into a single char
            temp = []
            while (In[i].isalpha()):
                temp.append(In[i])
                i += 1
                if (i>=len(In)):
                    break
            if (temp == ['e']):
                Out.append(float(np.exp(1)))    #np.exp() gives numpy.float64 type
            elif (temp == ['p','i']):
                Out.append(np.pi)
            else:
                Out.append(''.join(temp))
            i -= 1

        i += 1
    return Out


def braceChk(In):   #checks if braces are inputted given correctly
    stack = []
    for ch in In:
        if (ch in '({['):
            stack.append(ch)
        elif (ch == ')'):
            if(stack.pop() != '('):
                return 0
        elif (ch == ']'):
            if(stack.pop() != '['):
                return 0
        elif (ch == '}'):
            if(stack.pop() != '{'):
                return 0
    if (stack != []):
        return 0
    else:
        return 1    #1 means correct, 0 means invalid input


def precedence (optr):
    if (optr == '~'):
        return 7
    elif (optr.isalpha()):
        return 6
    elif (optr == '^'):
        return 5
    elif (optr == '/'):
        return 4
    elif (optr == '*'):
        return 3
    elif (optr == '-'):
        return 2
    elif (optr == '+'):
        return 1
    else:
        return 0


def Infix_2_Postfix (In):
    stack = []
    Out = []    #output array

    def pushOptr ():
        if (In[i] == '-'):
            if (i == 0):
                stack.append('~')   #unary minus
            elif (type(In[i-1]) != float) and (In[i-1] not in 'xyz'):
                stack.append('~')
            else:
                stack.append('-')   #binary minus
        elif (In[i] == '+'):
            if (i != 0):
                stack.append('+')
            elif (type(In[i-1])==float) or (In[i-1] in 'xyz'):
                stack.append('+')
        else:
            stack.append(In[i])

    for i in range(len(In)):
        if (type(In[i]) == float) or (In[i]=='x'):
            Out.append(In[i])
        elif (In[i]== '('):
            stack.append(In[i])
        elif (In[i]== ')'):
            while (1):
                optr = stack.pop()
                if (optr == '('):
                    break
                Out.append(optr)
        else:
            if (stack == []):
                pushOptr()
            elif(precedence(In[i]) > precedence(stack[-1])):
                pushOptr()
            else:
                while (precedence(In[i]) <= precedence(stack[-1])):
                    Out.append(stack.pop())
                    if (stack == []):
                        break

                pushOptr()
    while (stack != []):
        Out.append(stack.pop())
    return Out

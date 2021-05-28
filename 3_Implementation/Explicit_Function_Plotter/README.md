# Explicit Function Plotter

## Introduction

An **explicit function** refers to functions represented as y = f(x1,x2,...), where the independent variable is fully isolated by itself in one of the sides of the equality. That is, the independent variable can be expressed solely in terms of the dependent variables.


## Programming Language

The whole code is written in **Python3** making use of **Spyder3** as an IDE.

#### Python Libraries used:
- sys
- numpy
- matplotlib
- mpl_toolkits
- PyQt5


## Code files

File | Functionality | Dependencies
------------ | ------------- | ----------
Code.py | to check and process function i/p into postfix | None
Decode.py | to compute the output of a postfix expression | None
GUI_2D.py | executable file for 2D plotter with GUI | Code.py, Decode.py
GUI_3D.py | executable file for 3D plotter with GUI | Code.py, Decode.py
Test_2D.py | test file for 2D plotter without GUI | Code.py, Decode.py
Test_3D.py | test file for 3D plotter without GUI | Code.py, Decode.py

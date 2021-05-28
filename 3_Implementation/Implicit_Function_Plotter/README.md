# Implicit Function Plotter

## Introduction

An **implicit function** refers to functions represented as g(x1,x2,...) = f(x1,x2,...), where a single variable is not fully isolated by itself to either side of the equality. While it might be possible to rewrite such a function into it's explicit counterpart, this is not always true. eg: sin(x+y) = xy

**Note: THIS CODE IS INCOMPLETE**

## Programming Language

The whole code is written in **Python3** making use of **Spyder3** as an IDE.

#### Python Libraries used:
- sys
- numpy
- matplotlib
- PyQt5


## Code files

File | Functionality | Dependencies
------------ | ------------- | ----------
Code.py | to check and process function i/p into postfix | None
Decode.py | to compute the output of a postfix expression | None
GUI.py | executable file for 2D plotter with GUI | Code.py, Decode.py
Test.py | test file for 2D plotter without GUI | Code.py, Decode.py

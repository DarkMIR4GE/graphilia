# Requirements

## Introduction

- While working with complicated mathematical functions, a quick visualisation tool can help one a lot in gaining a better understanding of the problem in hand. Even if the same can be achieved by making use of a suitable programming language like Python or MATLAB, a simple dedicated software to perform the same could be appreciated; especially by someone with little or no programming background.
- This project was specifically chosen because I had tried to implement something similar in a C++ hobby project during my school days and wanted to upgrade it into a better GUI all the while taking leverage of the same as a prototype.


## Research

Conventionally, arithmetical and logical formulae and statements are expressed with [infix notations](https://en.wikipedia.org/wiki/Infix_notation) where the binary operators are placed in between its operands (eg: 2 + 3). Infix notations require the use of parenthesis to indicate the intended order of operations; in the absence of which, a certain order of precedence is placed on operators.

Even though using infix notation is more convenient as far as human readability is concerned, computers find it difficult to parse it as such. Thus arises the need for conversion to either a [prefix notation](https://en.wikipedia.org/wiki/Polish_notation) where a binary operator precedes its operands (eg: + 2 3), or a [postfix notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) where a binary operator succeeds its operands (eg: 2 3 +). [Shunting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm) is one such algorithm which facilitates a conversion between a human-preferred infix expression and a computer-preferred postfix expression. The algorithm does this by making use of data structures such as queues and stacks.


## Cost

As the whole project involved the usage of free (or free versions of) software only, it is completely free of monetary costs.


## Defining the System


## SWOT Analysis


## 5W's and 1H



## Detail Requirements

### High Level Requirements:

ID | Description | Status
--------- | -------- | ---------
HR_01 | User-friendly Graphical User Interface with axes | Implemented
HR_02 | User should be able to input function in text format | Implemented
HR_03 | System should accept trigonometric/logarithmic/… functions | Implemented
HR_04 | System should recognise invalid inputs/functions | Implemented
HR_05 | System should plot the user inputted function | Implemented
HR_06 | Clear axes functionality | Implemented

### Low Level Requirements:

ID | Description | HR_ID | Status
--------- | -------- | -------- | ---------
LR_01 | Buttons to adjust range of displayed axes | HR_01 | Implemented
LR_02 | Pan/Zoom/Rotate functionalities using mouse | HR_01 | Future
LR_03 | Acceptance of mathematical constants like e,pi | HR_02 | Implemented
LR_04 | Acceptance of further functions like hyperbolic... | HR_03 | Implemented
LR_05 | Acceptance of Min and Max functions | HR_03 | Future
LR_06 | Identify occurrences of imaginary/undefined/indeterminate values | HR_04 | Implemented
LR_07 | Options to plot multiple functions in the same axes | HR_05 | Implemented
LR_08 | 3D representation of functions in 2 variables | HR_05 | Implemented
LR_09 | Plot graphs from implicit function inputs | HR_05 | Incomplete

# Test Plan

## Integration Test (High Level Test)

HT_ID | Description | Result | Type of Test
------- | -------- | -------- | ----------
HT_01 | Check if GUI is loading properly | SUCCESS | Requirement based
HT_02 | Check if input string is read from textbox | SUCCESS | Requirement based
HT_03 | Check if functions are coded properly from raw i/p | SUCCESS | Technical
HT_04 | Check if the coded i/p are accurately converted to postfix | SUCCESS | Technical
HT_05 | Check if trigonometric/logarithmic/… functions are recognised | SUCCESS | Requirement based
HT_06 | Check if invalid functions break the program | SUCCESS | Requirement based
HT_07 | Check if brace mismatches break the program | SUCCESS | Requirement based
HT_08 | Check if the program plots the input function | SUCCESS | Requirement based
HT_09 | Check if the clear button clears the figure | SUCCESS | Requirement based

## Unit Test (Low Level Test)

LT_ID | HT_ID | Description |  Result | Type of Test
------- | -------- | -------- | ---------- | --------
LT_01 | HT_01 | Check if the range gets altered as per user i/p | SUCCESS | Requirement based
LT_02 | HT_03 | Check if constants like e,pi are recognised | SUCCESS | Requirement based
LT_03 | HT_05 | Check if hyperbolic/… functions are recognised | SUCCESS | Requirement based
LT_04 | HT_06 | Check if encountering imaginary o/p breaks the program | SUCCESS | Requirement based
LT_05 | HT_06 | Check if encountering undefined/indeterminate o/p breaks the program | SUCCESS | Requirement based
LT_06 | HT_08 | Check if multiple functions can be plotted in the same axis | SUCCESS | Requirement based
LT_07 | HT_08 | Check if function i/p in 2 variables plot 3D graphs | SUCCESS | Requirement based
LT_08 | HT_08 | Check if implicit functions are plotted accurately | FAIL | Requirement based
LT_09 | HT_08 | Are the 2D, 3D and implicit parts integrated together | FAIL | Requirement based

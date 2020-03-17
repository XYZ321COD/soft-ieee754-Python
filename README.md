# soft-ieee754-Python
This project allows you to create custom ieee754 data types for Python and Numpy, which normally are unavailable. Project is still under process of building.
## Why
The smallest floating point supported by numpy and python is half(16bits). Sometimes in science reaserch we must go a bit lower with bit precision, and this project should allow you to create every ieee754 floating-point format in Python.

## How to create lib
`python2 setup.py build`

## Creating custom float
Inside common.hpp there is:<br>
`typedef IEEE754<x,y >`<br>
Just type our own x and y. For more information checkout [LiraNuna - ieee754](https://github.com/LiraNuna/soft-ieee754)
## Testing how good your custom floating point is
Inside /Tests there is .py files that will tell you how your custom fp is doing comparable to Python standard float. Before running test move created .so into /Tests

## How to use 
Check /Tests for more examples.
## Related work 
* [LiraNuna - ieee754](https://github.com/LiraNuna/soft-ieee754)
    - My projects is simply python wrapper around it.
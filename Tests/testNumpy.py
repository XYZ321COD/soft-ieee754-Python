import numpy as np
from numpy import uint16, float16, float32, float64
from numpy.testing import *
import _float

def test_consistency():
    # Check how my created floating-point is doing comparable to built-in floats.
    # Remebmer that we can only cast from floating points - can't cast from int

    f32array = np.arange(0x10, dtype=float32)
    myFpArray = np.array(f32array).astype(dtype=_float.myType)
    print("From float32 to myType")
    print(f32array)
    print(myFpArray)
    print("--------------------------")

    # Convert my floating-point to flaot32
    myFpArray = np.array(f32array).astype(dtype=_float.myType)
    myFpArrayto_32 = myFpArray.copy()
    myFpArrayto_32 = myFpArray.astype(dtype=float32)
    print("From myType to float32")
    print(myFpArray)
    print(myFpArrayto_32)
    print("--------------------------")
    # Convert float64 to my float-point

    f64array = np.array(f32array).astype(dtype=float64)
    myFpArrayfrom_f64 = f64array.copy()
    myFpArrayfrom_f64 = myFpArrayfrom_f64.astype(_float.myType)
    print("From float64 to myType")
    print(f64array)
    print(myFpArrayfrom_f64)
    print("--------------------------")



    # Convert float64 to my float-point

    myFpArray = np.array(f32array).astype(dtype=_float.myType)
    myFpArrayto_f64 = myFpArray.copy()
    myFpArrayto_f64 = myFpArrayto_f64.astype(dtype=float64)
    print("From myType to float64")
    print(myFpArray)
    print(myFpArrayto_f64)
    print("--------------------------")



def test_ordering():




def main():
    test_consistency()
    test_ordering()

main()
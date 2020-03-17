import _float

def AddCheck(number1, number2):
    sumOfFloats = number1 + number2
    roundingLoss(sumOfFloats)

def SubCheck(number1,number2):
    subOfFloats = number1 - number2
    roundingLoss(subOfFloats)

def MulCheck(number1,number2):
    mulOfFloats = number1 * number2
    roundingLoss(mulOfFloats)

def DivCheck(number1,number2):
    divOfFloats = number1 / number2
    roundingLoss(divOfFloats)

def roundingLossprint(number1):
    number1casted = _float.myType(number1)
    print ("After Casting: "+ str((number1casted)) + " Before Casting: " + str(number1))
    print("Relative error: " +  str(abs((number1casted.castToFloat()) - number1)))
    print("Absolute error: " + str((abs((number1casted.castToFloat()) - number1)/number1)) + " %")
    return (abs((number1casted.castToFloat()) - number1)/number1)

def roundingLoss(number1):
    number1casted = _float.myType(number1)
    return (abs((number1casted.castToFloat()) - number1)/number1)


def testRangeFrom0To1(numberOfProbes):
    mistake_for_range = 0
    for u in range(1,numberOfProbes):
        u = float(u)
        k = float(u/float(numberOfProbes))
        mistake_for_range += roundingLoss(k)
    print ("Absolute error for [0,1] range: " + str(mistake_for_range/numberOfProbes))

def testRangeFrom0To10(numberOfProbes):
    mistake_for_range = 0
    for u in range(1,numberOfProbes):
        u = float(u)
        k = float(float((numberOfProbes)+float(9*u))/float(numberOfProbes))
        mistake_for_range += roundingLoss(k)
    print ("Absolute error for [1,10] range: " + str(mistake_for_range/numberOfProbes))

def testRangeFrom10To1000(numberOfProbes):
    mistake_for_range = 0
    for u in range(1,numberOfProbes):
        u = float(u)
        k = float(float((10*numberOfProbes)+float(990*u))/float(numberOfProbes))
        mistake_for_range += roundingLoss(k)
    print ("Absolute error for [10,1000] range: " + str(mistake_for_range/numberOfProbes))

def testRangeFrom1000To1000000(numberOfProbes):
    mistake_for_range = 0
    for u in range(1,numberOfProbes):
        u = float(u)
        k = float(float((1000*numberOfProbes)+float(999000*u))/float(numberOfProbes))
        mistake_for_range += roundingLoss(k)
    print ("Absolute error for [1000,1000000] range: " + str(mistake_for_range/numberOfProbes))


def main():
    ## Casting test ## 
    testRangeFrom0To1(1000)
    testRangeFrom0To10(1000)
    testRangeFrom10To1000(1000)
    testRangeFrom1000To1000000(1000)

main()
def zeroPad(numberString, zeros, left = True):
    """Return the string with zeros added to the left or right."""
    for i in range(zeros):
        if left:
            numberString = '0' + numberString
        else:
            numberString = numberString + '0'
    return numberString

def karatsuba(num1, num2):

    # Convert to strings for easy access to digits
    num1Str = str(num1)
    num2Str = str(num2)

    """ Karatsuba implementation """
    # Base cases for recursion
    if len(num1Str) == 1 and len(num2Str) == 1:  # Small digit number trivial calculation
        return int(num1Str) * int(num2Str)
    
    if len(num1Str) < len(num2Str):
        # Zero pad num1
        num1Str = zeroPad(num1Str, len(num2Str) - len(num1Str))
    elif len(num2Str) < len(num1Str):
        # Zero pad num2
        num2Str = zeroPad(num2Str, len(num1Str) - len(num2Str))

    n = len(num1Str)
    j = n//2

    # For odd digit integers
    if (n % 2) != 0:
        j += 1

    BZeroPadding = n - j
    AZeroPadding = BZeroPadding * 2
    
    a = int(num1Str[:j])
    b = int(num1Str[j:])
    c = int(num2Str[:j])
    d = int(num2Str[j:])

    ac = karatsuba(a,c)
    bd = karatsuba(b,d)
    k = karatsuba(a+b , c+d)
    ad_plus_bc = k - ac - bd
    
    A = int(zeroPad(str(ac), AZeroPadding, False))
    B = int(zeroPad(str(ad_plus_bc), BZeroPadding, False))

    answer = A + B + bd
    
    return answer

num1 = 3141592653589793238462643383279502884197169399375105820974944592
num2 = 2718281828459045235360287471352662497757247093699959574966967627

print ("The final answer is: ", karatsuba(num1,num2))
# Expected Final answer: 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184
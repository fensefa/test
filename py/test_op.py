#!usr/bin/env python
# -*- coding: utf-8 -*-

def op1(a, b):
    return a + b % 256

def op2(a, b):
    return a ^ b

def op3(a, b):
    a <<= 1
    a %= 256
    return a ^ b

def op4(a, b):
    return (~a % 256 + b) % 256

def op5(a, b):
    return (~a) ^ b

def op6(a, b):
    return (a + b) ^ a

def op7(a, b):
    return (a + b) ^ b

def test_associate(op):
    for a in xrange(10):
        for b in xrange(10):
            for c in xrange(10):
                if op(op(a, b), c) != op(a, op(b, c)):
                    print False, a, b, c
                    return False
    print True
    return True

def test_commutative(op):
    for a in xrange(10):
        for b in xrange(10):
                if op(a, b) != op(b, a):
                    print False, a, b
                    return False
    print True
    return True

def test(op):
    print str(op)
    test_associate(op)
    test_commutative(op)

for op in [op1, op2, op3, op4, op5, op6, op7]:
    test(op)

def op8(a, b):
    c = [0,0]
    c[0] = (a[0] << b[1]) ^ b[0]
    c[1] = a[1] + b[1]
    return c
def test1(op):
    for x in xrange(63):
        for y in xrange(63):
            for z in xrange(63):
                a,b,c = [[i,1] for i in [x,y,z]]
                if op(op(a, b), c) != op(a, op(b, c)):
                    print False, a, b, c
                    return False
    print True
    return True
def test2(op):
    for x in xrange(63):
        for y in xrange(63):
                a,b = [[i,1] for i in [x,y]]
                if op(a, b) != op(b, a):
                    print False, a, b
                    return False
    print True
    return True
print (op8)
test1(op8)
test2(op8)

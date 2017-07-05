#!usr/bin/env python
# -*- coding: utf-8 -*-

import time
import random

def test(func):
    func()
    return func()

@test
def fun():
    print "call fun"

def time_print(func):
    def _func(*arg, **karg):
        print "begin time of %s" % func.func_name,time.time()
        print "Hello, I am func"
        print "end time of %s" % func.func_name,time.time()
        ret = func(*arg, **karg)
        return ret
    return _func

@time_print
def fun2():
    print "I am fun2"

def multi_call(n):
    def _deco(func):
        def __deco(*arg, **karg):
            for i in range(n):
                print "call func %s time %d" % (func.func_name, i + 1)
                ret = func(*arg, **karg)
            return ret
        return __deco
    return _deco

def deco(func):
    print("before myfunc() called.")
    func()
    print("  after myfunc() called.")
    return func
@deco 
def myfunc():
    print(" myfunc() called.")


@multi_call(8)
def print_rand():
    print random.randint(0,20)

if __name__ == "__main__":
    fun
    fun2()
    print_rand()
    myfunc()

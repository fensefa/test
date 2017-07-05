#!usr/bin/env python
# -*- coding: utf-8 -*-

from concurrent import futures
n = 10000000

sum = 0
def fun(a,b):
    local_sum = 0
    t = 1.0 / n
    while b < n:
        x = t * b
        local_sum += 1 / (1 + x * x) * t
        b += a
    print 'local sum',local_sum
    return local_sum
count = 0
def fun2(future):
    print future.result()
def fun3(future):
    global sum, count
    sum += future.result()
    count += 1
    if count == 4:
        print sum * 4
executor = futures.ProcessPoolExecutor(max_workers=4)
future = executor.submit(fun,4,0)
future.add_done_callback(fun3)
future = executor.submit(fun,4,1)
future.add_done_callback(fun3)
future = executor.submit(fun,4,2)
future.add_done_callback(fun3)
future = executor.submit(fun,4,3)
future.add_done_callback(fun3)

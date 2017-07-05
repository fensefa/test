#!usr/bin/env python
# -*- coding: utf-8 -*-

import time
import threading

from concurrent import futures

def fun(n):
    time.sleep(2)
    print n
    return -n
def fun2(future):
    print future.result()
executor = futures.ProcessPoolExecutor(max_workers=5)
future = executor.submit(fun,1)
future.add_done_callback(fun2)
future = executor.submit(fun,2)
future.add_done_callback(fun2)
future = executor.submit(fun,3)
future.add_done_callback(fun2)

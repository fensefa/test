#!usr/bin/env python
# -*- coding: utf-8 -*-

import multiprocessing
import time

abc = [1, 2, 3, 4, 5]

def add(n):
    time.sleep(1)
    print n
    return n + 1
pool = multiprocessing.Pool(5)
print map(add, abc)

if __name__ == '__main__':
    print pool.map(add, abc)

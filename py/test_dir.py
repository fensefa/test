#!usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import os
print sys.path[0]

def path_1():
    return sys.path[0]
def path_2():
    return sys.path
def path_3():
    return __file__
def path_4():
    return os.path.realpath(__file__)
def path_5():
    return os.path.split(os.path.realpath(__file__))[0]

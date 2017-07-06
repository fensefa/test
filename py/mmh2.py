#!usr/bin/env python
# -*- coding: utf-8 -*-

import struct

mod_base = 2 ** 64

def Hash64A(key, seed):
    length = len(key)
    data = [ord(i) for i in key]

    m = 0xc6a4a7935bd1e995
    r = 47

    h = seed ^ (length * m % mod_base)

    i = 0
    while (i + 8 <= length):
        k = struct.unpack("Q", key[i: i + 8])
        k = k[0]

        k *= m
        k %= mod_base
        k ^= k >> r
        k *= m
        k %= mod_base

        h ^= k
        h *= m
        h %= mod_base

        i += 8

    switcher = length & 7
    for j in range(switcher):
        h ^= (data[j+i] << (j * 8))
    if (switcher >= 1):
        h *= m
        h %= mod_base

    h ^= h >> r
    h *= m
    h %= mod_base
    h ^= h >> r
    return h

def hash_test(file_name):
    for x in open(file_name).read().strip().split('\n'):
        print x,Hash64A(x,0)

if __name__ == '__main__':
    hash_test("1.txt")

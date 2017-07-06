#!usr/bin/env python
# -*- coding: utf-8 -*-

import logging
logging.basicConfig(level=logging.DEBUG,
    format='%(asctime)s %(filename)s:%(lineno)d [%(levelname)s] %(message)s',
    datefmt='%a, %d %b %Y %H:%M:%S',
    filename='myapp.log',
    filemode='a')

logging.error("this is a error")
logging.warn("this is a warn")
logging.info("this is a info")
logging.debug("this is a debug")

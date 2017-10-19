#!/bin/bash
{
    flock -n 3
    [ $? -eq 1 ] && { echo fail; exit; }
    echo $$
} 3<>mylockfile

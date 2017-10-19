#!/usr/bin/env bash

if [ $# -lt 3 ]
then
    echo Usage: sh lock_run.sh sleep_interval lock_file command
    exit
fi

sleep_interval=$1
lock_file=$2
shift 2
cmd=$@
lock_pid=$(cat $lock_file)
process_num=$(/bin/ps aux | awk '$2 == "'$lock_pid'"' |wc -l)
while [ ${process_num}"" -gt 0 ]
do
    echo pwd : $(cat $lock_file.pwd)
    echo cmd : $(cat $lock_file.cmd)
    echo ${lock_pid} $lock_pwd $lock_cmd is running, now sleep $sleep_interval seconds
    sleep $sleep_interval
    lock_pid=$(cat $lock_file)
    process_num=$(/bin/ps aux | awk '$2 == "'$lock_pid'"' |wc -l)
done
echo $$ > ${lock_file}
echo $(pwd) > ${lock_file}.pwd
echo $cmd > ${lock_file}.cmd
eval $cmd

#!/bin/bash


function endless_loop()
{
        while : ; do : ; done
}

echo 20000 >/sys/fs/cgroup/cpu/test/cpu.cfs_quota_us

endless_loop &

pid=$!

echo "pid: $pid"

sleep 2

top -p $pid -n 2

echo "cat $pid > /sys/fs/cgroup/cpu/test/tasks"
sleep 2

echo $pid > /sys/fs/cgroup/cpu/test/tasks
cat /sys/fs/cgroup/cpu/test/tasks

sleep 1

top -p $pid -n 2

kill $pid

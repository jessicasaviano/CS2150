#!/bin/bash

echo 'Dictionary file: '
read dictionary

echo 'Grid file: '
read grid

RUNNING_TIME_1=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME_2=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME_3=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME_4=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME_5=`./a.out $dictionary $grid | tail -1`



total_time_sum=$((RUNNING_TIME_1+RUNNING_TIME_2+RUNNING_TIME_3+RUNNING_TIME_4+RUNNING_TIME_5))
total_count=5
average_time=$((total_time_sum/total_count))
echo "average in milliseconds: "
echo $average_time





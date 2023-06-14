

total_count=5
total_time=0

echo 'enter the exponent for counter.cpp: '
read value

if [[ $value == "quit" ]] ; then
    exit 1
fi

avg=0
for(( i = 0; i <= total_count; i++ )) ; do

    echo 'Running iteration' $i'...'
    time=`./a.out $value`
    total_time=$((time+total_time))
    echo 'time taken:' $time' ms'
done
echo '5 iterations took' $total_time 'ms'
avg=$((total_time/total_count))
echo 'Average time was' $avg' ms'
    

    
    
    
    


    

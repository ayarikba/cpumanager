#! /bin/bash

freq=2000000
core_count=0

change_freq(){
    local path=$1
    local freq_path="${path}"
    echo ${freq_path}
    echo ${freq} | sudo tee ${freq_path}
}

change_freq_for_cores() {
    core_count=$(tac /proc/cpuinfo | grep -m1 "processor" | grep -o '[0-9]\+')

    for ((i=0; i<=core_count; i++)); do
        tmp="/sys/devices/system/cpu/cpu${i}/cpufreq/scaling_max_freq"
        ##echo $tmp
        change_freq ${tmp}
    done
}

change_freq_for_cores
echo "All cpu max freqs are changing to 2.0GHZ"



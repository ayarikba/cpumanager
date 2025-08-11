#! /bin/bash

freq=1600000
core_count=0
scaling_governor="powersave"

change_freq(){
    local path=$1
    local freq_path="${path}/cpufreq/scaling_max_freq"
    echo ${freq_path}
    echo ${freq} | sudo tee ${freq_path}
}


change_freq_governor_to_powersave(){
    local path=$1
    local governor_path="${path}/cpufreq/scaling_governor"
    local available_governor_path="${path}/cpufreq/scaling_available_governors"
    local result=$(cat ${available_governor_path} | grep -count ${scaling_governor}) 
    
    if ((result!=0)); then
        echo ${scaling_governor} | sudo tee ${governor_path}
    fi
}


change_freq_for_cores() {
    core_count=$(tac /proc/cpuinfo | grep -m1 "processor" | grep -o '[0-9]\+')

    for ((i=0; i<=core_count; i++)); do
        tmp="/sys/devices/system/cpu/cpu${i}"
        ##echo $tmp
        change_freq ${tmp}
        # change_freq_governor_to_powersave ${tmp}
    done
}

change_freq_for_cores

echo "All cpu max freqs are changing to 2.0GHZ"



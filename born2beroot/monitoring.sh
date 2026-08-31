#!/bin/bash

# ARCHITECTURE
ARCH=$(dpkg --print-architecture)

#CPU
PHYSICAL_CPU=$(lscpu | grep "CPU(s)" | awk 'NR==1{print $2}')
VIRTUAL_CPU=$(nproc)
CPU_USAGE=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')


#MEMORY
MEMORY_POURCENT=$(free --mega | grep Mem: | awk '{printf ("%i%%",($3/$2)*100)}')
MEMORY_TOTAL=$(free --mega | grep Mem: | awk '{printf ("%i", $2)}')
MEMORY_USAGE_MB=$(free --mega | grep Mem: | awk '{printf ("%i", $3)}')

#NETWORK
IP_ADDR=$(hostname -I)
IP_MAC=$(ip link | grep link/ether | cut -b 16-32 | head -1)
TCP_ESTABLISHED=$(ss -taH state established | wc -l)

#DISK
IS_LVM=$(if [ $(lsblk |grep lvm | wc -l) -gt 0 ]; then echo "yes"; else echo "no"; fi)
DISK_TOTAL=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{total += $2} END {print total}')
DISK_USAGE=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} END {print used}')
DISK_POURCENT=$(df --output=used,size -x tmpfs -x devtmpfs | awk 'NR>1 {used+=$1; total+=$2} END {printf "%.1f", (used/total)*100}')
#DISK_POURCENT=$(($(lsblk --output SIZE -n -d /dev/sda | awk '{print $1}'))*100)

#OTHER
LAST_REBOOT_DATE=$(last reboot | head -1 | awk '{printf ("%s %s %s %s\n", $5, $6, $7, $8)}')
SUDO_CMD=$(journalctl _COMM=sudo | grep COMMAND= | wc -l)
NB_USER_LOG=$(w -h | wc -l)

echo "+-----------------+
| ARCHITECTURE    : $ARCH
+-----------------+ 
| PHYSICAL CPU    : $PHYSICAL_CPU
+-----------------+
| VIRTUAL CPU     : $VIRTUAL_CPU
+-----------------+
| MEMORY USAGE    : $MEMORY_USAGE_MB/${MEMORY_TOTAL}MB ($MEMORY_POURCENT)
+-----------------+
| DISK USAGE      : $DISK_USAGE/$DISK_TOTAL GB ($DISK_POURCENT%)
+-----------------+
| CPU USAGE       : $CPU_USAGE
+-----------------+
| LAST BOOT       : $LAST_REBOOT_DATE
+-----------------+
| USE LVM ?       : $IS_LVM
+-----------------+
| CONNECTIONS TCP : $TCP_ESTABLISHED
+-----------------+
| USER LOG        : $NB_USER_LOG
+-----------------+
| NETWORK         : $IP_ADDR ; $IP_MAC
+-----------------+
| SUDO            : $SUDO_CMD
+-----------------+"

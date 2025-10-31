#!/bin/bash

# ARCHITECTURE
ARCH=$(uname -a)

#CPU
PHYSICAL_CPU=$(lscpu | grep "CPU(s)" | awk 'NR==1{print $2}')
VIRTUAL_CPU=$(nproc)
CPU_USAGE=$(vmstat | awk 'NR==3{printf ("%d\n", 100-$15)}')


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
DISK_TOTAL=$(lsblk --output SIZE -n -d /dev/sda | awk '{print $1}')
DISK_TOTAL_IN_MB=$(lsblk -b --output SIZE -n -d /dev/sda | awk '{print $1}')
#DISK_POURCENT=$(($(lsblk --output SIZE -n -d /dev/sda | awk '{print $1}'))*100)

#OTHER
LAST_REBOOT_DATE=$(last reboot | head -1 | awk '{printf ("%s %s %s %s\n", $5, $6, $7, $8)}')
SUDO_CMD=$(journalctl _COMM=sudo | grep COMMAND= | wc -l)
NB_USER_LOG=$(w -h | wc -l)

echo -e "+-----------------+
| ARCHITECTURE    : $ARCH
+-----------------+ 
| PHYSICAL CPU    : $PHYSICAL_CPU
+-----------------+
| VIRTUAL CPU     : $VIRTUAL_CPU
+-----------------+
| MEMORY USAGE    : $MEMORY_USAGE_MB/${MEMORY_TOTAL}MB ($MEMORY_POURCENT)
+-----------------+
| DISK USAGE      : $DISK_TOTAL
+-----------------+
| CPU USAGE       : %
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
+-----------------+
| TIME NOW        : $(date -R)
+-----------------+\n"

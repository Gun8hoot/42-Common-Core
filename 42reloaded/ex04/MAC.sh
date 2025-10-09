#!/bin/bash

ifconfig | grep "Ethernet" | cut -b 15-31

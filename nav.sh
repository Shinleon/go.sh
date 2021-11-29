#!/bin/bash

NAV_LOC="$HOME/bin/nav"
DATA_LOC="nav_data/directory_alias.csv"

C_NAV="$NAV_LOC/nav.out"

# we could check if go.out exists, 
#  if not, record current directory, go to the go directory, make,
#  and go back to the recorded directory

$C_NAV $NAV_LOC/$DATA_LOC $@
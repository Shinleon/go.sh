#!/bin/bash

GO_LOC="$HOME/bin/go"
DATA_LOC="go_data/directory_alias.csv"

C_GO="$GO_LOC/go.out"

# we could check if go.out exists, 
#  if not, record current directory, go to the go directory, make,
#  and go back to the recorded directory

$C_GO $GO_LOC/$DATA_LOC $@
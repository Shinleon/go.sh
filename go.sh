#!/bin/bash

# run as source or this can't move directories but mess up

# echo number of parameters $#
# for argument in $@
# do
#     echo $argument 
# done

PY_GO="~/bin/go/go.py"
if [ $# -gt 2 ]
then
    echo "This script doesn't need more than two parameters"
elif [ $# -eq 2 ]
then
    # echo "There's a command and an alias"
    # echo "assuming current directory is the directory"
    a=`python3 $PY_GO $1 $2`
    echo $a
elif [ $# -eq 1 ]
then
    #echo "We're gonna try to move to the directory"
    if [ -d $1 ]
    then
        cd $1
        ls -liFAG
    else
        #echo "\"$1\" doesn't exist as a directory"
        #echo "going to check aliases"
        a=`python3 $PY_GO $1`
        # echo $a
        if [ -d $a ]
        then 
            cd $a
            ls -liFAG
        else
            echo "No such directory or alias \"$1\""
        fi
    fi
else
    a=`python3 $PY_GO`
    echo
    echo "The command \`go\` is meant to help with navigation. It's purpose is for you"
    echo "to store commonly used directories as aliases and be able to easily navigate"
    echo "to them by typing \"go <alias>\". Of course you will need to be able to add"
    echo "and remove alias directories so there are two variations that come with \`go\`"
    echo "In order to get full results please run by prepending \`source\` so that the"
    echo "script is capable of changing directories"
    echo
    echo "The possible entry formats are"
    echo "1:: go add <alias>  # which assumes the current directory is the one to alias as"
    echo "2:: go rm  <alias>"
    echo "3:: go <directory or alias>"
    echo "4:: go # which will print out this help message"
    echo
    echo "list of [current aliases, directories]"
    echo $a
    
fi

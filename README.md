# go.sh

Personal navigator

## Installation instructions

Personally, I recommend creating a '/bin' folder in the $HOME directory and then creating a directory for this specific script inside of that 'bin' folder.

There are three volitile parts in terms of running on another machine:
1) Where the python script 'go.py' is
2) Where the csv 'directory_alias.csv' is
3) How the python script is run

The $PY_GO variable in the 'go.sh' file will need to point to the accompanying python script, so you might have to modify that path. 
Also, the variable 'csv_location' in 'go.py's init function will need to point to where you want the csv of aliases to be. 
The last part is that you may need to change how python is run/calling the script, so the $PYTHON variable in 'go.sh' should point to a valid python environment

Those are the three volitile parts in terms of running on another machine.

In order to easily run the program, I use 
> alias go="source $HOME/bin/go/go.sh" 

so that I can simply type
> go \<parameters\>

to use the script but you can also modify your $PATH variable if you want to, which might make sense, especially if you're going for the 'bin' folder.

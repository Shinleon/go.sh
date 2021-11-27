# go.sh

Personal navigator (Getting rewritten in C because I cannot add in the levenshtein distance correction how I want to if it's in Python)
*NOTICE: This version doesn't work yet. This notice will be removed when it does*
## Installation instructions

Personally, I recommend creating a '/bin' folder in the $HOME directory and then creating a directory for this specific script inside of that 'bin' folder.

There are three moving parts in terms of running on another machine:
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

## Bit about how it works
If you type 'go \<directory or alias\>', the program will first check the directories and then
the aliases. This means that if you attempt to create an alias to a directory using the tilde 
or a string that is a valid path, it won't work properly. 

If you just type 'go alias \~', the shell you're using will just expand the tilde to the home 
directory, and if you type 'go \<your home directory\>', as it checks for directories then alises,
you'll just end up going to the home directory instead of the directory where you originally
intended to alias to.
If you type "go alias '\~'" , the tilde won't be automatically expanded, but if you attempt to type
'go \~' in order to use the alias, the tilde will be then automatically expanded to your home
directory, placing you in your home directory instead of the directory where you wanted to alias
to. You could get around this and use the tilde as an alias by typing 'go "\~"' which will then
be properly interpreted by both the shell and the go script as wanting to go to the directory
that the go script has recorded under the name '\~'.

Either way, just don't bully the script or you'll end up
confusing the script on where it is you're tring to go.


## Things to add
- recommendations if you misspell things. 
- Fuzzy search(?) 
- tab autocomplete for aliases not just directories (https://stackoverflow.com/a/31075108)
## CSV dissection

CSV's are pretty simple; comma-delimited fields in each row the same number of fields
per row as any other row, hopefully. If it doesn't, well we'll know when we try
to load it, and it'll complain.

The implementation I'm going for is going to just load in the whole csv file into a 
2D array of strings; hopefully, I'll be able to then do operations such as find me
the fifth field in the row whose value in the first field is *x*. I'll basically
be mimicing the c interpretation of csv found in the [Python Documentation](https://docs.python.org/3/library/csv.html).

## Implementation

With the goal of taking in a csv, there are a couple things I have in mind.
- I want a generic csv writer like the python one
- I want a generic csv reader like the python one
- After that
    - I want to be able to find a row by specifying a column number and a value quickly.
    - I want to be able to find all rows with a specific value in a field quickly.
    - I want to be able to create a another csv of a current one where the csv is sorted by a field.
    - I want to be able to quickly append, and insert in a specific location.
    - I want to be able to change a field value in a specific row quickly.

In order to do this, I need to make a lexer
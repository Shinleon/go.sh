## CSV dissection

CSV's are pretty simple; comma-delimited fields in each row the same number of fields
per row as any other row, hopefully. If it doesn't, well we'll know when we try
to load it, and it'll complain.

The implementation I'm going for is going to just load in the whole csv file into a 
2D array of strings; hopefully, I'll be able to then do operations such as find me
the fifth field in the row whose value in the first field is *x*. I'll basically
be mimicing the c interpretation of csv found in the [Python Documentation](https://docs.python.org/3/library/csv.html).
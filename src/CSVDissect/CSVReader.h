
#ifndef CSV_DISSECT_H
#define CSV_DISSECT_H

// I think there is no occassion where we need to hand the entire dataset to the user
// If they want something like that, then can iterate through the csv and construct it
//   themselves.
// struct CSVData {
//     int row_quant;          // how many rows are in the csv file
//     int col_quant;          // how many fields per row in csv
//     char*** all_data;       // holds the data
// };

// https://specs.frictionlessdata.io/csv-dialect/#usage
struct CSVDialect
{
    char delimiter;       // default to ','
    char *lineTerminator; // default to "\r\n"
    char quoteChar;       // default to '"'
    int doubleQuote;      // default to 1/true
    char escapeChar;      // default to '\\'
    char nullSequence;    // default to '\0'. shouldn't be set by default
    int skipInitialSpace; // default to 0/false
    // int header              // it doesnt' matter if there is a header, user can parse
    char commentChar; // default to '#'? Not sure what else to do
    // int caseSensitiveHeader; // it doesn't matter, as headers are of no concern
    char *csvddfVersion;  // default to NULL, Not sure if this is going to be useful
};

// The goal is to read out the csv file one line at a time, given a dialect
struct CSVReader
{
    FILE* f;
    struct CSVDialect* dialect;
};

// completely un-necessary for reading, maybe when making the writer.
// // needed for CSV writer
// // look here [https://stackoverflow.com/a/10631901] for considering writing using fseek.
// enum CSVQuotingStyle {
//     QUOTE_NONE = 3,
//     // QUOTE_NONNUMERIC = 2,   // There's no point in having this option.
//     QUOTE_MINIMAL = 1, 
//     QUOTE_ALL = 0
// }; 

struct CSVReader* makeCSVReader(
    const char *file, char delimiter, char quoteChar);

#endif

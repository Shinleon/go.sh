
#ifndef CSV_DISSECT_H
#define CSV_DISSECT_H

struct CSVData {
    int row_quant;          // how many rows are in the csv file
    int col_quant;          // how many fields per row in csv
    char*** all_data;       // holds the data
};

struct CSVReader
{
    FILE* f;
};

// needed for CSV writer
// look here [https://stackoverflow.com/a/10631901] for considering writing using fseek.
enum CSVQuotingStyle {
    QUOTE_NONE = 3,
    QUOTE_NONNUMERIC = 2,
    QUOTE_MINIMAL = 1, 
    QUOTE_ALL = 0
}; 

struct CSVReader* makeCSVReader(
    const char *file, char delimiter, char quoteChar);

#endif

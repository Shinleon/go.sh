
#ifndef CSV_DISSECT_H
#define CSV_DISSECT_H

struct CSVHeaders
{
    char** headers;
    int length;
};

struct CSVData {
    struct CSV_Header* h;   // holds a header (if indicated that the csv has one)
    int row_quant;          // how many rows are in the csv file
    int col_quant;          // how many fields per row in csv
    char*** all_data;       // holds the data
};

struct CSVFileReader
{
    FILE* f;
    struct CSVData* data;
};

enum CSVQuotingStyle {
    QUOTE_NONE = 3,
    QUOTE_NONNUMERIC = 2,
    QUOTE_MINIMAL = 1, 
    QUOTE_ALL = 0
}; 

struct CSVFileReader* makeCSVFileReader(
    const char *file, int headers, char quoteChar, enum CSVQuotingStyle style);

#endif

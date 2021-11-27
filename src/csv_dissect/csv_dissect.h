
#ifndef CSV_DISSECT_H
#define CSV_DISSECT_H

struct CSVHeaders
{
    char** headers;
    int length;
};

struct CSVFileReader
{
    FILE* f;
    struct CSV_Headers* h;
    int row_quant;
    int col_quant;
    char*** all_data;

};

struct CSVFileReader* makeCSVFileReader(const char* file, int headers, int load);

#endif

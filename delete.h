#ifndef DELETE_H
#define DELETE_H

void delete_table(char *db_name, char *table_name);
void delete_database(char *db_name);
void delete_column(char *db_name, char *table_name, char *column);
void delete_row(char *db_name, char *table_name, int row_number);

#endif

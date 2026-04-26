# dbms_using_C<br><br>
## task division<br>
1. Erica - create database and table<br>
2. Madhi - insert and select data<br>
3. Isha - delete database and table or data<br><br>

## program flow<br>
main menu<br>
|_ create<br>
    &nbsp;&nbsp;&nbsp;&nbsp;|_ Database<br>
        &nbsp;&nbsp;&nbsp;&nbsp;|_ must create a folder with giver name (can use mkdir command)<br>
        &nbsp;&nbsp;&nbsp;&nbsp;|_ must include a file named tableNames.txt which contains all the files name that is in the databse and should be appended as new files are created<br>
        &nbsp;&nbsp;&nbsp;&nbsp;|_ must check if database name is unique or not, if the name contains any whitespaces or not, or contains an extension like .txt, .docx, etc. if found invalid database and re-ask user<br>
    &nbsp;&nbsp;&nbsp;&nbsp;|_ Table<br>
        &nbsp;&nbsp;&nbsp;&nbsp;|_ must create a .txt and .csv file<br>
        &nbsp;&nbsp;&nbsp;&nbsp;|_ .txt must contains the number of columns, and primary key(if available)<br>
        ```
        this_is_TableName.txt
        numbersOfColumns<SPACE>primaryKey
        (%d %d)
        ```

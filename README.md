# dbms_using_C

## Task Division
1. Erica – Create database and table  
2. Madhi – Insert and select data  
3. Isha – Delete database, table, or data  

---

## Program Flow

### Main Menu

#### 1. Create
- **Database**
  - Create a folder with the given name (use `mkdir`)
  - Include a file named `tableNames.txt`
    - Stores all table names
    - Append new names when tables are created
  - Validate:
    - Name must be unique
    - No whitespace allowed
    - No extensions like `.txt`, `.docx`, etc.

- **Table**
  - Create both `.txt` and `.csv` files
  - `.txt` stores metadata:

```
this_is_TableName.txt
numbersOfColumns primaryKey
(%d %d)
```

---

#### 2. Insert
- User provides database name and table name  
- Validate if both exist  
- Take input for all columns  
- Append data into `.csv` file  
- Ensure primary key uniqueness  

---

#### 3. Select
- User provides database name and table name  
- Display all records from `.csv`  
- Optional:
  - Filter using condition  
  - Format: `column = value`  

---

#### 4. Delete

- **Database**
  - Delete the database folder  

- **Table**
  - Delete corresponding `.txt` and `.csv` files  

- **Data**
  - Input:
    - Database name  
    - Table name  
    - Condition (`column = value`)  
  - Process:
    - Read `.csv`
    - Copy non-matching records into a temporary file
    - Replace original file with updated file  

---

## Important Notes
- Always validate user input to avoid invalid names and crashes  
- Keep `.txt` (metadata) and `.csv` (data) consistent  
- Use temporary files when modifying or deleting data  
- Enforce primary key uniqueness strictly  

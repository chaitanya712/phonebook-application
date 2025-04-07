# Phonebook-application
## Compiling commands 
```bash
gcc -c src/sqlite3.c -o build/sqlite3.o
g++  build/sqlite3.o -std=c++17 src/*.cpp -Iinclude -o phonebook.exe -lpthread 
```
## Run command
```bash
./phonebook.exe
```

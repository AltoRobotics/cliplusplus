# Timida reimplementazione delle coreutils

In src ci vanno i comandi.
In test le asserzioni che testano che i comandi siano eseguiti e che l'output sia conforme.

Per semplicitá al momento i test che si invocano con 

    make test 

o

    ninja test

ma cercano gli eseguibili sotto ../src : tenetene conto se modificate la build.

# Dipendenze

La prima dipendenza che ho utilizzato è 

* **Tiny-process-library** https://gitlab.com/eidheim/tiny-process-library che permette di interagire con i processi del sistema

# Comandi

**true**  https://man7.org/linux/man-pages/man1/true.1.html - senza option

**false**  https://man7.org/linux/man-pages/man1/false.1.html - senza option

# Ispirazione

L'ispirazione arriva dal libro __Command-Line Rust__ di Ken Youens-Clark. 

https://www.amazon.com/Command-Line-Rust-Project-Based-Primer-Writing/dp/1098109430
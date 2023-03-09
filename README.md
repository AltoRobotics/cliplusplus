# Timida reimplementazione delle coreutils

In src ci vanno i comandi.
In test le asserzioni che testano che i comandi siano eseguiti e che l'output sia conforme.

Per semplicitá al momento i test che si invocano con 

    make test 

o

    ninja test

ma cercano gli eseguibili sotto ../src : tenetene conto se modificate la build.

# Implementation

**true**  https://man7.org/linux/man-pages/man1/true.1.html - senza option

**false**  https://man7.org/linux/man-pages/man1/false.1.html - senza option
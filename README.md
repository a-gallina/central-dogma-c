# Central Dogma C Translator
Un tool scritto in C per convertire sequenze genomiche dal formato FASTA in sequenze amminoacidiche, seguendo il dogma centrale della biologia molecolare (DNA --> RNA --> Proteina).

## Funzionalità
* Lettura e parsing di file ".fasta" 
* Tracsrizione da DNA a RNA
* Traduzione da RNA a polipeptide tramite tabella dei codoni ottimizzata.

## Compilazione
Per compilare il programma utilizzando GCC su ambiente Linux:

gcc -o translator main.c fasta_io.c translator.c

## Utilizzo
Passare il file FASTA come argomento:

./translator sequenza.fasta

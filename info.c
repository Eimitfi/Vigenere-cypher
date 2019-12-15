#include "info.h"

void intro(){
printf("Salve!\nQuesto software utilizza il crittogramma di Vigenere per crittare/decrittare dei semplici testi;\n");
printf("per leggere le info inserire 'S' altrimenti inserire qualsiasi altra lettera ->  ");
}

void info_crittografia(){
printf("\n");
        printf("Questo metodo di cifratura utilizza una chiave per crittare e decrittare testo.\n");
        printf("Per questo e' necessario che sia la sorgente sia la destinazione del messaggio conoscano la chiave.\n");
        printf("Per molto tempo questo sistema e' stato ritenuto inviolabile;\n");
        printf("fu Kasiski però il primo a trovare un modo per forzare il sistema trovando un modo per dedurre la chiave.\n");
        printf("Ma niente panico, prendendo alcuni accorgimenti si puo' creare un testo indecifrabile (a patto che la chiave rimanga segreta):\n");
        printf("1) la chiave deve essere lunga almeno quanto il testo;\n");
        printf("2) la chiave deve essere generata automaticamente e non deve avere nessun significato;\n");
        printf("3) la chiave deve essere usata una sola volta;\n\n\n");
        printf("Programma OpenSource scritto da Iftimie D.M. per scopi didattici; il codice sorgente e' liberamente consultabile/modificabile.\n");
        printf("Per suggerimenti e/o modifiche scrivere a miftimie99@gmail.com\nPer eventuali lamentele scrivere a fake_mail@fake.fk\n\n");
}

void info_testo(){

printf("\nalcuni accorgimenti per il testo da cifrare:\n");
printf("1) le eventuali maiuscole verranno convertite in minuscole\n");
printf("2) gli unici caratteri ammessi sono quelli dell'alfabeto inglese,tutti i caratteri speciali,numeri e caratteri accentati non sono accettati\n");
printf("3) in caso di inserimento di caratteri non permessi il testo verrà crittato comunque, ma verranno tralasciati i caratteri non permessi\n");
printf("inserire il testo da cifrare:\n");



}

void info_chiave(){
printf("\nQuale chiave si vuole utilizzare?\n");
printf("\nPer crittare con una propria chiave inserire 'S'\n");
printf("Per i caratteri della chiave valgono le stesse regole dei caratteri del testo, ma in più non si possono inserire spazi\n");
printf("Nel caso sia presente un carattere proibito nella chiave, essa dovrà essere reinserita senza il carattere vietato\n");
printf("Per crittare con una chiave generata senza significato e lunga quanto il testo inserire 'N'(consigliato)\n");

}
void info_testo_cifrato(){
printf("\nInserire il testo cifrato da decifrare:");


}

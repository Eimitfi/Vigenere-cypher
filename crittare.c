#include "crittare.h"

void gestione_cifratura(){
int counter=0;
list testo=NULL;
do{
info_testo();
testo=get_testo(&counter);//chiamata a funzione che prende il testo
}while(counter==0);//controllo esistenza del testo 
int corretto=FALSE;
list chiave=NULL;
info_chiave();
do{
char ch;
ch=getchar();
while(getchar()!='\n' && ch!=EOF);
if(ch=='S' || ch=='s'){
corretto=TRUE;
chiave=get_chiave();//chiamata a funzione che prende la chiave dall'utente
}else if(ch=='N' || ch=='n'){
corretto=TRUE;
chiave=make_chiave(counter);//chiamata a funzione che genera la chiave casuale
}else{
printf("carattere errato, riprovare con 'S' o 'N'");
}
}while(!corretto);//controllo se l'utente inserisce un carattere non permesso
list testo_cifrato=algoritmo_cifratura(testo,chiave);//chiamata alla funzione che si occupa della cifratura
//stampa dei risultati
printf("questo era il testo originale:\n");
showlist(testo);
printf("questa è la chiave, custodiscila con cura e condividila con chi deve decifrare il testo\n");
showlist(chiave);
printf("questo è il testo cifrato\n");
showlist(testo_cifrato);
//deallocazione delle liste
freelist(testo);
freelist(chiave);
freelist(testo_cifrato);
}

void gestione_decifratura(){
int counter=0;
list testo_cifrato=NULL;
do{
info_testo_cifrato();
testo_cifrato=get_testo(&counter);//funzione che prende il testo cifrato dall'utente
}while(counter==0);
list chiave= NULL;
chiave=get_chiave();//funzione che prende la chiave dall'utente
list testo=algoritmo_decifratura(testo_cifrato, chiave);//funzione che si occupa della decifratura del testo crittato
//stampa dei risultati
printf("questo è il testo in chiaro:\n");
showlist(testo);
printf("questa è la chiave utilizzata per decifrare il testo\n");
showlist(chiave);
printf("questo è il testo cifrato inserito\n");
showlist(testo_cifrato);
//deallocazione delle liste
freelist(testo);
freelist(chiave);
freelist(testo_cifrato);
}

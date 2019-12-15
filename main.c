#include "element.h"
#include "crittare.h"
int main(){
int corretto=FALSE, errori=0;
char info, azione;
intro();
info=getchar();
	if(info=='s' || info=='S'){
	info_crittografia();
	}
char c;
while(c=getchar()!='\n' && c!=EOF );//pulizia del buffer input; l'utente potrebbe aver inserito più di una sola lettera
printf("\ncosa si intende fare?\n");
do{			//ciclo per permettere di reinserire il carattere in caso di errore
	printf("per crittare inserire 'C', per decrittare inserire 'D' ->  ");
	azione=getchar();
	while(c=getchar()!='\n' && c!=EOF);//pulizia del buffer input; l'utente potrebbe aver inserito più di una sola lettera
	if(azione=='c' || azione=='C'){
	gestione_cifratura();
	corretto=TRUE;
	}else if(azione=='d' || azione=='D'){
	gestione_decifratura();
	corretto=TRUE;
	}else{
	errori++;
	printf("carattere errato, riprova:\n");
	}
	if(errori==15){
	printf("\n\nse vuoi possiamo continuare all'infinito, vediamo chi molla per primo...\n\n");//easter egg, se l'utente sbaglila 15 volte stampa questa stringa
	errori=0;
	}
}while(!corretto);
}

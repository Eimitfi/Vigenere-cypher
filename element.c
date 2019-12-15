#include "element.h"

void riempi_matrice(char matrice[][DIM]){//funzione che genera la matrice utilizzata per crittare e decrittare 
int i=0, j=0;
char ch='a', scorri='a';    //la variabile scorri è quella che permette di scrivere la lettera seguente a ogni inizio di riga
	for(i;i<26;i++){
        	for(j;j<DIM;j++){
        	matrice[i][j]=ch;
        		if(ch=='z'){ //questo if controlla che non vengano scritti in una riga simboli al di fuori di a"---"z"
        		ch='a';
        		}else{
        		ch=ch+1;
        		}
        	}
	j=0;
	scorri=scorri+1;
	ch=scorri;
	}
}

list get_testo(int * counter){//funzione che si occupa di prendere il testo da crittare
(*counter)=0;
list temp=NULL;
char ch;
while((ch=getchar())!='\n'){
int permesso=FALSE;
if(ch>='A' && ch <='Z'){
ch=tolower(ch);
}
if((ch>='a' && ch<='z') || ch==' '){
permesso=TRUE;
}
if(permesso==TRUE){//controllo che il carattere da inserire nella lista sia permesso
temp=add(ch,temp);//funzione che inserisce in fondo a una lista un carattere
(*counter)++;
}
}

return temp;

}


list get_chiave(){//funzione che si occupa di prendere la chiave dall'utente
int non_corretto=TRUE;
list temp=NULL;
char ch;
do{
printf("Inserire la chiave:");
non_corretto=FALSE;
while((ch=getchar())!='\n' && ch!=EOF){//scelta di progetto:controllare ogni carattere, anche se sono già stati trovati caratteri non conformi
if(ch>='A' && ch <='Z'){
ch=tolower(ch);
}
if((ch>='a' && ch<='z')){
temp=add(ch,temp);
}else{
non_corretto=TRUE;
}
}
if(empty(temp)){
non_corretto=TRUE;

}
if(non_corretto){
freelist(temp);//se viene inserito un carattere non conforme la lista viene cancellata e si ricomincia
list temp=NULL;
printf("nella chiave e' presente un carattere non consentito\n");
}
}while(non_corretto);

return temp;
}


list make_chiave(int counter){
list temp=NULL;
time_t tempo;
char ch;
srand((unsigned) time(&tempo));
for(int i=0;i<counter;i++){
ch=rand() % 26+97;//inserisco un carattere random nella lista
temp=add(ch,temp);
}
return temp;
}

int trova_colonna(char ch,char matrice[][DIM]){
int colonna;
int trovato=FALSE;
for(int i=0;i<DIM && trovato==FALSE;i++){//scorre la matrice fino a che non trova il carattere giusto
if(ch==matrice[0][i]){
colonna=i;
trovato=TRUE;
}
}
return colonna;
}

int trova_riga(char ch,char matrice[][DIM]){
int riga;
int trovato=FALSE;
for(int i=0;i<DIM && trovato==FALSE;i++){//scorre la matrice fino a che non trova il carattere giusta
if(ch==matrice[i][0]){
riga=i;
trovato=TRUE;
}
}
return riga;
}

list algoritmo_cifratura(list testo, list chiave){
list testo_cifrato=NULL;
char matrice[DIM][DIM];
riempi_matrice(matrice);
list ricomincia_chiave=chiave;//vedi giù
int colonna, riga;
char ch_testo, ch_chiave;
while(!empty(testo)){
if(chiave==NULL){
chiave=ricomincia_chiave;//la chiave è più corta del testo, quindi una volta terminato ogni carattere essa ricomincia dal primo carattere
}
ch_testo=head(testo);
ch_chiave=head(chiave);
if((ch_testo>='a' && ch_testo<='z')){
colonna=trova_colonna(ch_testo,matrice);
riga=trova_riga(ch_chiave,matrice);
testo_cifrato=add(matrice[riga][colonna],testo_cifrato);//aggiunge al testo cifrato 
}else if(ch_testo==' '){//se il testo contiene uno spazio, esso verrà inserito così com'è nella lista testo_cifrato
testo_cifrato=add(' ',testo_cifrato);
}
testo=tail(testo);
chiave=tail(chiave);
}

return testo_cifrato;
}

int trova_colonna_decifrare(char ch,int riga, char matrice[][DIM]){
int colonna;
int trovato=FALSE;
for(int i=0;i<DIM && trovato==FALSE;i++){//scorre la matrice fino a trovare il carattere cercato
if(ch==matrice[riga][i]){
colonna=i;
trovato=TRUE;
}
}
return colonna;
}

list algoritmo_decifratura(list testo_cifrato, list chiave){
list testo=NULL;
char matrice[DIM][DIM];
riempi_matrice(matrice);
int colonna,riga;
char ch_chiave,ch_testo_cifrato;
list ricomincia_chiave=chiave;//vedi giù
while(!empty(testo_cifrato)){
if(empty(chiave)){
chiave=ricomincia_chiave;//nel caso la chiave sia più corta del testo cifrato
}
ch_chiave=head(chiave);
ch_testo_cifrato=head(testo_cifrato);
if((ch_testo_cifrato>='a' && ch_testo_cifrato<='z')){
riga=trova_riga(ch_chiave, matrice);
colonna=trova_colonna_decifrare(ch_testo_cifrato,riga,matrice);
testo=add(matrice[0][colonna],testo);
}else if(ch_testo_cifrato==' '){//se il carattere è uno spazio viene inserito coiì com'è
testo=add(' ',testo);
}
testo_cifrato=tail(testo_cifrato);
chiave=tail(chiave);



}
return testo;
}

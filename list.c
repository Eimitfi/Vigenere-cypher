/*
proprietà intellettuale(?) di: Iftimie Dragos Mihaita 
matricola:0000873762
numero prova:
*/


#include "list.h"
list empty_list(void){
return NULL;
}
boolean empty(list l){
	if(l==NULL){
	return true;
	}else{
	return false;
	}
}

element head(list l){
	if(empty(l)){
	abort();
	}else{
	return l->value;
	}
}

list tail(list l){
	if(empty(l)){
	abort();
	}else{
	return l->next;
	}
}

list cons(element e, list l){
	list t;
	t = (list) malloc(sizeof(item));
	t->value=e;
	t->next=l;
	return t;
}
list add(element e, list l){
list temp=l;
if(empty(l)){
cons(e,l);
}else{
list t=(list) malloc(sizeof(item));
t->value=e;
l=append(l,t);
return l;

}
}
/*
int equals(element e1,element e2){
int result=0;
if(strcmp(e1.squadra,e2.squadra)==0){
result=1;
}
return result;                                // PER MEMBER
}
int member(element el, list l){
int result =0;
while(!empty(l) && !result){
result = equals(el,head(l));
if(!result){
l=tail(l);
}
}
return result;
}*/
/*
boolean member(element el, list l){
	if(empty(l)){
	return false;
	}else if(el==head(l)){
	return true;
	}else{
	return member(el, tail(l));
	}
}
*/
void freelist(list l) { 
       if (empty(l)) 
              return; 
       else { 
              freelist(tail(l)); 
              free(l); 
       } 
       return; 
} 
int length(list l){
	if(empty(l)){
	return 0;
	}else{
	return 1+length(tail(l));
	}
}

list sub_list(int n, list l){
	int i=1;
	while(!empty(l) && (i<n)){
	l=tail(l);
	i++;
	}
	return l;
}
/*
list add(element el, list l){
	if(empty(l)){
	return cons(el,l);
	}else{
	return cons(head(l), add(el,tail(l)));
	}

}
*/
list append(list l1, list l2){
	if(empty(l1)){
	return l2;
	}else{
	return cons(head(l1), append(tail(l1),l2));
	}


}

list reverse(list l){
	if(empty(l)){
	return empty_list();
	}else{
	append(reverse(tail(l)), cons(head(l),empty_list()));
	}
}

list copy(list l){
	if(empty(l)){
	return l;
	}else{
	return cons(head(l), copy(tail(l)));
	}
}
/*
list delete_element(element el, list l){
	if(empty(l)){
	return empty_list();
	}else if(el == head(l)){
	return tail(l);
	}else{
	return cons(head(l), delete_element(el, tail(l)));
	}

}
*/

void showlist(list l) { 
       element temp; 
       if (!empty(l)) { 
              temp = head(l); 
              printf("%c", temp);
              showlist(tail(l)); 
              return; 
       } 
       else { 
              printf("\n\n"); 
              return; 
       } 
} 
                                // PER ORDINAMENTO LISTE
/*
int confronta(element e1, element e2) 
{
int result=1;
	result=strcmp(e1.nome,e2.nome);
	 if(result==0){
	result=(e1.ombrellone)-(e2.ombrellone);
	}
	
	

return result;
}

*/



/*
list insElementOrdInList(element el, list l) //inserisce in modo ordinato l elemento nella lista
{
	if (empty(l))
		return cons(el, l);
	else if (confronta(el, head(l)) <= 0) //elemento di confronto per l ordinamento
		return cons(el, l);
	else
		return cons(head(l), insElementOrdInList(el, tail(l)));
}
*/

/*
list mergeList(list l1, list l2) {          //list 1 vuoto
	list l3 = copy(l1);
	if (empty(l2)) return l3;
	else if (!member(head(l2), l3))
		l3 = insElementOrdInList(head(l2), l3);
	return mergeList(l3, tail(l2));
}
*/


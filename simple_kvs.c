#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int N = 10 ; // int = 10
// simple implementation : tableau de structures :

struct S_KVS{
    char* key ;
    char* value ;
};

struct S_KVS **  SKVS ;  

void initialiseKVS(){
    SKVS = malloc(sizeof(struct S_KVS *) * N) ;
    for( int i = 0; i < N ; ++i){
        SKVS[i] = NULL ;
    }
    //SKVS[0] = malloc(sizeof(struct S_KVS));
    //SKVS[0] ->key   = "ab";
    //SKVS[0] ->value = "abcdef";
}
void AffichageKVS(){
  if (SKVS[0] == NULL){
      printf("%s\n", "KVS VIDE !!!");
      return ;
  }
  int i= 0;
  while ( SKVS[i] != NULL && i < N ) {
    printf(" KVS[%u]  : %s  =  %s\n", i, SKVS[i]->key, SKVS[i]->value);
    i++;
  }
}
int checkSKVS(char* key){
    int j = 0 ;
    while(  j < N){
        if ( SKVS[j] == NULL)
            break ;
        j++;
    }
    for (int i=0; i<j; ++i)
        if ( strcmp( SKVS[i]-> key , key) == 0 )
            // printf("%s  =  %s\n", SKVS[i] -> key, SKVS[i] -> value); afficher la valeur déjà existant.
            return 1 ;
    return 0 ;
}

void set  (char* key, char* value){
  const int b = checkSKVS(key) ; // check si key existe déjà !
    // si faux : ajouter key et value à la fin du tableau .
    if ( b == 0 ){
        int i = 0 ;
        while( i < N ) {
	  if (SKVS[i] == NULL)
	    break;
	  i++;
	}
        SKVS[i] = malloc(sizeof(struct S_KVS));
	SKVS[i] ->key   = key  ;
	SKVS[i] ->value = value;
        
	}
}
char* get (char* key){
  int b = checkSKVS(key) ;
  if  ( b == 0){
    printf("%s : %s\n", key, "Cette key n'existe pas !");
    return "????";
  }
  else
    for (int i=0; i<N; ++i)
      if (SKVS[i] != NULL && strcmp( SKVS[i]-> key , key) == 0 )
	return SKVS[i]->value ;
    
}

/* SKVS  : exemple pour N = 4
 * SKVS[0] = key0 | value0
 * SKVS[1] = key1 | value1
 * SKVS[2] = key2 | value2
 * SKVS[3] = key3 | value3
 * */
// set("a", "abcd", N) : ajout la donnée ("a", "abcd") au tableau Simple_KVS
// get("a", N) : retourne la valeur associée à la clé "a"


//void set(char* key, char** value, const size_t size) ; // set("ab", "abcdef", 10)
//char * get (char* key, const size_t size) ;            // char* val = get("ab", 10)

int main() {
    printf("Hello, World!\n");
    initialiseKVS()          ;
    //printf("Hello, World!\n");
    //int b = checkSKVS("ab")  ;
    //printf("Hello, World!\n");
    //printf("%u\n", b) ;
    AffichageKVS()    ;
    //printf("Hello, World!\n");
    //b = checkSKVS("xy");
    //printf("%u\n", b)  ;
    set("xy", "wxyz");
    printf("Hello, World!\n");
    AffichageKVS();
    char* c = get("ab");
    printf("%s  :  %s\n", "ab", c);
    set("uv","opqr");
    AffichageKVS();
    printf("Hello, World!\n");
    return 0;
    
    /* 
       - Si la taille du tableau devient très grand, la recherche d'une clé-valeur sera plus couteuse
       - Pour l'ajout/suppression d'un élément On parcourt tous le tableau élément par élément.
       - On stocke et la clé et la valeur associée => saturer la mémoire !
       
     */
}

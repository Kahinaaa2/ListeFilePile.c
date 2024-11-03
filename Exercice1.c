Exercice 1 (Liste doublement chaînée)
On rapelle que les Chainons des listes doublement chaînées possèdent un pointeur vers le Chainon suivant et un pointeur
vers le Chainon précédent. Il est donc possible de parcourir une telle liste dans les deux sens.
1. Déclarer une structure de liste doublement chaînée permettant de stocker des mots de 20 caractères maximum.
2. Écrire une fonction compareMot(char *mot1, char* mot2 ) qui retourne 1 si mot1 est avant mot2 dans l’ordre alphabétique et 0 sinon.
3. Écrire une fonction insertListe(char *mot1, liste *pliste ) qui ajoute à la liste doublement chaînée pointée par
pliste de mots classés dans l’ordre alphabetique un nouveau Chainon contenant mot1.
4. Écrire une procédure affiche(liste *pliste ) qui affiche dans l’ordre les mots contenus dans la liste.
5. Écrire une procédure afficheInv(liste *pliste ) qui affiche dans l’ordre inverse les mots contenus dans la liste.
6. Déclarer un nouvelle liste et la remplir avec une vingtaine de mots. Afficher cette liste de mots dans l’ordre alphabétique
et anti-alphabétique.




#include<stdio.h>
#include<stdlib.h>
#define MAX_CHAR 20

typedef struct chainon{
  char valeur[MAX_CHAR];
  struct chainon *suivant;
  struct chainon *prec;
}Chainon;

typedef struct liste{
  Chainon *tete;
  Chainon *fin;
}Liste;

Chainon *createChainon(char *c){
    //verifier si la chaine ne depasse pas la chaine maximale
    if(strlen(c)>MAX_CHAR){
      exit(1);
    }
    if(c==NULL){
      exit(2);
    }
    Chainon *new =malloc(sizeof(Chainon));
    if(new==NULL){
      exit(4);
    }
  }
  
  //copier la chaine de caractere dans le new chainon
  strcpy(new->valeur, c);
  nouveau->suivant=NULL;
  nouveau->prec==NULL;
  retrun new;
}

Liste createListe(){
  Liste liste;
  liste.tete=NULL;
  liste.fin=NULL;
  return liste;
}

int compareMot(char *mot1, char *mot2){
  //verifier si les deux chaines ne sont pas nulles
  if(mot1 == NULL || mot2 ==NULL){
    exit(6);
  }
  //verifier que les chaines dne depasse pas la taille

  if(strlen(mot1)>MAX_CHAR || strlen(mot2)>MAX_CHAR){
    exit(8);
  }

  //comparaison des chaines de caracteres
  if(strcmp(mot1,mot2)<0){
    return 1;
  }else{
    return 0; //mot1 ne precede pas mot2
  }
}


Chainon *insertDebut(Chainon *tete, char *a){
  //verifier si la chaine ne depasse pas la chaine maximale
  if(a==0 || strlen(a)>MAX_CHAR){
    exit(9);
  }
 if(tete==NULL){
   tete=createChainon(a);
 }else{
   Chainon *new = createChainon(a);
   new->suivant =tete;
   new->prec=NULL;
   tete=new;
 }
  return tete;
}

//on cree la fonction pour inserer un mot dans la liste de maniere trié

void insertliste(Liste *pliste,Char mot1){
  if(mot1==NULL || tete==NULL|| strlen(mot1)>MAX_CHAR){
    exit(10);
  }
  //si la liste est vide, on insert le premier chainon
  if(pliste->tete==NULL){
    pliste->tete=createChainon(mot1);
    pliste->fin =pliste->tete; //la tete est la queue sont identique car il n'ya q'un seul element
  }
  //si le mot doit etre inserer en debut de liste
  if(compareMot(mot1, pliste->tete->valeur)){
    pliste->tete = insertDebut(pliste->tete, mot1);//on insert le mot au debut
  }
 //rechere le bon endroit pour inserer le mot
  Chainon *borne1 = pliste->tete;
  Chainon *borne2 = pliste->tete->suivant;
  while(borne2!=NULL){
    //si mot1 doit etre entre borne1 et 2
    if(compareMot(borne1->valeur, mot1) && compareMot(borne2->valeur,mot1)){
      Chainon *new = createChainon(mot1);
      new->suivant =borne2;
      new->prec = borne1;
      borne1->suivant =new;
      borne2->prec=new;
    }
    //avance dans la liste
    borne1=borne2;
    borne2=borne2->suivant;
  }
  //si le mot doit etre inserer a la fin de la liste
  pliste->fin->suivant=createChainon(mot1);
  pliste->fin->suivant->prec=pliste->fin;
  pliste->fin=pliste->fin->suivant;


  void afficheListe(Liste *liste){
    if(liste==NULL){
      printf("la liste est vide.\n");
    }
    else{
      Chainon *tmp =liste->tete;
      while(tmp != NULL){
        printf("%s", tmp->valeur);
          if(tmp->suivant != NULL){
            printf("->");
          }
      }
      printf("\n");
    }
  }

  int mai(){
    liste 1 = createListe(); //creation d'une liste vide

    //iserer 5 mot dans la liste

    insertListe(&1, "chat");
    insertListe(&1, "chien");
    insertListe(&1, "oiseau");
    insertListe(&1, "poisson");
    insertListe(&1, "zebre");

    afficheListe(&1);

    return 0;
  }

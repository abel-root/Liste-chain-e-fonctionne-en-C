#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Point{
    int dx;
    int dy;
    struct Point * next;

}Point;

//add element at the head of the liste
Point * insertHead(Point *list,int dx, int dy){
    Point * newNode = malloc(sizeof(Point));

    newNode->dx   = dx;
    newNode->dy   = dy;
    newNode->next = list;
    return newNode;
}
//add element at the tail of the liste
Point* insertTail(Point*list, int dx, int dy){
    Point * newNode = malloc(sizeof(Point));

    newNode->dx   = dx;
    newNode->dy   = dy;
    newNode->next = NULL;

    if(list==NULL) return newNode;

    Point * current = list;
    while(current->next != NULL){
        current=current->next;
    }
    current->next = newNode;

    return list;

}

//show list value
void showList(Point*list){
    if(list==NULL){
        printf("Liste NULL\n");
    }
    Point * temp = list;
    while(temp->next!=NULL){
        printf("(%d,%d)->",temp->dx,temp->dy);
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("(%d,%d)->",temp->dx,temp->dy);
    }
    printf("NULL\n");
}

//delete a element in the list
Point* deleteHead(Point*list){
   
    if(list==NULL){
        return NULL;
    }
     Point*newList=list->next;
    free(list);
    return newList;
}

/// on ne peut pas être sur l'élement dont onn veux supprimer
Point*deleteTail(Point*list){
    if(list==NULL) return NULL; // if list is empty

    if(list->next == NULL){ // if list is one element
        free(list);
        return NULL;
    }
    Point* current = list;
    while (current->next->next!=NULL) {
        current=current->next;
    }

    free(current->next);
    current->next = NULL;

    return list;
}

// sheek one element 
Point* findElement(Point* list,int dx, int dy){
  
    Point *current = list;
    while(current != NULL){
        if(current->dx == dx && current->dy == dy){
            return current;     // trouvé
        }
        current = current->next;
    }
    return NULL;    
}

//find the i element in the list
Point* findByIndexTheElement(Point*list,int idx){
     int step;
    
    for(step=0; step<idx && list!=NULL; step++){
        list=list->next;
    }
    if(list==NULL){return NULL;}
    else{ return list;}
   
}
//compter le nombre d'élement dans la liste
int nbrElement(Point*list){
    if(list==NULL) return 0;
    int i =0;
    Point*current = list;
    while(current->next!=NULL){
        i++;
        current=current->next;
    }
    i+=1;
    return i;
}
// effacer la liste 
Point*clear(Point*list){
    if(list==NULL)return NULL;
    if(list->next==NULL){
        free(list);
        return NULL;
    }
    Point * current=list;
    while(list !=NULL){
        current=list->next;
        free(list);
        list=current;
    }
    return NULL;
}

//compter le nombre d'occurence d'une valeur
int nbrOccurence(Point*list, int dx,int dy){
    int occ=0;
    if(list==NULL) return 0;
    while((list=findElement(list, dx,  dy))!=NULL){
        list=list->next;
        occ++;
    }
    return occ;
}
//récuperer la valeur d'un élement
int nodeValueDx(Point*list , int idx){
    return findByIndexTheElement(list, idx)->dx;
}
int nodeValueDy(Point*list,int idx){
    return findByIndexTheElement(list, idx)->dy;
}

//supprimer tous les élements de la liste ayant une valeur
Point *deleteByValue(Point *list, int v){
    // 1. supprimer les nœuds de tête correspondants
    while(list != NULL && (list->dx == v || list->dy == v)){
        Point *tmp = list;
        list = list->next;
        free(tmp);
    }

    // 2. supprimer les correspondants dans le reste de la liste
    Point *current = list;
    while(current != NULL && current->next != NULL){
        if(current->next->dx == v || current->next->dy == v){
            Point *tmp = current->next;
            current->next = tmp->next;   // relier avant de libérer
            free(tmp);
            // on n'avance pas : le nouveau current->next reste à tester
        } else {
            current = current->next;
        }
    }
    return list;
}
int main(){

    struct Point *list = NULL;
    int n,dx,dy;

    printf("Inserer les donnees à la tete de la liste\n");
    for(n=0;n<5;n++){
        printf("Entrez la valeur de dx\n");
        scanf("%d",&dx);
        printf("Entrez la valeur de dy\n");
        scanf("%d",&dy);
        list =insertHead(list, dx, dy);
    }

    showList(list);
    printf("Inserer les donnees à la fin de la liste\n");
    for(n=0;n<4;n++){
        printf("Entrez la valeur de dx\n");
        scanf("%d",&dx);
        printf("Entrez la valeur de dy\n");
        scanf("%d",&dy);
        list =insertTail(list, dx, dy);
    }
    showList(list);

    printf("nombre d'élement dans ma liste\n");
    printf("nbr= %d\n",nbrElement(list));

    printf("\n");
    printf("nbr d'occurence = %d\n",nbrOccurence(list, 10,5));

    printf("\n");
    printf("valeur dx de l'élement 3 =%d\n",nodeValueDx(list,3));
    printf("valeur dy de l'élement 4 =%d\n",nodeValueDy(list,4));

    printf("\n");
    printf("supprier un élement par valeur\n");
    list = deleteByValue(list, 10);
    showList(list);

    list=deleteHead(list);
    printf("\n");
    printf("delete the frist element of the list\n");
    showList(list);

    printf("nombre d'élement dans ma liste\n");
    printf("nbr= %d\n",nbrElement(list));

    list=deleteTail(list);
    printf("\n");
    printf("delete the last element of the list\n");
    showList(list);
    printf("\n");

    printf("nombre d'élement dans ma liste\n");
    printf("nb= %d\n",nbrElement(list));
    printf("\n");

    printf("rechercher un element dans la liste\n");
    list = findElement(list, 10, 5);
    showList(list);

    printf("\n");
    printf("rechercher le i-eme élement de la liste\n");
    list=findByIndexTheElement(list,1);
    showList(list);

    printf("\n");
    printf("Effacer la liste\n");
    list=clear(list);
    showList(list);

    return 0;
}

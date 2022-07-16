#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tam 26
//Structs 
//struct da ARVORE
struct raiz{
    struct raiz * esq;
    struct raiz * dir;
    char palavra[100];
    int repeticao;
};typedef struct raiz ARVORE;
//struct do vetor que irá aponat
struct indice{
    char letra;
    ARVORE * aponta;
};typedef struct indice INDICE;

//Inicializa vetor
/////////////////////////////////////////////////////
void inicializa_vetor(INDICE vet[]){
    int i;
    for(i=0; i < tam; i++){
        vet[i].letra = 'a' + i;
        vet[i].aponta = NULL;
    }
}

//Insere palavras
/////////////////////////////////////////////////////
void insere_nodo(ARVORE ** raiz, char p[]){
  if((*raiz) == NULL){
        ARVORE * nodo = (ARVORE *)malloc(sizeof(ARVORE));
        strcpy(nodo->palavra, p);
        nodo ->dir = NULL;
        nodo -> esq =NULL;
        nodo -> repeticao = 1;
        (*raiz) = nodo;
    }

    else if(strcasecmp(p, (*raiz)-> palavra) <= -1){
        insere_nodo(&(*raiz) -> esq, p);
    }

    else if(strcasecmp(p, (*raiz)->palavra) == 0){
        (*raiz)->repeticao += 1;
    }

    else{
        insere_nodo(&(*raiz)->dir, p);
    }

}
//percorre vetor para inserir na ARVORE correta
void insere_palavra_lista(INDICE vet[], char p[], int i){
    if(i < tam){
        if(vet[i].letra == tolower(p[0])){

            insere_nodo(&(vet[i].aponta), p);
        }

        else{
            insere_palavra_lista(vet, p, i+1);
        }
    }
}

//Mostrar as palavras
/////////////////////////////////////////////////////
void mostra_nodo(ARVORE * nodo){
    if(nodo != NULL){
        mostra_nodo(nodo -> esq);
        printf("%s - %d repeticoes\n", nodo->palavra, nodo->repeticao);
        mostra_nodo(nodo->dir);
    }
}
//percorre vetor, para mostrar todas as palavras
void exibe_palavras(INDICE vet[], int i){
    if(i < tam){
        mostra_nodo(vet[i].aponta);

        exibe_palavras(vet, i+1);
    }
}

//Mostra as palavras com 1 repeticao

void mostra_palavra_repeticao(ARVORE * nodo, int n){
    if(nodo != NULL){
        mostra_palavra_repeticao(nodo->esq, n);
        if(nodo->repeticao == n){
            printf("%s - %d repeticoes\n", nodo->palavra, nodo->repeticao);
        }
        mostra_palavra_repeticao(nodo->dir, n);
    }
}
//Exibe as palavras, recebendo o número de repeticao como parâmetro
void exibe_palavras_repeticao_1(INDICE vet[], int i){
    if(i<tam){
        mostra_palavra_repeticao(vet[i].aponta, 1);
        exibe_palavras_repeticao_1(vet, i+1);
    }
}
//retorna o maior 
int retorna_maior(ARVORE * nodo, int maior){
    ARVORE *aux = nodo;
    while(aux!=NULL){
        if(aux->repeticao > maior){
            maior = aux->repeticao;
        }
        aux = aux->esq;
    }
    aux = nodo;
    while(aux!=NULL){
        if(aux->repeticao > maior){
            maior = aux->repeticao;
        }
        aux = aux->dir;
    }
    return maior;
}
//retorna palavras com mais repetições
void exibe_palavras_maior_repeticao(INDICE vet[]){
    int maior = 1;
    int i;
    for(i=0;i<tam;i++){
            int aux = retorna_maior(vet[i].aponta, maior);
            if(aux > maior){
                maior = aux;
            }
        }

    for(i = 0; i<tam; i++){
        mostra_palavra_repeticao(vet[i].aponta, maior);
    }
}


//remover
int remover_nodo(ARVORE ** nodo, char p[]){
    if((*nodo) == NULL){
        return 0;
    }
    else if(strcasecmp((*nodo)->palavra, p) > 0){
        remover_nodo(&(*nodo)->esq, p);
    }
    else if(strcasecmp((*nodo)->palavra, p) < 0){
        remover_nodo(&(*nodo)->dir, p);
    }
    else{
        if((*nodo)-> esq == NULL && (*nodo)->dir == NULL){
            free(*nodo);
            (*nodo) = NULL;
            return 1;
        }
        else if((*nodo)->esq == NULL){
            ARVORE * aux = (*nodo);
            (*nodo) = (*nodo)->dir;
            free(aux);
            return 1;
        }
        else if((*nodo)->dir == NULL){
            ARVORE * aux = (*nodo);
            (*nodo) = (*nodo)->esq;
            free(aux);
            return 1;
        }
        else{
            ARVORE * aux = (*nodo)->esq;
            while(aux->dir != NULL){
                aux = aux->dir;
            }
            char string[100];
            strcpy(string, (*nodo)->palavra);
            strcpy((*nodo)->palavra, aux->palavra);
            (*nodo)->repeticao = aux->repeticao;
            strcpy(aux->palavra, string);
            remover_nodo(&(*nodo)->esq, p);
            return 1;
        }
    }
}
//percorre o vetor
int remover(INDICE vet[], int i, char p[]){
    if(i<tam){
        if(vet[i].letra == p[0]){
            return remover_nodo(&vet[i].aponta, p);
        }
        remover(vet, i+1, p);
    }
    return 0;
}

//Exibe as palavras que começam com uma determinada letra
void exibe_palavras_letra(INDICE vet[], int i, char letra){
    if(i<tam){
        if(vet[i].letra == letra){
            mostra_nodo(vet[i].aponta);
        }
        else{
            exibe_palavras_letra(vet, i+1, letra);
        }
    }
}
/////////////////////////////////////////////////////

//conta palavras
int contador_palavras(ARVORE * nodo){
    if(nodo == NULL){
        return 0;
    }
    else{
        return 1 + contador_palavras(nodo->esq) + contador_palavras(nodo->dir);
    }
}
//Mostra o total de palavras
void mostra_conta(INDICE vet[]){
    int soma =0;
    for(int i=0; i<tam; i++){
        soma = soma + contador_palavras(vet[i].aponta);
    }
    printf("Total de palavras: %d\n", soma);
}

//Consulta
int consulta_nodo(ARVORE * nodo, char p[]){
    if(nodo == NULL){
        return 0;
    }

    else if(strcmp(p, nodo->palavra) == 0){
        return nodo->repeticao;
    }
    else if(strcmp(p, nodo->palavra) < 0){
        consulta_nodo(nodo->esq, p);
    }
    else{
        consulta_nodo(nodo->dir, p);
    }
}
//percorre vetor para retornar a consulta
int consulta(INDICE vet[], char p[], int i){
    if(i<tam){
       if(vet[i].letra == p[0]){
           return consulta_nodo(vet[i].aponta, p);
       }
        else{
            consulta(vet, p, i+1);
        }
    }
}

//conta repeticao
int contador_repeticoes(ARVORE * nodo){
    if(nodo == NULL){
        return 0;
    }
    else{
        return nodo->repeticao + contador_repeticoes(nodo->esq) + contador_repeticoes(nodo->dir);
    }
}

void mostra_repeticao(INDICE vet[]){
    int somaRepeticoes = 0;
    for(int i=0; i<tam; i++){
        somaRepeticoes = somaRepeticoes + contador_repeticoes(vet[i].aponta);
    }

    printf("Total de repeticoes: %d\n", somaRepeticoes);
}



//Main
int main(){
    INDICE vet[tam];
    char palavra[] = "aguas";
    char teste[] ="abono";
    char as1[] = "as";
    char ce[] = "certeza";
    char fo[] = "folhas";
    char fim1[] = "fim";
    char fato1[] = "fato";
    char frutas[] = "frutas";

    inicializa_vetor(vet);

    insere_palavra_lista(vet, palavra, 0);
    insere_palavra_lista(vet, teste, 0);
    insere_palavra_lista(vet, teste, 0);
    insere_palavra_lista(vet, as1, 0);
    insere_palavra_lista(vet, as1, 0);
    insere_palavra_lista(vet, as1, 0);
    insere_palavra_lista(vet, ce, 0);
    insere_palavra_lista(vet, fo, 0);
    insere_palavra_lista(vet, fo, 0);
    insere_palavra_lista(vet, fim1, 0);
    insere_palavra_lista(vet, fato1, 0);
    insere_palavra_lista(vet, fato1, 0);
    insere_palavra_lista(vet, frutas, 0);
    insere_palavra_lista(vet, "zebra", 0);

    printf("****************************************\n");
    printf("Todas as Palavras: \n\n");
    exibe_palavras(vet, 0);
    printf("****************************************\n");
    printf("Todas as Palavras com a letra F: \n\n");
    exibe_palavras_letra(vet, 0, 'f');
    printf("****************************************\n");
    mostra_conta(vet);
    printf("****************************************\n");
    mostra_repeticao(vet);
    printf("****************************************\n");
    printf("Palavras com 1 repeticao:\n\n");
    exibe_palavras_repeticao_1(vet, 0);
    printf("****************************************\n");
    printf("Palavras com mais repeticoes:\n\n");
    exibe_palavras_maior_repeticao(vet);
    printf("****************************************\n");
    remover(vet, 0, "abono");
    printf("Todas as Palavras (Pos remocao): \n\n");
    exibe_palavras(vet, 0);
}











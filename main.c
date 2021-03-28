//Arquivo main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listaDinEncad.h"

void menu()
{
    printf("|-----------------------------------------------\n");
    printf("|           Lista Dinamica Encadeada           |\n");
    printf("|----------------------------------------------|\n");
    printf("| 1 - Cadastrar Matricula                      |\n");
    printf("| 2 - Consultar Matricula                      |\n");
    printf("| 3 - Consultar Lista                          |\n");
    printf("| 4 - Excluir Matricula                        |\n");
    printf("| 0 - Sair                                     |\n");
    printf("|----------------------------------------------|\n");
    printf("|                    Debug                     |\n");
    printf("|----------------------------------------------|\n");
    printf("| c - Cria Lista                               |\n");
    printf("| p - Preenche Lista (Adiciona 5 Elementos)    |\n");
    printf("| l - Libera Lista                             |\n");
    printf("| t - Tamanho da Lista                         |\n");
    printf("| i - Imprimi Lista                            |\n");
    printf("| a - Insere Lista Inicio                      |\n");
    printf("| r - Remove Lista Inicio                      |\n");
    printf("| x - Insere Lista Final                       |\n");
    printf("| k - Remove Lista Final                       |\n");
    printf("| e - Remove Lista Matricula                   |\n");
    printf("| j - Consulta lista Posicao                   |\n");
    printf("| v - Consulta lista Matricula                 |\n");
    printf("|----------------------------------------------|\n");
    return;
}

int main()
{
    int matri;
    bool con = true;
    char opcao, pedro;
    Lista* li = cria_lista();
    struct aluno dados;

    while(con)
    {
        system("cls");
        menu();
        printf("Digite a opcao desejada: ");
        scanf("%c", &opcao);
        switch(opcao)
        {
        case '1':
            if(lista_cheia(li))
            {
                printf("Lista Cheia");
                system("pause");
                break;
            } else {
                printf("Digite a Matricula: ");
                scanf("%d", &dados.matricula);
                printf("Digite o Nome: ");
                fseek(stdin,0,SEEK_END);
                scanf("%s", dados.nome);
                printf("Digite a Nota 01: ");
                scanf("%f", &dados.n1);
                printf("Digite a Nota 02: ");
                scanf("%f", &dados.n2);
                printf("Digite a Nota 03: ");
                scanf("%f", &dados.n3);
                insere_lista_ordenada(li, dados);
                break;
            }
        case '2':
            printf("Qual matricula deseja consultar? ");
            scanf("%d", &matri);
            consulta_lista_mat(li, matri, &dados);
            printf("-------------------------------\n");
            printf("Matrucula: %d\n", dados.matricula);
            printf("Nome: %s\n", dados.nome);
            printf("Notas: %.2f %.2f %.2f\n",dados.n1,
                                             dados.n2,
                                             dados.n3);
            printf("-------------------------------\n");
            system("pause");
            break;
        case '3':
            imprime_lista(li);
            system("pause");
            break;
        case '4':
            printf("Qual matricula deseja remover? ");
            scanf("%d", &matri);
            remove_lista(li, matri);
            printf("Matricula removida com sucesso!!\n");
            system("pause");
            break;
        case '0':
            con = false;
            break;
        case 'c':
            li = cria_lista();
            printf("Lista criada com sucesso!!\n");
            system("pause");
            break;
        case 'p':
            for(int i = 0,j = tamanho_lista(li) + 1; i < 5; i++)
            {
                for(int k = 0, l = 0; k < sizeof(dados.nome); k++)
                {
                    dados.nome[l] = NULL;
                    l++;
                }
                dados.matricula = j;
                dados.nome[0] = 'A';
                dados.nome[1] = 'l';
                dados.nome[2] = 'u';
                dados.nome[3] = 'n';
                dados.nome[4] = 'o';
                dados.n1 = 10;
                dados.n2 = 10;
                dados.n3 = 10;
                insere_lista_ordenada(li, dados);
                j++;
            }
            printf("Elementos adicionados com sucesso!!\n");
            system("pause");
            break;
        case 'l':
            libera_lista(li);
            li = cria_lista();
            printf("Lista liberada com sucesso!!\n");
            system("pause");
            break;
        case 't':
            printf("A lista possui %d elementos!\n", tamanho_lista(li));
            system("pause");
            break;
        case 'i':
            imprime_lista(li);
            system("pause");
            break;
        case 'a':
            printf("Digite a Matricula: ");
            scanf("%d", &dados.matricula);
            printf("Digite o Nome: ");
            fseek(stdin,0,SEEK_END);
            scanf("%s", dados.nome);
            printf("Digite a Nota 01: ");
            scanf("%f", &dados.n1);
            printf("Digite a Nota 02: ");
            scanf("%f", &dados.n2);
            printf("Digite a Nota 03: ");
            scanf("%f", &dados.n3);
            insere_lista_inicio(li, dados);
            printf("Elemento inserido no inicio da lista\n");
            system("pause");
            break;
        case 'r':
            remove_lista_inicio(li);
            printf("Elemento do inicio da lista removido!!\n");
            system("pause");
            break;
        case 'x':
            printf("Digite a Matricula: ");
            scanf("%d", &dados.matricula);
            printf("Digite o Nome: ");
            fseek(stdin,0,SEEK_END);
            scanf("%s", dados.nome);
            printf("Digite a Nota 01: ");
            scanf("%f", &dados.n1);
            printf("Digite a Nota 02: ");
            scanf("%f", &dados.n2);
            printf("Digite a Nota 03: ");
            scanf("%f", &dados.n3);
            insere_lista_final(li, dados);
            printf("Elemento inserido no final da lista\n");
            system("pause");
            break;
        case 'k':
            remove_lista_final(li);
            printf("Elemento do final da lista removido!!\n");
            system("pause");
            break;
        case 'e':
            printf("Qual elemento deseja remover? ");
            scanf("%d", &matri);
            remove_lista(li, matri);
            printf("Elemento da lista removido com sucesso!!\n");
            system("pause");
            break;
        case 'j':
            printf("Qual posicao deseja consultar? ");
            scanf("%d", &matri);
            consulta_lista_pos(li, matri, &dados);
            printf("-------------------------------\n");
            printf("Matrucula: %d\n", dados.matricula);
            printf("Nome: %s\n", dados.nome);
            printf("Notas: %.2f %.2f %.2f\n",dados.n1,
                                             dados.n2,
                                             dados.n3);
            printf("-------------------------------\n");
            system("pause");
            break;
        case 'v':
            printf("Qual matricula deseja consultar? ");
            scanf("%d", &matri);
            consulta_lista_mat(li, matri, &dados);
            printf("-------------------------------\n");
            printf("Matrucula: %d\n", dados.matricula);
            printf("Nome: %s\n", dados.nome);
            printf("Notas: %.2f %.2f %.2f\n",dados.n1,
                                             dados.n2,
                                             dados.n3);
            printf("-------------------------------\n");
            system("pause");
            break;
        }
    }
    return 0;
}

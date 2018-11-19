#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// FUNCÃO PARA COLETAR DADOS
int coletarDados(int nome, int dataNasc, int rg, int email)
{
    int dados = 0;
    fflush(stdin); // LIMPAR BUFFER DO TECLADO
    dados += printf("\nInforme o nome completo do visitante: ");
    dados += gets(nome);
    dados += printf("Informe a data de nascimento do visitante: ");
    dados += gets(dataNasc);
    dados += printf("Informe o RG do visitante: ");
    dados += gets(rg);
    dados += printf("Informe o e-mail do participante: ");
    dados += gets(email);
    return dados;
}

// FUNÇÃO PARA GERAR CÓDIGO DO VISITANTE
int gerarCodigo(int cod, int i, int n1, int n2)
{
    for(i = 0; i <= 60; i++)
    {
        cod = rand() % n1 + n2;
    }
    return;
}

// FUNÇÃO PARA GERAR TICKET
int ticket(int codigo, int letra, int assento)
{
    int dados = 0;
    dados += printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    dados += printf("                              CODIGO: %d\n", codigo);
    dados += printf("                              DATA: 10/12/2018\n");
    dados += printf("                              HORA: 17:00\n");
    dados += printf("                              ASSENTO: %s%d\n", letra, assento);
    dados += printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    return dados;
}

main()
{
    char user[] = "un", password[] = "pa", usuario[20], senha[20];
    char nomeComp[50], dataNasc[11], rg[13], email[30];
    char resp[10], resp1[10], resp2[10];
    char letraEsp[] = "E", letraRes[] = "R", letraA[] = "A", letraB[] = "B", letraC[] = "C", letraD[] = "D";
    char cadeiraOcupada[] = "[x]", cadeiraLivre[] = "[]";
    int i, x, tentar, cod, op1, op2, codigo, codExc, visitantes[53], nAssentoReservado;
    int assentos[40], assentosReservados[10], assentosEspeciais[3], status[40], statusReservados[10], statusEspeciais[3], encontrou, achou, respondeu;

    for(i = 0; i < 3; i++)
    {
        assentosEspeciais[i] = i + 1;
        statusEspeciais[i] = 0;
    }
    for(i = 0; i < 53; i++)
    {
        visitantes[i] = 0;
    }
    for(i = 0; i < 40; i++)
    {
        status[i] = 0;
        assentos[i] = i + 1;
    }
    for(i = 0; i < 10; i++)
    {
        statusReservados[i] = 0;
        assentosReservados[i] = i + 1;
    }

    while(tentar != 1)
    {
        system("cls");
        printf("\n======= UNIP - PALESTRA =======\n\n");
        printf("===============================\n\n");
        tentar = 0; // FLAG PARA CASO USUARIO OU SENHA ESTEJAM INCORRETOS
        printf("Digite seu usuario: ");
        gets(usuario);
        printf("Digite sua senha: ");
        gets(senha);

        if(strcmp(user, usuario) == 0 && strcmp(password, senha) == 0)
        {
            while(op1 != 4)
            {
                // Apresenta o menu principal
                system("cls");
                op2 = 0;
                printf("\n          MENU PRINCIPAL\n\n");
                printf("================================\n\n");
                printf("1- Gerenciar visitante\n");
                printf("2- Realizar sorteio\n");
                printf("3- Enviar comunicado por e-mail\n");
                printf("Escolha sua opcao: ");
                scanf("%d", &op1);
                system("cls");

                switch(op1)
                {
                    case 1:
                            system("cls");
                            // Apresenta o menu secundário da opção 1
                            printf("\n       MENU SECUNDARIO\n\n");
                            printf("=============================\n\n");
                            printf("1- Incluir participante\n");
                            printf("2- Excluir participante\n");
                            printf("3- Listar lugares livres\n");
                            printf("4- Listar lugares ocupados\n");
                            printf("5- Mostrar todos lugares\n");
                            printf("6- Retornar ao menu principal\n");
                            printf("Escolha sua opcao: ");
                            scanf("%d", &op2);
                            switch(op2)
                            {
                                case 1:
                                    // INCLUIR PARTICIPANTE
                                    system("cls");
                                    i = 0;
                                    encontrou = 0; // FLAG PARA SABER SE HÁ VAGA LIVRE PARA NOVO VISITANTE
                                    codigo = gerarCodigo(cod, i, 1000, 9999);
                                    // TENTA ACHAR UMA VAGA PARA NOVO VISITANTE
                                    while(i < 53)
                                    {
                                        if(visitantes[i] == 0)
                                        {
                                            visitantes[i] = codigo;
                                            encontrou = 1;
                                            i = 53;
                                        }
                                        i++;
                                    }
                                    if(encontrou == 0)
                                    {
                                        printf("Nao ha assentos disponiveis!");
                                    }
                                    if(encontrou == 1)
                                    {
                                        system("cls");
                                        achou = 0; // FLAG PARA VERIFICAR SE HÁ ASSENTOS DISPONÍVEIS
                                        respondeu = 0; // FLAG PARA VERIFICAR SE AS PERGUNTAS FORAM RESPONDIDAS CORRETAMENTE
                                        fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                        printf("\n                 INCLUIR PARTICIPANTE\n\n");
                                        printf("======================================================\n\n");
                                        printf("O visitante e um convidado? (S / N): ");
                                        gets(resp1);
                                        printf("O visitante necessita de um lugar especial? (S / N): ");
                                        gets(resp2);
                                        fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                        if(strcmp(resp2, "S") == 0)
                                        {
                                            i = 0;
                                            while(i < 3)
                                            {
                                                if(statusEspeciais[i] == 0)
                                                {
                                                    statusEspeciais[i] = 1;
                                                    // FUNÇÃO COLETAR DADOS DO VISITANTE
                                                    coletarDados(nomeComp, dataNasc, rg, email);
                                                    system("cls");
                                                    // FUNÇÃO MOSTRAR TICKET
                                                    ticket(codigo, letraEsp, assentosEspeciais[i]);
                                                    getch();
                                                    achou = 1;
                                                    i = 3;
                                                }
                                                i++;
                                            }
                                            if(achou == 0)
                                            {
                                                    printf("Infelizmente todos assentos especiais ja estao ocupados.");
                                                    getch();
                                            }
                                            respondeu = 1;
                                        }
                                        if(strcmp(resp1, "S") == 0 && strcmp(resp2, "N") == 0)
                                        {
                                            i = 0;
                                            while(i < 10)
                                            {
                                                if(statusReservados[i] == 0)
                                                {
                                                    printf("\nInforme o numero do assento reservado: ");
                                                    scanf("%d", &nAssentoReservado);
                                                    if(statusReservados[nAssentoReservado - 1 ] == 0)
                                                    {
                                                        statusReservados[nAssentoReservado - 1] = 1;
                                                        // FUNÇÃO PARA COLETAR DADOS
                                                        coletarDados(nomeComp, dataNasc, rg, email);
                                                        // WHILE PARA INCREMENTAR O NÚMERO DO ASSENTO
                                                        system("cls");
                                                        ticket(codigo, letraRes, nAssentoReservado);
                                                        getch();
                                                        achou = 1;
                                                    }
                                                    i = 10;
                                                }
                                                i++;
                                            }
                                            if(achou == 0)
                                            {
                                                printf("Esse assento reservado ja esta ocupado.");
                                                getch();
                                            }
                                            respondeu = 1;
                                        }
                                        if(strcmp(resp1, "N") == 0 && strcmp(resp2, "N") == 0)
                                        {
                                            i = 0;
                                            while(i < 40)
                                            {
                                                if(status[i] == 0)
                                                {
                                                    status[i] = 1;
                                                    // FUNÇÃO PARA COLETAR DADOS
                                                    coletarDados(nomeComp, dataNasc, rg, email);
                                                    system("cls");
                                                    if(i < 10)
                                                    {
                                                        ticket(codigo, letraA, assentos[i]);
                                                    }
                                                    if(i >= 10 && i < 20)
                                                    {
                                                        ticket(codigo, letraB, assentos[i - 10]);
                                                    }
                                                    if(i >= 20 && i < 30)
                                                    {
                                                        ticket(codigo, letraC, assentos[i - 20]);
                                                    }
                                                    if(i >= 30 && i < 40)
                                                    {
                                                        ticket(codigo, letraD, assentos[i - 30]);
                                                    }
                                                    getch();
                                                    achou = 1;
                                                    i = 40;
                                                }
                                                i++;
                                            }
                                            if(achou == 0)
                                            {
                                                printf("Infelizmente todos os assentos comuns ja estao ocupados.");
                                                getch();
                                            }
                                            respondeu = 1;
                                        }
                                    }
                                    if(respondeu == 0)
                                    {
                                        printf("Erro! Responda novamente as perguntas.");
                                        getch();
                                    }
                                    break;
                                case 2:
                                    system("cls");
                                    encontrou = 0; // FLAG PARA SABER SE FOI CONCLUÍDO A EXCLUSÃO
                                    achou = 0; // FLAG PARA VERIFICAR SE HÁ VISITANTES A SEREM EXCLUIDOS
                                    i = 0;
                                    x = 0;
                                    fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                    while(i < 53)
                                    {
                                        if(visitantes[i] != 0)
                                        {
                                            printf("\n                 EXCLUIR PARTICIPANTE\n\n");
                                            printf("======================================================\n\n");
                                            printf("O visitante a ser excluido e um convidado? (S / N): ");
                                            gets(resp1);
                                            printf("O visitante a ser excluido e um especial? (S / N): ");
                                            gets(resp2);
                                            printf("\n\nDigite o codigo do convidado: ");
                                            scanf("%d", &codExc);
                                            fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                            printf("Voce tem certeza que deseja excluir o visitante? (S / N): ");
                                            gets(resp);
                                            if(strcmp(resp, "N") == 0)
                                            {
                                                system("cls");
                                                printf("Exclusao cancelada com sucesso.");
                                                respondeu = 1;
                                                getch();
                                                i = 53;
                                            }

                                            if(strcmp(resp2, "S") == 0)
                                            {
                                                system("cls");
                                                if(strcmp(resp, "S") == 0)
                                                {
                                                    while(i < 53)
                                                    {
                                                        if(visitantes[i] == codExc)
                                                        {
                                                            visitantes[i] = 0;
                                                            while(x < 3)
                                                            {
                                                                if(statusEspeciais[x] != 0)
                                                                {
                                                                    statusEspeciais[x] = 0;
                                                                    x = 3;
                                                                }
                                                                x++;
                                                            }
                                                            printf("Exclusao concluida com sucesso!");
                                                            getch();
                                                            encontrou = 1;
                                                            i = 53;
                                                        }
                                                        i++;
                                                    }
                                                    if(encontrou == 0)
                                                    {
                                                        printf("Nao foi possivel encontrar o visitante, tente novamente.");
                                                        getch();
                                                    }
                                                }
                                            }
                                            if(strcmp(resp1, "S") == 0 && strcmp(resp2, "N") == 0)
                                            {
                                                system("cls");
                                                if(strcmp(resp, "S") == 0)
                                                {
                                                    while(i < 53)
                                                    {
                                                        if(visitantes[i] == codExc)
                                                        {
                                                            visitantes[i] = 0;
                                                            while(x < 10)
                                                            {
                                                                if(statusReservados[x] != 0)
                                                                {
                                                                    statusReservados[x] = 0;
                                                                    x = 3;
                                                                }
                                                                x++;
                                                            }
                                                                printf("Exclusao concluida com sucesso.");
                                                                getch();
                                                                encontrou = 1;
                                                                i = 53;
                                                        }
                                                        i++;
                                                    }
                                                    if(encontrou == 0)
                                                    {
                                                        printf("Nao foi possivel encontrar o visitante, tente novamente.");
                                                        getch();
                                                    }
                                                }
                                            }
                                            if(strcmp(resp1, "N") == 0 && strcmp(resp2, "N") == 0)
                                            {
                                                system("cls");
                                                if(strcmp(resp, "S") == 0)
                                                {
                                                    while(i < 53)
                                                    {
                                                        if(visitantes[i] == codExc)
                                                        {
                                                            visitantes[i] = 0;
                                                            while(x < 40)
                                                            {
                                                                if(status[x] != 0)
                                                                {
                                                                    status[x] = 0;
                                                                    x = 3;
                                                                }
                                                                x++;
                                                            }
                                                            printf("Exclusao concluida com sucesso.");
                                                            getch();
                                                            encontrou = 1;
                                                            i = 40;
                                                        }
                                                        i++;
                                                    }
                                                    if(encontrou == 0)
                                                    {
                                                        printf("Nao foi possivel encontrar o visitante, tente novamente.");
                                                        getch();
                                                    }
                                                }
                                            }
                                            achou = 1;
                                        }
                                        i++;
                                    }
                                    if(achou == 0)
                                    {
                                        printf("Nao ha participantes a serem excluidos.");
                                        getch();
                                        i = 53;
                                    }
                                    break;
                                case 3:
                                    system("cls");
                                    printf("\nLUGARES  LIVRES\n\n");
                                    printf("================\n\n");
                                    encontrou = 0;
                                    printf("CADEIRA  STATUS\n\n");
                                    for(i = 0; i < 3; i++)
                                    {
                                        if(statusEspeciais[i] == 0)
                                        {
                                            printf("  E%d\t LIVRE\n", assentosEspeciais[i]);
                                            encontrou = 1;
                                        }
                                    }
                                    printf("\n\n");
                                    for(i = 0; i < 10; i++)
                                    {
                                        if(statusReservados[i] == 0)
                                        {
                                            printf("  R%d\t LIVRE\n", assentosReservados[i]);
                                            encontrou = 1;
                                        }
                                    }
                                    printf("\n\n");
                                    for(i = 0; i < 40; i++)
                                    {
                                        if(status[i] == 0)
                                        {
                                            if(i < 10)
                                            {
                                                printf("  %s%d\t LIVRE\n", letraA, assentos[i]);
                                            }
                                            if(i >= 10 && i < 20)
                                            {
                                                printf("  %s%d    LIVRE\n", letraB, assentos[i]);
                                            }
                                            if(i >= 20 && i < 30)
                                            {
                                                printf("  %s%d    LIVRE\n", letraC, assentos[i]);
                                            }
                                            if(i >= 30 && i < 40)
                                            {
                                                printf("  %s%d    LIVRE\n", letraD, assentos[i]);
                                            }
                                            encontrou = 1;
                                        }
                                    }
                                    if(encontrou == 0)
                                    {
                                        printf("Nao ha lugares livres.\n");
                                    }
                                    getch();
                                    break;
                                case 4:
                                    system("cls");
                                    printf("\nLUGARES   OCUPADOS\n\n");
                                    printf("==================\n\n");
                                    encontrou = 0;
                                    printf("CADEIRA   STATUS\n\n");
                                    for(i = 0; i < 3; i++)
                                    {
                                        if(statusEspeciais[i] == 1)
                                        {
                                            printf("  E%d\t  OCUPADO\n", assentosEspeciais[i]);
                                            encontrou = 1;
                                        }
                                    }
                                    printf("\n\n");
                                    for(i = 0; i < 10; i++)
                                    {
                                        if(statusReservados[i] == 1)
                                        {
                                            printf("  R%d\t  OCUPADO\n", assentosReservados[i]);
                                            encontrou = 1;
                                        }
                                    }
                                    printf("\n\n");
                                    for(i = 0; i < 40; i++)
                                    {
                                        if(status[i] == 1)
                                        {
                                            if(i < 10)
                                            {
                                                printf("  %s%d\t  OCUPADO\n", letraA, assentos[i]);
                                            }
                                            if(i >= 10 && i < 20)
                                            {
                                                printf("  %s%d    OCUPADO\n", letraB, assentos[i]);
                                            }
                                            if(i >= 20 && i < 30)
                                            {
                                                printf("  %s%d    OCUPADO\n", letraC, assentos[i]);
                                            }
                                            if(i >= 30 && i < 40)
                                            {
                                                printf("  %s%d    OCUPADO\n", letraD, assentos[i]);
                                            }
                                            encontrou = 1;
                                        }
                                    }
                                    if(encontrou == 0)
                                    {
                                        printf("Nao ha lugares ocupados.\n");
                                    }
                                    getch();
                                    break;
                                case 5:
                                    system("cls");
                                    x = 0; // CONTADOR PARA CONTROLE INTERNO
                                    printf("\nTODOS OS LUGARES\n\n");
                                    printf("==================\n\n");
                                    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                                    printf("|||||||||||||||||||||||||||||||||||| PALCO |||||||||||||||||||||||||||||||||||||||||\n");
                                    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n");
                                    printf("  \t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\t\n\n");
                                    printf("  E\t");
                                    for(i = 0; i < 3; i++)
                                    {
                                        if(statusEspeciais[i] == 0)
                                        {
                                            printf("[ ]\t");
                                        }
                                        if(statusEspeciais[i] == 1)
                                        {
                                            printf("[X]\t");
                                        }
                                    }
                                    printf("\n\n  R\t");
                                    for(i = 0; i < 10; i++)
                                    {
                                        if(statusReservados[i] == 0)
                                        {
                                            printf("[ ]\t");
                                        }
                                        if(statusReservados[i] == 1)
                                        {
                                            printf("[X]\t");
                                        }
                                    }
                                    for(i = 0; i < 40; i++)
                                    {
                                        if(i < 10)
                                        {
                                            if(i < 1)
                                            {
                                                printf("\n\n  A\t");
                                            }
                                            if(status[i] == 0)
                                            {
                                                printf("[ ]\t");
                                            }
                                            if(status[i] == 1)
                                            {
                                                printf("[X]\t");
                                            }
                                        }
                                        if(i >= 10 && i < 20)
                                        {
                                            if(i < 11)
                                            {
                                                printf("\n\n  B\t");
                                            }
                                            if(status[i] == 0)
                                            {
                                                printf("[ ]\t");
                                            }
                                            if(status[i] == 1)
                                            {
                                                printf("[X]\t");
                                            }
                                        }
                                        if(i >= 20 && i < 30)
                                        {
                                            if(i < 21)
                                            {
                                                printf("\n\n  C\t");
                                            };
                                            if(status[i] == 0)
                                            {
                                                printf("[ ]\t");
                                            }
                                            if(status[i] == 1)
                                            {
                                                printf("[X]\t");
                                            }
                                        }
                                        if(i >= 30 && i < 40)
                                        {
                                            if(i < 31)
                                            {
                                                printf("\n\n  D\t");
                                            };
                                            if(status[i] == 0)
                                            {
                                                printf("[ ]\t");
                                            }
                                            if(status[i] == 1)
                                            {
                                                printf("[X]\t");
                                            }
                                        }
                                    }
                                    printf("\n\n");
                                    getch();
                                    break;
                                case 6:
                                    break;
                                default:
                                    printf("Opcao invalida!");
                                    getch();
                                    break;
                            } // SWITCH(OP2)
                    }
                }
            tentar = 1;
        }
        else
        {
            printf("Usuario ou senha incorreta, tente novamente.\n");
            tentar = 0;
            getch();
        }
    } // WHILE
} // MAIN



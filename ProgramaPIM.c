#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "funcoes.c"

main()
{
    struct Pessoa visitanteEsp[3];
    struct Pessoa visitanteRes[10];
    struct Pessoa visitante[40];
    char user[] = "empresaPalestra", password[] = "palestraUnip", usuario[20], senha[20], data[11], hora[11];
    char nomeComp[50], dataNasc[11], rg[13], email[50], de[50], contEmail[100];
    char resp[2], resp1[2], resp2[2], resp3[2];
    char letraEsp[] = "E", letraRes[] = "R", letraA[] = "A", letraB[] = "B", letraC[] = "C", letraD[] = "D";
    char cadeiraOcupada[] = "[x]", cadeiraLivre[] = "[]";
    int i, x, y, z, tentar, cod, op1, op2, op3, codigo, codExc, codEmail, visitantes[53], nAssentoReservado, numSort;
    int assentos[40], assentosReservados[10], assentosEspeciais[3], status[40], statusReservados[10], statusEspeciais[3], encontrou, achou, respondeu;
    // PONTEIROS
    struct Pessoa *pCodEsp;
    pCodEsp = &visitanteEsp[0];
    struct Pessoa *pCodRes;
    pCodRes = &visitanteRes[0];
    struct Pessoa *pCod;
    pCod = &visitante[0];

    for(i = 0; i < 53; i++)
    {
        visitantes[i] = 0;
    }
    for(i = 0; i < 3; i++)
    {
        statusEspeciais[i] = 0;
        assentosEspeciais[i] = i + 1;
        strcpy(visitanteEsp[i].nome, "N/A");
        strcpy(visitanteEsp[i].data, "N/A");
        strcpy(visitanteEsp[i].rgP, "N/A");
        strcpy(visitanteEsp[i].emailP, "N/A");
        visitanteEsp[i].codigoP = 0;
    }
    for(i = 0; i < 10; i++)
    {
        statusReservados[i] = 0;
        assentosReservados[i] = i + 1;
        strcpy(visitanteRes[i].nome, "N/A");
        strcpy(visitanteRes[i].data, "N/A");
        strcpy(visitanteRes[i].rgP, "N/A");
        strcpy(visitanteRes[i].emailP, "N/A");
        visitanteRes[i].codigoP = 0;
    }
    for(i = 0; i < 40; i++)
    {
        status[i] = 0;
        assentos[i] = i + 1;
        strcpy(visitante[i].nome, "N/A");
        strcpy(visitante[i].data, "N/A");
        strcpy(visitante[i].rgP, "N/A");
        strcpy(visitante[i].emailP, "N/A");
        visitante[i].codigoP = 0;
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
            printf("\nLogin realizado com sucesso!\n");
            printf("\n\n\n\n\n\n© 2018 - GATES IT SOLUTIONS\n");
            getch();
        }

        if(strcmp(user, usuario) == 0 && strcmp(password, senha) == 0)
        {
            system("cls");
            printf("\n    DEFINIR DATA E HORA\n\n");
            printf("===========================\n\n");
            printf("Digite a data da palestra: ");
            gets(data);
            printf("Digite a hora da palestra: ");
            gets(hora);
            while(op1 != 4)
            {
                // Apresenta o menu principal
                system("cls");
                op2 = 0;
                printf("\n        MENU PRINCIPAL\n\n");
                printf("===============================\n\n");
                printf("1- Gerenciar visitante\n");
                printf("2- Realizar sorteio\n");
                printf("3- Enviar comunicado por e-mail\n");
                printf("Escolha sua opcao: ");
                scanf("%d", &op1);
                switch(op1)
                {
                case 1:
                    system("cls");
                    // Apresenta o menu secundário da opção 1
                    while(op2 != 7)
                    {
                        system("cls");
                        printf("\n     GERENCIAR VISITANTE\n\n");
                        printf("============================\n\n");
                        printf("1- Incluir participante\n");
                        printf("2- Excluir participante\n");
                        printf("3- Listar lugares livres\n");
                        printf("4- Listar lugares ocupados\n");
                        printf("5- Mostrar todos lugares\n");
                        printf("6- Mostrar todos os visitantes\n");
                        printf("7- Retornar ao menu principal\n");
                        printf("Escolha sua opcao: ");
                        scanf("%d", &op2);
                        switch(op2)
                        {
                        case 1:
                            // INCLUIR PARTICIPANTE
                            system("cls");
                            i = 0;
                            encontrou = 0; // FLAG PARA SABER SE HÁ VAGA LIVRE PARA NOVO VISITANTE
                            // TENTA ACHAR UMA VAGA PARA NOVO VISITANTE
                            while(i < 53)
                            {
                                if(visitantes[i] == 0)
                                {
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
                                    codigo = gerarCodigo(cod, i, 1000, 9999);
                                    // TENTA ACHAR UMA VAGA PARA NOVO VISITANTE
                                    while(i < 53)
                                    {
                                        if(visitantes[i] == 0)
                                        {
                                            visitantes[i] = codigo;
                                            i = 53;
                                        }
                                        i++;
                                    }
                                    i = 0;
                                    while(i < 3)
                                    {
                                        if(statusEspeciais[i] == 0)
                                        {
                                            statusEspeciais[i] = 1;
                                            // FUNÇÃO COLETAR DADOS DO VISITANTE
                                            coletarDados(visitanteEsp[i].nome, visitanteEsp[i].data, visitanteEsp[i].rgP, visitanteEsp[i].emailP);
                                            visitanteEsp[i].codigoP = codigo;
                                            system("cls");
                                            // FUNÇÃO MOSTRAR TICKET
                                            ticket(codigo, letraEsp, assentosEspeciais[i], data, hora);
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
                                    codigo = gerarCodigo(cod, i, 1000, 9999);
                                    // TENTA ACHAR UMA VAGA PARA NOVO VISITANTE
                                    while(i < 53)
                                    {
                                        if(visitantes[i] == 0)
                                        {
                                            visitantes[i] = codigo;
                                            i = 53;
                                        }
                                        i++;
                                    }
                                    i = 0;
                                    while(i < 10)
                                    {
                                        if(statusReservados[i] == 0)
                                        {
                                            printf("\nInforme o numero do assento reservado: ");
                                            scanf("%d", &nAssentoReservado);
                                            if(nAssentoReservado != 0 && nAssentoReservado < 11)
                                            {
                                                if(statusReservados[i] == 0)
                                                {
                                                    statusReservados[i] = 1;
                                                    // FUNÇÃO PARA COLETAR DADOS
                                                    coletarDados(visitanteRes[i].nome, visitanteRes[i].data, visitanteRes[i].rgP, visitanteRes[i].emailP);
                                                    visitanteRes[i].codigoP = codigo;
                                                    // WHILE PARA INCREMENTAR O NÚMERO DO ASSENTO
                                                    system("cls");
                                                    ticket(codigo, letraRes, nAssentoReservado, data, hora);
                                                    getch();
                                                    achou = 1;
                                                    i = 10;
                                                }
                                            }
                                        }
                                        i++;
                                    }
                                    if(achou == 0)
                                    {
                                        printf("Esse assento reservado ja esta ocupado ou nao existe.");
                                        getch();
                                    }
                                    respondeu = 1;
                                }
                                if(strcmp(resp1, "N") == 0 && strcmp(resp2, "N") == 0)
                                {
                                    i = 0;
                                    codigo = gerarCodigo(cod, i, 1000, 9999);
                                    // TENTA ACHAR UMA VAGA PARA NOVO VISITANTE
                                    while(i < 53)
                                    {
                                        if(visitantes[i] == 0)
                                        {
                                            visitantes[i] = codigo;
                                            i = 53;
                                        }
                                        i++;
                                    }
                                    i = 0;
                                    while(i < 40)
                                    {
                                        if(status[i] == 0)
                                        {
                                            status[i] = 1;
                                            // FUNÇÃO PARA COLETAR DADOS
                                            coletarDados(visitante[i].nome, visitante[i].data, visitante[i].rgP, visitante[i].emailP);
                                            visitante[i].codigoP = codigo;
                                            system("cls");
                                            if(i < 10)
                                            {
                                                ticket(codigo, letraA, assentos[i], data, hora);
                                            }
                                            if(i >= 10 && i < 20)
                                            {
                                                ticket(codigo, letraB, assentos[i - 10], data, hora);
                                            }
                                            if(i >= 20 && i < 30)
                                            {
                                                ticket(codigo, letraC, assentos[i - 20], data, hora);
                                            }
                                            if(i >= 30 && i < 40)
                                            {
                                                ticket(codigo, letraD, assentos[i - 30], data, hora);
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
                            respondeu = 0; // FLAG PARA SABER SE AS PERGUNTAS FORAM RESPONDIAS
                            x = 0;
                            fflush(stdin); // LIMPA O BUFFER DO TECLADO
                            i = 0;
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
                                    printf("\n\nDigite o codigo do visitante: ");
                                    scanf("%d", &codExc);
                                    fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                    if(strcmp(resp2, "S") == 0)
                                    {
                                        system("cls");
                                        i = 0;
                                        while(i < 53)
                                        {
                                            if(visitantes[i] == codExc)
                                            {
                                                x = 0;
                                                while(x < 3)
                                                {
                                                    if(codExc == (pCodEsp + x)->codigoP)
                                                    {
                                                        printf("Dados do visitante: \n\n");
                                                        dados(visitanteEsp[x].nome, visitanteEsp[x].data, visitanteEsp[x].rgP, visitanteEsp[x].emailP, visitanteEsp[x].codigoP);
                                                        printf("Status: Visitante Especial\n");
                                                        x = 3;
                                                    }
                                                    x++;
                                                }
                                                printf("\nVoce tem certeza que deseja excluir o visitante? (S / N): ");
                                                gets(resp);
                                                if(strcmp(resp, "S") == 0)
                                                {
                                                    y = 0;
                                                    while(y < 3)
                                                    {
                                                        if(statusEspeciais[y] != 0)
                                                        {
                                                            statusEspeciais[y] = 0;
                                                            y = 3;
                                                        }
                                                        y++;
                                                    }
                                                    z = 0;
                                                    while(z < 3)
                                                    {
                                                        if(codExc == (pCodEsp + z)->codigoP)
                                                        {
                                                            strcpy(visitanteEsp[z].nome, "N/A");
                                                            strcpy(visitanteEsp[z].data, "N/A");
                                                            strcpy(visitanteEsp[z].rgP, "N/A");
                                                            strcpy(visitanteEsp[z].emailP, "N/A");
                                                            (pCodEsp + z)->codigoP = 0;
                                                            z = 3;
                                                        }
                                                        z++;
                                                    }
                                                    visitantes[i] = 0;
                                                    printf("Exclusao concluida com sucesso!");
                                                    getch();
                                                    i = 53;
                                                }
                                                if(strcmp(resp, "N") == 0)
                                                {
                                                    system("cls");
                                                    printf("Exclusao cancelada com sucesso.");
                                                    respondeu = 1;
                                                    getch();
                                                    i = 53;
                                                }
                                                encontrou = 1;
                                            }
                                            i++;
                                        }
                                        respondeu = 1;
                                    }
                                    if(strcmp(resp1, "S") == 0 && strcmp(resp2, "N") == 0)
                                    {
                                        system("cls");
                                        i = 0;
                                        while(i < 53)
                                        {
                                            if(visitantes[i] == codExc)
                                            {
                                                x = 0;
                                                while(x < 10)
                                                {
                                                    if(codExc == (pCodRes + x)->codigoP)
                                                    {
                                                        printf("Dados do visitante: \n\n");
                                                        dados(visitanteRes[x].nome, visitanteRes[x].data, visitanteRes[x].rgP, visitanteRes[x].emailP, visitanteRes[x].codigoP);
                                                        printf("Status: Visitante Convidado\n");
                                                        x = 10;
                                                    }
                                                    x++;
                                                }
                                                printf("\nVoce tem certeza que deseja excluir o visitante? (S / N): ");
                                                gets(resp);
                                                if(strcmp(resp, "S") == 0)
                                                {
                                                    y = 0;
                                                    while(y < 10)
                                                    {
                                                        if(statusReservados[y] != 0)
                                                        {
                                                            statusReservados[y] = 0;
                                                            y = 10;
                                                        }
                                                        y++;
                                                    }
                                                    z = 0;
                                                    while(z < 10)
                                                    {
                                                        if(codExc == (pCodRes + z)->codigoP)
                                                        {
                                                            strcpy(visitanteRes[z].nome, "N/A");
                                                            strcpy(visitanteRes[z].data, "N/A");
                                                            strcpy(visitanteRes[z].rgP, "N/A");
                                                            strcpy(visitanteRes[z].emailP, "N/A");
                                                            (pCodRes + z)->codigoP = 0;
                                                            z = 10;
                                                        }
                                                        z++;
                                                    }
                                                    visitantes[i] = 0;
                                                    printf("Exclusao concluida com sucesso.");
                                                    getch();
                                                    i = 53;
                                                }
                                                if(strcmp(resp, "N") == 0)
                                                {
                                                    system("cls");
                                                    printf("Exclusao cancelada com sucesso.");
                                                    respondeu = 1;
                                                    getch();
                                                    i = 53;
                                                }
                                            }
                                            i++;
                                        }
                                        encontrou = 1;
                                        respondeu = 1;
                                    }
                                    if(strcmp(resp1, "N") == 0 && strcmp(resp2, "N") == 0)
                                    {
                                        system("cls");
                                        i = 0;
                                        while(i < 53)
                                        {
                                            if(visitantes[i] == codExc)
                                            {
                                                x = 0;
                                                while(x < 40)
                                                {
                                                    if(codExc == (pCod + x)->codigoP)
                                                    {
                                                        printf("Dados do visitante: \n\n");
                                                        dados(visitante[x].nome, visitante[x].data, visitante[x].rgP, visitante[x].emailP, visitante[x].codigoP);
                                                        printf("Status: Visitante Comum\n");
                                                        x = 40;
                                                    }
                                                    x++;
                                                }
                                                printf("\nVoce tem certeza que deseja excluir o visitante? (S / N): ");
                                                gets(resp);
                                                if(strcmp(resp, "S") == 0)
                                                {
                                                    y = 0;
                                                    while(y < 40)
                                                    {
                                                        if(status[y] != 0)
                                                        {
                                                            status[y] = 0;
                                                            y = 40;
                                                        }
                                                        y++;
                                                    }
                                                    z = 0;
                                                    while(z < 40)
                                                    {
                                                        if(codExc == (pCod + z)->codigoP)
                                                        {
                                                            strcpy(visitante[z].nome, "N/A");
                                                            strcpy(visitante[z].data, "N/A");
                                                            strcpy(visitante[z].rgP, "N/A");
                                                            strcpy(visitante[z].emailP, "N/A");
                                                            (pCod + z)->codigoP = 0;
                                                            z = 40;
                                                        }
                                                        z++;
                                                    }
                                                    visitantes[i] = 0;
                                                    printf("Exclusao concluida com sucesso.");
                                                    encontrou = 1;
                                                    getch();
                                                    i = 53;
                                                }
                                                if(strcmp(resp, "N") == 0)
                                                {
                                                    system("cls");
                                                    printf("Exclusao cancelada com sucesso.");
                                                    respondeu = 1;
                                                    encontrou = 1;
                                                    getch();
                                                    i = 53;
                                                }
                                                encontrou = 1;
                                            }
                                            i++;
                                        }
                                        respondeu = 1;
                                    }
                                    achou = 1;
                                }
                                i++;
                            }
                            if(achou == 0)
                            {
                                printf("Nao ha participantes a serem excluidos.");
                                getch();
                                break;
                            }
                            if(respondeu == 0)
                            {
                                printf("Erro! Responda novamente as perguntas.");
                                getch();
                                break;
                            }
                            if(encontrou == 0)
                            {
                                printf("Nao foi possivel encontrar o visitante, tente novamente.");
                                getch();
                                break;
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
                            system("cls");
                            encontrou = 0;
                            printf("\nTODOS OS VISITANTES\n\n");
                            printf("=====================\n\n");
                            for(i = 0; i < 3; i++)
                            {
                                if(strcmp(visitanteEsp[i].nome, "N/A") != 0)
                                {
                                    dados(visitanteEsp[i].nome, visitanteEsp[i].data, visitanteEsp[i].rgP, visitanteEsp[i].emailP, visitanteEsp[i].codigoP);
                                    printf("Status: Visitante Especial\n");
                                    printf("\n");
                                    encontrou = 1;
                                }
                            }
                            for(i = 0; i < 10; i++)
                            {
                                if(strcmp(visitanteRes[i].nome, "N/A") != 0)
                                {
                                    dados(visitanteRes[i].nome, visitanteRes[i].data, visitanteRes[i].rgP, visitanteRes[i].emailP, visitanteRes[i].codigoP);
                                    printf("Status: Visitante Convidado\n");
                                    printf("\n");
                                    encontrou = 1;
                                }
                            }
                            for(i = 0; i < 40; i++)
                            {
                                if(strcmp(visitante[i].nome, "N/A") != 0)
                                {
                                    dados(visitante[i].nome, visitante[i].data, visitante[i].rgP, visitante[i].emailP, visitante[i].codigoP);
                                    printf("Status: Visitante Comum\n");
                                    printf("\n");
                                    encontrou = 1;
                                }
                            }
                            if(encontrou == 0)
                            {
                                printf("Nao ha visitantes cadastrados.");
                            }
                            getch();
                            break;
                        case 7:
                            break;
                        default:
                            printf("Opcao invalida!");
                            getch();
                            break;
                        } // SWITCH(OP2)
                    } // WHILE (OP != 6)
                    break; // CASE 1;
                case 2:
                    system("cls");
                    fflush(stdin); // LIMPAR BUFFER DO TECLADO
                    encontrou = 0; // FLAG PARA SABER SE HÁ PARTICIPANTES CADASTRADOS
                    i = 0;
                    printf("\n                 REALIZAR SORTEIO\n\n");
                    printf("======================================================\n\n");
                    while(i < 53)
                    {
                        if(visitantes[i] != 0)
                        {
                            printf("Voce tem certeza que deseja realizar o sorteio? (S / N): ");
                            gets(resp3);
                            if(strcmp(resp3, "S") == 0)
                            {
                                numSort = 1 + (rand() % 43);
                                printf("\n\nO numero sorteado foi: %d\n", numSort);
                                if(numSort > 40)
                                {
                                    printf("O visitante sorteado foi: \n");
                                    dados(visitanteEsp[numSort - 41].nome, visitanteEsp[numSort - 41].data, visitanteEsp[numSort - 41].rgP, visitanteEsp[numSort - 41].emailP, visitanteEsp[numSort - 41].codigoP);
                                }
                                if(numSort <= 40)
                                {
                                    printf("O visitante sorteado foi: \n");
                                    dados(visitante[numSort - 1].nome, visitante[numSort - 1].data, visitante[numSort - 1].rgP, visitante[numSort - 1].emailP, visitante[numSort - 1].codigoP);
                                }
                            }
                            if(strcmp(resp3, "N") == 0)
                            {
                                printf("Sorteio cancelado com sucesso!");
                            }
                            getch();
                            encontrou = 1;
                            i = 53;
                        }
                        i++;
                    }
                    if(encontrou == 0)
                    {
                        printf("Nao ha visitantes cadastrados!");
                        getch();
                    }
                    break;
                case 3:
                    system("cls");
                    fflush(stdin); // LIMPAR BUFFER DO TECLADO
                    op3 = 0;
                    while(op3 != 3)
                    {
                        system("cls");
                        printf("\n                 ENVIAR E-MAIL\n\n");
                        printf("======================================================\n\n");
                        printf("1- Escolher visitante\n");
                        printf("2- Todos os visitantes\n");
                        printf("3- Retornar ao menu principal\n");
                        printf("Escolha sua opcao: ");
                        scanf("%d", &op3);
                        switch(op3)
                        {
                        case 1:
                            system("cls");
                            fflush(stdin); // LIMPA O BUFFER DO TECLADO
                            encontrou = 0; // FLAG PARA SABER SE TEM O CODIGO INFORMADO
                            achou = 0;
                            x = 0;
                            printf("\nESCOLHER VISITANTE\n\n");
                            printf("====================\n\n");
                            while(x < 53)
                            {
                                if(visitantes[x] != 0)
                                {
                                    printf("O visitante e um convidado? (S / N): ");
                                    gets(resp1);
                                    printf("O visitante e um especial? (S / N): ");
                                    gets(resp2);
                                    if(strcmp(resp1, "S") == 0)
                                    {
                                        printf("\nDigite o codigo do visitante: ");
                                        scanf("%d", &codEmail);
                                        i = 0;
                                        while(i < 3)
                                        {
                                            if(codEmail == (pCodEsp + i)->codigoP)
                                            {
                                                fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                                printf("\n\nDe: ");
                                                gets(de);
                                                printf("Para: %s\n\n", visitanteEsp[i].emailP);
                                                printf("Digite o conteudo do e-mail: \n\n");
                                                gets(contEmail);
                                                encontrou = 1;
                                                i = 3;
                                                getch();
                                            }
                                            i++;
                                        }
                                        printf("\n\n");
                                        printf("Voce deseja enviar o e-mail? (S / N): ");
                                        gets(resp);
                                        if(strcmp(resp, "S") == 0)
                                        {
                                            printf("\nE-mail enviado com sucesso!");
                                            getch();
                                            x = 53;
                                        }
                                        if(strcmp(resp, "N") == 0)
                                        {
                                            printf("\nE-mail cancelado com sucesso!");
                                            getch();
                                            x = 53;
                                        }
                                    }
                                    if(strcmp(resp1, "S") == 0 && strcmp(resp2, "N") == 0)
                                    {
                                        printf("\nDigite o codigo do visitante: ");
                                        scanf("%d", &codEmail);
                                        i = 0;
                                        while(i < 10)
                                        {
                                            if(codEmail == (pCodRes + i)->codigoP)
                                            {
                                                fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                                printf("\n\nDe: ");
                                                gets(de);
                                                printf("Para: %s\n\n", visitanteRes[i].emailP);
                                                printf("Digite o conteudo do e-mail: \n\n");
                                                gets(contEmail);
                                                encontrou = 1;
                                                i = 10;
                                                getch();
                                            }
                                            i++;
                                        }
                                        printf("\n\n");
                                        printf("Voce deseja enviar o e-mail? (S / N): ");
                                        gets(resp);
                                        if(strcmp(resp, "S") == 0)
                                        {
                                            printf("E-mail enviado com sucesso!");
                                            x = 53;
                                            getch();
                                        }
                                        if(strcmp(resp, "N") == 0)
                                        {
                                            printf("E-mail cancelado com sucesso!");
                                            x = 53;
                                            getch();
                                        }
                                    }
                                    if(strcmp(resp1, "N") == 0 && strcmp(resp2, "N") == 0)
                                    {
                                        printf("\nDigite o codigo do visitante: ");
                                        scanf("%d", &codEmail);
                                        i = 0;
                                        while(i < 40)
                                        {
                                            if(codEmail == (pCod + i)->codigoP)
                                            {
                                                fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                                printf("\n\nDe: ");
                                                gets(de);
                                                printf("Para: %s\n\n", visitante[i].emailP);
                                                printf("Digite o conteudo do e-mail: \n\n");
                                                gets(contEmail);
                                                encontrou = 1;
                                                i = 40;
                                                getch();
                                            }
                                            i++;
                                        }
                                        printf("\n\n");
                                        printf("Voce deseja enviar o e-mail? (S / N): ");
                                        gets(resp);
                                        if(strcmp(resp, "S") == 0)
                                        {
                                            printf("E-mail enviado com sucesso!");
                                            getch();
                                            x = 53;
                                        }
                                        if(strcmp(resp, "N") == 0)
                                        {
                                            printf("E-mail cancelado com sucesso!");
                                            getch();
                                            x = 53;
                                        }
                                    }
                                    if(encontrou == 0)
                                    {
                                        printf("Nao foi possivel encontrar o visitante, tente novamente!");
                                        x = 53;
                                        getch();
                                    }
                                    achou = 1;
                                }
                                x++;
                            }
                            if(achou == 0)
                            {
                                printf("Nao ha visitantes cadastrados!");
                                getch();
                            }
                            break;
                        case 2:
                            system("cls");
                            fflush(stdin); // LIMPAR BUFFER DO TECLADO
                            i = 0;
                            encontrou = 0;
                            printf("\nTODOS OS VISITANTES\n\n");
                            printf("=====================\n\n");
                            while(i < 53)
                            {
                                if(visitantes[i] != 0)
                                {
                                    fflush(stdin); // LIMPA O BUFFER DO TECLADO
                                    printf("De: ");
                                    gets(de);
                                    printf("Para: Todos os visitantes\n\n");
                                    printf("Digite o conteudo do e-mail: \n\n");
                                    gets(contEmail);
                                    getch();
                                    printf("\n\n");
                                    printf("Voce deseja enviar o e-mail? (S / N): ");
                                    gets(resp);
                                    if(strcmp(resp, "S") == 0)
                                    {
                                        printf("E-mail enviado com sucesso!");
                                        getch();
                                    }
                                    if(strcmp(resp, "N") == 0)
                                    {
                                        printf("E-mail cancelado com sucesso!");
                                        getch();
                                    }
                                    encontrou = 1;
                                    i = 53;
                                }
                                i++;
                            }
                            if(encontrou == 0)
                            {
                                printf("Nao ha visitantes cadastrados!");
                                getch();
                            }
                            break;
                        case 3:
                            break;
                        default:
                            printf("Opcao invalida!");
                            getch();
                            break;
                        } // SWITCH(OP3)
                    } // WHILE (OP3 != 3)
                    break;
                default:
                    printf("Opcao invalida!");
                    getch();
                    break;
                } // SWITCH (OP1)
                tentar = 1;
            }
        }
        else
        {
            printf("\nUsuario ou senha incorreta, tente novamente.\n");
            tentar = 0;
            printf("\n\n\n\n\n\n© 2018 - GATES IT SOLUTIONS\n");
            getch();
        } // IF (LOGIN)
    } // WHILE
} // MAIN



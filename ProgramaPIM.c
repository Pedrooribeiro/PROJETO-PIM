#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

    // FUNCÃO PARA COLETAR DADOS
int coletarDados(int nome, int dataNasc, int rg, int email)
{
    int dados = 0;
    fflush(stdin); // LIMPAR BUFFER DO TECLADO
    dados += printf("Informe o nome completo do visitante: ");
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
int ticket(int funcaoCodigo, int nome, int dataNasc, int rg, int email, int letra, int assento)
{
    int dados = 0;
    dados += printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    dados += printf("                              CODIGO: %d\n", funcaoCodigo);
    dados += printf("                              NOME COMPLETO: %s\n", nome);
    dados += printf("                              DATA DE NASCIMENTO: %s\n", dataNasc);
    dados += printf("                              RG: %s\n", rg);
    dados += printf("                              E-MAIL: %s\n", email);
    dados += printf("                              ASSENTO: %s%d\n", letra, assento);
    dados += printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    return dados;
}


main()
{
    char user[] = "un", password[] = "pa", usuario[20], senha[20];
    char resp1[10], resp2[10];
    char nomeComp[50], dataNasc[11], rg[13], email[30];
    char letraEsp[] = "E", letraRes[] = "R", letraA[] = "A", letraB[] = "B", letraC[] = "C", letraD[] = "D";
    int i, cod, tentar, op1, op2, codigo, visitantes[53], nAssentoReservado;
    int assentos[40], assentosReservados[10], assentosEspeciais[3], status[40], statusReservados[10], statusEspeciais[3], encontrou, achou;

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
                printf("1- Gerenciar visitante\n");
                printf("2- Realizar sorteio\n");
                printf("3- Enviar comunicado por e-mail\n");
                printf("Escolha sua opcao: ");
                scanf("%d", &op1);
                system("cls");

                switch(op1)
                {
                    case 1:
                        while(op2 != 6)
                        {
                            system("cls");
                            // Apresenta o menu secundário da opção 1
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
                                        fflush(stdin); // LIMPA O BUFFER DO TECLADO
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
                                                    ticket(codigo, nomeComp, dataNasc, rg, email, letraEsp, assentosEspeciais[i]);
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
                                        }
                                        if(strcmp(resp1, "S") == 0 && strcmp(resp2, "N") == 0)
                                        {
                                            i = 0;
                                            while(i < 10)
                                            {
                                                if(statusReservados[i] == 0)
                                                {
                                                    system("cls");
                                                    printf("Informe o numero do assento reservado: ");
                                                    scanf("%d", &nAssentoReservado);
                                                    if(statusReservados[nAssentoReservado - 1 ] == 0)
                                                    {
                                                        statusReservados[nAssentoReservado - 1] = 1;
                                                        // FUNÇÃO PARA COLETAR DADOS
                                                        coletarDados(nomeComp, dataNasc, rg, email);
                                                        // WHILE PARA INCREMENTAR O NÚMERO DO ASSENTO
                                                        system("cls");
                                                        ticket(codigo, nomeComp, dataNasc, rg, email, letraRes, nAssentoReservado);
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
                                                        ticket(codigo, nomeComp, dataNasc, rg, email, letraA, assentos[i]);
                                                    }
                                                    if(i >= 10 && i < 20)
                                                    {
                                                        ticket(codigo, nomeComp, dataNasc, rg, email, letraB, assentos[i - 10]);
                                                    }
                                                    if(i >= 20 && i < 30)
                                                    {
                                                        ticket(codigo, nomeComp, dataNasc, rg, email, letraC, assentos[i - 20]);
                                                    }
                                                    if(i >= 30 && i < 40)
                                                    {
                                                        ticket(codigo, nomeComp, dataNasc, rg, email, letraD, assentos[i - 30]);
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
                                        }
                                    }
                                }
                            }
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



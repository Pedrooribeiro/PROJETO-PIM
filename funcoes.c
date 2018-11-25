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
int ticket(int codigo, int letra, int assento, int data, int hora)
{
    int dados = 0;
    dados += printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    dados += printf("::                              CODIGO: %d\t\t\t\t\t\t::\n", codigo);
    dados += printf("::                              DATA: %s\t\t\t\t\t::\n", data);
    dados += printf("::                              HORA: %s\t\t\t\t\t\t::\n", hora);
    dados += printf("::                              ASSENTO: %s%d\t\t\t\t\t\t::\n", letra, assento);
    dados += printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    return dados;
}

// FUNÇÃO PARA MOSTRAR OS DADOS
int dados(int nomeComp, int dataNasc, int rg, int email, int codigo)
{
    int dados = 0;
    dados += printf("Nome: %s\n", nomeComp);
    dados += printf("Data de nascimento: %s\n", dataNasc);
    dados += printf("RG: %s\n", rg);
    dados += printf("E-mail: %s\n", email);
    dados += printf("Codigo: %d\n", codigo);
    return dados;
}

// STRUCT PARA CRIAR VISITANTE
struct Pessoa
{
    char nome[50];
    char data[11];
    char rgP[13];
    char emailP[50];
    int codigoP;
};

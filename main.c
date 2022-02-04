#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define Nomes 30

typedef struct{
    char nomeInimigo[Nomes];
    int hpMonstro;
    int dano;
    char imagem[1000];

} tMonsterConfig;


int menu(){
    int opcao;

    printf("\n\n*************** BATTLE SLAYER RPG!!! ***************");
    printf("\n           ________________________________");
    printf("\n***********       1) Jogar duelo mortal    ************");
    printf("\n***********       2) Configurar            ************");
    printf("\n***********       3) Sair                  ************");
    printf("\n***********________________________________************");

    printf("\n\nEscolha a opcao desejada:");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        INTRO();
        break;
    case 2:
        CONFIGURAR();
        break;
    case 3:
        printf("Saindo...");
        return 0;

    default:
        printf("\n\nOpção inválida!!!");
    }

    return 1;
}

void CONFIGURAR ()
{
    system("cls");

    tMonsterConfig newConfig;

    FILE *arq;

    printf("\nConfigurando o jogo...\n");

    int ConfigOpcao;
    printf("\n\n*************** CONFIGURACAO!!! ***************\n\n");
    printf("\n           ________________________________");
    printf("\n***********       1) Configurar Inimigos   ************");
    printf("\n***********       2) Sair                  ************");
    printf("\n***********________________________________************");
    printf("\n\nEscolha a opcao desejada:");
    scanf("%d", &ConfigOpcao);

    switch(ConfigOpcao){
    case 1:
        system("cls");

        printf("\nDigite o Nome do Inimigo: ");
        fflush(stdin);
        fgets(newConfig.nomeInimigo, Nomes, stdin);

        printf("\nDigite o valor de HP(Hit Points) da Criatura: ");
        scanf("%i", &newConfig.hpMonstro);

        printf("\nDigite o valor de Dano no acerto da Criatura: ");
        scanf("%i", &newConfig.dano);

        arq = fopen("Inimigos.qz", "ab");

        if(arq == NULL){
            printf("\nNão foi possível abrir o arquivo.");
        }
        else{
            fwrite(&newConfig, sizeof(tMonsterConfig), 1, arq);
            fclose(arq);
        }

        fclose(arq);
        printf("\nNome do Inimigo: %s", newConfig.nomeInimigo);
        printf("HP: %d", newConfig.hpMonstro);
        printf("\nDANO: %d", newConfig.dano);

        Sleep(4000);
        return CONFIGURAR();
    case 2:
        system("cls");
        return menu();
    default:
        printf("OPCAO INVALIDA!");
        Sleep(2000);
        return CONFIGURAR();
    }
}

int INTRO (){
    system("cls");

    char nomePers[Nomes];

    int opcao;

    //introdução ao jogo
    printf("Ola nobre aventureiro");
    Sleep(3000);

    printf("\nOs monstros estao invadindo! Libere sua furia e salve nosso vilarejo");
    Sleep(3000);

    printf("\n\n\nPrimeiramente diga seu Nome que sera lembrado para toda a Eternidade!!\nNome: ");
    scanf("%s", nomePers);

    Sleep(2000);
    printf("\n\n%s va ao Arsenal e compre os melhores equipamentos \n\nBoa Sorte Aventureiro! \n\n", nomePers);
    Sleep(2000);
    ARSENAL(nomePers);

    return 1;
}

void ARSENAL(char *nomePers){
    system("cls");
    int moedas =10;
    *nomePers = *nomePers;
    int opcao;
    int pocoes = 0, ataque = 2, defesa = 0;

    printf("Ola meu nome e Jubileu voce deve estar aqui em busca de fortes equipamentos,\neu tenho oque voce precisa! Qual seu nome? \n");
    Sleep(2000);
    printf("\nOh! Mas que nome esquisito! Muito bem %s voce tem 10 MOEDAS para comprar meus produtos...", nomePers);
    Sleep(3000);

    for(int i=0; i<=moedas;){
        system("cls");
        printf("\n|------------------------------MERCADORIA----------------------------|");
        printf("\n|NOME DOS ITENS                                      SALDO %d|",moedas);
        printf("\n|1-)Espada De Bronze       (base+3)          4 MOEDAS            ");
        printf("\n|2-)Capacete De Bronze     (Reduz dano em 1) 3 MOEDAS            ");
        printf("\n|3-)Pocao De Vida          (Cura 5 de vida)  2 MOEDAS            ");
        printf("\n|4-)Sair                                                         ");
        printf("\n\n-");

        scanf("%d", &opcao);

        if (opcao == 4){
            break;
        }

        switch(opcao){
        case 1:
            if (moedas >= 4){
                moedas = moedas - 4;
                printf("\nComprou uma Espada de Cobre!");
                ataque = 3; 
                Sleep(1000);
            }
            else{
                printf("\nVoce nao tem moedas para comprar uma Espada");
                Sleep(1000);
            }
            break ;
        case 2:
            if (moedas >= 3){
                moedas = moedas - 3;
                printf("\nComprou um Capacete de Cobre!");
                defesa = 1;
                Sleep(1000);
            }
            else{
                printf("\nVoce nao tem moedas para comprar um Capacete");
                Sleep(1000);
            }
            break ;
        case 3:
            if (moedas >= 2){
                moedas = moedas - 2;
                printf("\nComprou uma Pocao de Vida!");
                pocoes = pocoes+1;
                Sleep(1000);
            }
            else{
                printf("\nVoce nao tem moedas para comprar uma Pocao");
                Sleep(1000);
            }
            break ;
        default:
            printf("\n\nOpção inválida!!!");
            break;
        }
    }
    printf("\nAgora voce esta pronto para a batalha!\n");
    Sleep(2000);
    Batalha_teste(&ataque,&defesa,&pocoes,&moedas);
}

void Batalha_teste(int *ataque, int *defesa, int *pocoes,int *moedas){
    system("cls");
    int vidaplayer = 20;
    int vidalimite = 20;
    int ataquemostro = 3;
    int opcao;
    int fugiu = 0;
    int dificuldade = 1;
    *ataque = *ataque;
    *defesa = *defesa;
    *pocoes = *pocoes;
    *moedas = *moedas;

    printf("Olha! Um monstro na sua frente! Tente lutar contra ele com seus equipamentos\n");
    Sleep(2000);

    for(int vidateste=15; vidateste>1;)
    {
        system("cls");
        if(vidaplayer <=0)
        {
            printf("\nVoce morreu......");
            Sleep(5000);
            main();
            return 0;
        }
        printf("\n|-------------------------BATALHA----------------------------|");
        printf("\nVoce encontra na sua frente um Slime! HP:%d\n\n",vidateste);
        printf("\nQual sua proxima acao?");
        printf("\n|HP: %d\n",vidaplayer);
        printf("\n|1-)Atacar");
        printf("\n|2-)Tomar Pocao");
        printf("\n|3-)Correr");
        printf("\n\n-");

        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            vidateste = vidateste - *ataque;
            printf("\nVoce atacou o monstro causando %d de dano",*ataque);
            Sleep(2000);
            if(vidateste <=0)
            {
                system("cls");
                printf("\nBoa! É isso ai voce acabou ele");
                *moedas = *moedas+10;
                printf("\nCom isso voce rebece mais 10 moedas, totalizando %d moedas", *moedas);
                Sleep(2000);
                ARSENAL_REAL(&*ataque,&*defesa,&*pocoes,&*moedas, &dificuldade, &vidaplayer, &vidalimite);
            }
            vidaplayer = vidaplayer - (ataquemostro-*defesa);
            printf("\nO Monstro te ataca de volta e causa %d de dano, porem sua defesa bloqueia %d de dano",ataquemostro,*defesa);
            Sleep(2000);
            break;
        case 2:
            if (*pocoes > 0)
            {
                if (vidaplayer < 20)
                {
                    vidaplayer = vidaplayer + 5;
                    if (vidaplayer > 20)
                    {
                        vidaplayer = 20;
                    }
                    *pocoes = *pocoes - 1;
                    printf("\nVoce toma uma pocao recuperando vida, voce tem %d pocoes restantes",*pocoes);
                    vidaplayer = vidaplayer - (ataquemostro-*defesa);
                    Sleep(2000);
                    printf("\nO Monstro te ataca de volta e causa %d de dano, porem sua defesa bloqueia %d de dano",ataquemostro,*defesa);
                    Sleep(2000);
                }
                else
                {
                    printf("\nVoce esta de vida cheia, voce tem %d pocoes restantes",*pocoes);
                    Sleep(2000);
                }
            }
            else
            {
                printf("\nVoce nao possui pocoes");
                Sleep(2000);
            }
            break;
        case 3:
            srand(time(NULL));
            int r = rand() % 6;
            if (r == 0)
            {
                fugiu = 1;
                vidateste = 0;
                Sleep(2000);
            }
            else
            {
                printf("\nVoce tenta fugir da criatura...\n...mas nao consegue");
                Sleep(2000);
                vidaplayer = vidaplayer - ataquemostro;
                printf("\nO Monstro te ataca de volta e causa %d de dano",ataquemostro);
                Sleep(2000);
            }
            break;
        }
    }

    if (fugiu == 1)
    {
        printf("\nVoce conseguiu escapar da criatura, porem nao recuperou as recompensas deixadas por ela");
        Sleep(2000);
        ARSENAL_REAL(&*ataque,&*defesa,&*pocoes,&*moedas,&dificuldade,&vidaplayer, &vidalimite);
    }
    else
    {
        system("cls");
        printf("\nBoa! É isso ai voce acabou ele");
        *moedas = *moedas+10;
        printf("\nCom isso voce rebece mais 10 moedas, totalizando %d moedas", *moedas);
        Sleep(2000);
        ARSENAL_REAL(&*ataque,&*defesa,&*pocoes,&*moedas, &dificuldade, &vidaplayer, &vidalimite);
    }
}
void ARSENAL_REAL(int *ataque, int *defesa, int *pocoes,int *moedas, int *dificuldade, int *vidaplayer, int *vidalimite)
{
    system("cls");
    *ataque = *ataque;
    *defesa = *defesa;
    *pocoes = *pocoes;
    *moedas = *moedas;
    *dificuldade = *dificuldade;
    *vidaplayer = *vidaplayer;
    *vidalimite = *vidalimite;
    int opcao;

    if (*dificuldade < 3){
        printf("Ola, voce esta de volta! Forjei novas armas para voce enfrentar monstros mais fortes\n");
        Sleep(3000);
        printf("Elas estão mais caras, mas porque usei do melhor que tinha, pode crer em minha palavra!\n");
    }else{
        printf("Jovem aventureiro! Voce esta de volta, percebo que enfrentou muitos desafios nao é?\n");
        Sleep(3000);
        printf("Mas nao se preocupe, forjei algo especial para voce utilizando rochas especiais que coletei a pouco tempo!\n");
        Sleep(3000);
        printf("De uma olhada!!\n");
    }
    Sleep(3000);

    for(int i=0; i<=*moedas;)
    {
        if (*dificuldade == 1)
        {
            system("cls");
            printf("\n|------------------------------MERCADORIA-----------------------|");
            printf("\n|NOME DOS ITENS                                      SALDO %d   |",*moedas);
            printf("\n|1-)Espada De Ferro       (Base+5)           7 MOEDAS           |");
            printf("\n|2-)Capacete De Ferro     (Reduz dano em 2)  6 MOEDAS           |");
            printf("\n|3-)Pocao De Vida         (Cura 5 de vida)   2 MOEDAS           |");
            printf("\n|4-)Sair                                                        |");
            printf("\n\n-");
        }
        else if (*dificuldade == 2)
        {
            system("cls");
            printf("\n|------------------------------MERCADORIA-----------------------|");
            printf("\n|NOME DOS ITENS                                      SALDO %d   |",*moedas);
            printf("\n|1-)Espada De Diamante     (Base+9)          11 MOEDAS          |    ");
            printf("\n|2-)Capacete De Diamante   (Reduz dano em 6) 9 MOEDAS           |   ");
            printf("\n|3-)Pocao De Vida          (Cura 5 de vida)  2 MOEDAS           |   ");
            printf("\n|4-)Sair                                                        |    ");
            printf("\n----------------------------------------------------------------|");

            printf("\n|------------------------Opcoes--Especiais----------------------|");
            printf("\n|5-)Bracelete da Vida     (+5 de vida maxima)5 MOEDAS           |  ");
            printf("\n|6-)Restaurar HP                             10 MOEDAS          |");

            printf("\n\n-");

        }
        else if (*dificuldade >= 3)
        {
            system("cls");
            printf("\n|------------------------------MERCADORIA-----------------------|");
            printf("\n|NOME DOS ITENS                                      SALDO %d   |",*moedas);
            printf("\n|1-)Espada De Obisidiana   (Base+15)         15 MOEDAS          |    ");
            printf("\n|2-)Capacete De Obisidiana (Reduz dano em 9) 12 MOEDAS          |   ");
            printf("\n|3-)Pocao De Vida          (Cura 5 de vida)  2 MOEDAS           |   ");
            printf("\n|4-)Sair                                                        |    ");
            printf("\n----------------------------------------------------------------|");

            printf("\n|------------------------Opcoes--Especiais----------------------|");
            printf("\n|5-)Bracelete da Vida    (+5 de vida maxima) 7 MOEDAS           | ");
            printf("\n|6-)Restaurar HP                             10 MOEDAS          |");

            printf("\n\n-");

        }
        scanf("%d", &opcao);

        //Tem que fazer fora do case pq C e uma merda, basicamente ele sai do for
        if (opcao == 4)
        {
            break;
        }

        switch(*dificuldade)
        {

        //DIFICULDADE 1
        case 1:
            switch(opcao)
            {
            case 1:
                if ((*moedas - 7) >= 0)
                {
                    *moedas = *moedas - 7;
                    printf("\nComprou uma Espada de Ferro!");
                    *ataque = 7;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar uma Espada");
                    Sleep(1000);
                }
                break ;
            case 2:
                if ((*moedas - 6) >= 0)
                {
                    *moedas = *moedas - 6;
                    printf("\nComprou um Capacete de Ferro!");
                    *defesa = 2;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar um Capacete");
                    Sleep(1000);
                }
                break ;
            case 3:
                if ((*moedas - 2) >= 0)
                {
                    *moedas = *moedas - 2;
                    printf("\nComprou uma Pocao de Vida!");
                    *pocoes = *pocoes+1;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar uma Pocao");
                    Sleep(1000);
                }
                break ;
            default:
                printf("\n\nOpção inválida!!!");
                break;
            }
            break;

        //DIFICULDADE 2
        case 2:
            switch(opcao)
            {
            case 1:
                if ((*moedas - 11) >= 0)
                {
                    *moedas = *moedas - 11;
                    printf("\nComprou uma Espada de Diamante!");
                    *ataque = 9;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar uma Espada");
                    Sleep(1000);
                }
                break ;
            case 2:
                if ((*moedas - 9) >= 0)
                {
                    *moedas = *moedas - 9;
                    printf("\nComprou um Capacete de Diamante!");
                    *defesa = 6;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar um Capacete");
                    Sleep(1000);
                }
                break ;
            case 3:
                if ((*moedas - 2) >= 0)
                {
                    *moedas = *moedas - 2;
                    printf("\nComprou uma Pocao!");
                    *pocoes = *pocoes+1;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar uma Pocao");
                    Sleep(1000);
                }
                break ;
            case 5:


                if ((*moedas - 5) >= 0)
                {
                    *moedas = *moedas - 5;
                    printf("\nComprou um Bracelete!");
                    *vidalimite = *vidalimite+5;
                    *vidaplayer = *vidaplayer+5;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar um Bracelete");
                    Sleep(1000);
                }break;
            case 6:
                 if ((*moedas - 10) >= 0)
                {
                    *moedas = *moedas - 10;
                    printf("\nVoce Recuperou toda sua Vida!");
                    *vidaplayer = *vidalimite;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para recuperar sua vida");
                    Sleep(1000);
                }break;

            default:
                printf("\n\nOpção inválida!!!");
                break;
            }
            break;

        //DIFICULDADE 3
        case 3:
            switch(opcao)
            {
            case 1:
                if ((*moedas - 15) >= 0)
                {
                    *moedas = *moedas - 11;
                    printf("\nComprou uma Espada de Obisidiana!");
                    *ataque = 15;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar uma Espada");
                    Sleep(1000);
                }
                break ;
            case 2:
                if ((*moedas - 12) >= 0)
                {
                    *moedas = *moedas - 9;
                    printf("\nComprou um Capacete de Obisidiana!");
                    *defesa = 9;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar um Capacete");
                    Sleep(1000);
                }
                break ;
            case 3:
                if ((*moedas - 2) >= 0)
                {
                    *moedas = *moedas - 2;
                    printf("\nComprou uma Pocao!");
                    *pocoes = *pocoes+1;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar uma Pocao");
                    Sleep(1000);
                }
                break ;
            case 5:
                if ((*moedas - 7) >= 0)
                {
                    *moedas = *moedas - 7;
                    printf("\nComprou outro Bracelete!");
                    *vidalimite = *vidalimite+5;
                    *vidaplayer = *vidaplayer+5;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para comprar outro Bracelete");
                    Sleep(1000);
                }break;
            case 6:
                 if ((*moedas - 10) >= 0)
                {
                    *moedas = *moedas - 10;
                    printf("\nVoce Recuperou toda sua Vida!");
                    *vidaplayer = *vidalimite;
                    Sleep(1000);
                }
                else
                {
                    printf("\nVoce nao tem moedas para recuperar sua vida");
                    Sleep(1000);
                }break;

            default:
                printf("\n\nOpção inválida!!!");
                break;
            }
            break;
        }
    }
    printf("\nAgora voce esta pronto para a batalha!\n");
    Sleep(2000);
    JOGAR(&*ataque,&*defesa,&*pocoes,&*moedas,&*dificuldade, &*vidaplayer, &*vidalimite);
}


void limparVetFlags(int flagMonstro[20])
{
    for(int i=0;i<20;i++)
    {
        flagMonstro[i] = 0;
    }
}

int CarregarMonstro(tMonsterConfig VetorMonstro[20]){
    FILE *arq;
    int i;
    arq = fopen("Inimigos.qz", "rb");

    if(arq == NULL)
    {
        printf("\nNão foi possível abrir o arquivo.");
    }else
    {
        i = 0;
        fread(&VetorMonstro[i],sizeof(tMonsterConfig),1,arq);
        while(!feof(arq) && i<20)
        {
            i++;
            fread(&VetorMonstro[i],sizeof(tMonsterConfig),1,arq);
        }
        fclose(arq);
    }
    return i;
}

int RetornaArrayVazio(int Vetor[20], int tamanho)
{
    int contagem;
    for (int i=0; i<tamanho; i++){
        if (Vetor[i] == 0){
            contagem++;
        }
    }
    if (contagem == tamanho)
    {
        return 0; // ESTA VAZIO
    }
    else
    {
        return 1; // NAO ESTA VAZIO
    }
}

int JOGAR(int *ataque, int *defesa, int *pocoes,int *moedas, int *dificuldade, int *vidalimite, int *vidaplayer)
{
    system("cls");

    //VARIAVEIS EM GERAL
    int QtdMonstroArquivo,MonstroEscolhido,nro_aleatorio;
    int opcao;
    int fugiu = 0;
    int dano_monstro;
    int hp_monstro;
    char nome_monstro[30];

    //PONTEIROS
    *ataque = *ataque;
    *defesa = *defesa;
    *pocoes = *pocoes;
    *moedas = *moedas;
    *dificuldade = *dificuldade;
    *vidaplayer = *vidaplayer ;
    *vidalimite = *vidalimite;

    //VETORES
    tMonsterConfig VetorMonstro[20];
    tMonsterConfig Monster;
    tMonsterConfig VetorDificuldade[20];

    //TENTA ABRIR ARQUIVO SENÃO NEM FUNCIONA NADA
    FILE *arq;
    arq = fopen("Inimigos.qz", "rb");

    if(arq == NULL)
    {
        printf("\nNão foi possível abrir o arquivo, tente cadastrar monstros");
        Sleep(5000);
        return menu();
    }
    else
    {
        int flagMonstro[20];
        limparVetFlags(flagMonstro);

        QtdMonstroArquivo = CarregarMonstro(VetorMonstro);

        srand((unsigned)time(NULL));

        //BASICAMENTE ELE FAZ OQUE A FUNCAO DE CARREGAR ARQUIVO FAZ, SÓ QUE AQUI
        //VOU ALIMENTAR OUTRO VETOR
        int i = 0;
        int j = 0;

        switch(*dificuldade)
        {
        case 1:
            while(!feof(arq) && i<QtdMonstroArquivo)
            {
                fread(&VetorMonstro[i],sizeof(tMonsterConfig),1,arq);
                if (VetorMonstro[i].hpMonstro > 0 && VetorMonstro[i].hpMonstro <= 25)
                {
                    VetorDificuldade[j] = VetorMonstro[i];
                    j++;
                }
                i++;
            }
            nro_aleatorio = rand() % j;
            strcpy(nome_monstro,VetorDificuldade[nro_aleatorio].nomeInimigo);
            dano_monstro = VetorDificuldade[nro_aleatorio].dano;
            hp_monstro = VetorDificuldade[nro_aleatorio].hpMonstro;
            break;
        case 2:
            while(!feof(arq) && i<QtdMonstroArquivo)
            {
                fread(&VetorMonstro[i],sizeof(tMonsterConfig),1,arq);
                if (VetorMonstro[i].hpMonstro > 25 && VetorMonstro[i].hpMonstro < 50)
                {
                    VetorDificuldade[j] = VetorMonstro[i];
                    j++;
                }
                i++;
            }
            nro_aleatorio = rand() % j;
            strcpy(nome_monstro,VetorDificuldade[nro_aleatorio].nomeInimigo);
            dano_monstro = VetorDificuldade[nro_aleatorio].dano;
            hp_monstro = VetorDificuldade[nro_aleatorio].hpMonstro;
            break;
        case 3:
            while(!feof(arq) && i<QtdMonstroArquivo)
            {
                fread(&VetorMonstro[i],sizeof(tMonsterConfig),1,arq);
                if (VetorMonstro[i].hpMonstro >= 50 && VetorMonstro[i].hpMonstro < 75)
                {
                    VetorDificuldade[j] = VetorMonstro[i];
                    j++;
                }
                i++;
            }
            nro_aleatorio = rand() % j;
            strcpy(nome_monstro,VetorDificuldade[nro_aleatorio].nomeInimigo);
            dano_monstro = VetorDificuldade[nro_aleatorio].dano;
            hp_monstro = VetorDificuldade[nro_aleatorio].hpMonstro;
            break;

        case 4:
            while(!feof(arq) && i<QtdMonstroArquivo)
            {
                fread(&VetorMonstro[i],sizeof(tMonsterConfig),1,arq);
                if (VetorMonstro[i].hpMonstro >= 75 && VetorMonstro[i].hpMonstro <= 150)
                {
                    VetorDificuldade[j] = VetorMonstro[i];
                    j++;
                }
                i++;
            }
            nro_aleatorio = rand() % j;
            strcpy(nome_monstro,VetorDificuldade[nro_aleatorio].nomeInimigo);
            dano_monstro = VetorDificuldade[nro_aleatorio].dano;
            hp_monstro = VetorDificuldade[nro_aleatorio].hpMonstro;
            break;}

        if (*dificuldade >= 4)
        {
            printf("Parece que os monstros se foram!\n");
            printf("A vila esta a salvo!!Parabens voce conseguiu!!!\n");
            Sleep(2000);
            printf("\n\nObrigado por Jogar ;)\n\n\n");
            printf("\nJOGO POR: Pedro Sagradim, Gabriel Rodrigues e Eduardo Krapas!\n");
            Sleep(5000);
            system("cls");
            return menu();
        }
        else
        {
            printf("Olha! Um monstro na sua frente! Tente lutar contra ele!\n");
            printf("Vamos Lá!\n");
            Sleep(2000);

            if(hp_monstro == 0 || dano_monstro == 0)
            {
                system("cls");
                printf("O inimigo era tao fraco que desistiu da luta =P");
                Sleep(4000);
                main();
                return 0;
            }

            for(hp_monstro; hp_monstro>0;)
            {
                if(*vidaplayer <=0)
                {
                    system("cls");
                    printf("\nVoce morreu......");
                    Sleep(3000);
                    return menu();
                }

                system("cls");
                printf("\n|-------------------------BATALHA----------------------------|");
                printf("\nVoce encontra na sua frente um %s! HP:%d\n\n",nome_monstro, hp_monstro);
                printf("\nQual sua proxima acao?");
                printf("\n|HP: %d\n",*vidaplayer);
                printf("\n|1-)Atacar");
                printf("\n|2-)Tomar Pocao");
                printf("\n|3-)Correr");
                printf("\n\n-");

                scanf("%d", &opcao);
                switch(opcao)
                {
                case 1:
                    hp_monstro = hp_monstro - *ataque;
                    printf("\nVoce atacou o monstro causando %d de dano",*ataque);
                    Sleep(2000);
                    if(hp_monstro <=0)
                    {
                        system("cls");
                        printf("\nBoa! É isso ai voce acabou ele");
                        int moedas_adic = (VetorDificuldade[nro_aleatorio].hpMonstro)/2;
                        *moedas = *moedas + floor(moedas_adic);
                        printf("\nCom isso voce rebece mais %d, moedas totalizando %d moedas", moedas_adic, *moedas);
                        *dificuldade = *dificuldade+1;
                        Sleep(2000);
                        ARSENAL_REAL(&*ataque,&*defesa,&*pocoes,&*moedas, &*dificuldade, &*vidaplayer, &*vidalimite);
                    }
                    if(dano_monstro-*defesa <=0){
                        *vidaplayer = *vidaplayer;
                    }else{
                    *vidaplayer = *vidaplayer - (dano_monstro-*defesa);}
                    printf("\nO Monstro te ataca de volta e causa %d de dano, porem sua defesa bloqueia %d de dano",dano_monstro,*defesa);
                    Sleep(2000);
                    break;
                case 2:
                    if (*pocoes > 0)
                    {
                        if (*vidaplayer < *vidalimite)
                        {
                            *vidaplayer = *vidaplayer + 5;
                            if (*vidaplayer > *vidalimite)
                            {
                                *vidaplayer = *vidalimite;
                            }
                            *pocoes = *pocoes - 1;
                            printf("\nVoce toma uma pocao recuperando vida, voce tem %d pocoes restantes",*pocoes);
                            if(dano_monstro-*defesa <=0){
                                *vidaplayer = *vidaplayer;
                            }else{
                                *vidaplayer = *vidaplayer - (dano_monstro-*defesa);
                            }
                            printf("\nO Monstro te ataca de volta e causa %d de dano, porem sua defesa bloqueia %d de dano",dano_monstro,*defesa);
                            Sleep(2000);
                        }
                        else
                        {
                            printf("\nVoce esta de vida cheia, voce tem %d pocoes restantes",*pocoes);
                            Sleep(2000);
                        }
                    }
                    else
                    {
                        printf("\nVoce nao possui pocoes");
                        Sleep(2000);
                    }
                    break;
                case 3:
                    srand((unsigned)time(NULL));
                    int r = rand() % 6;
                    if (r == 0)
                    {
                        fugiu = 1;
                        hp_monstro = 0;
                        Sleep(2000);
                    }
                    else
                    {
                        printf("\nVoce tenta fugir da criatura...\n...mas nao consegue");
                        Sleep(2000);
                        if(dano_monstro-*defesa <=0){
                            *vidaplayer = *vidaplayer;
                        }else{
                            *vidaplayer = *vidaplayer - (dano_monstro-*defesa);
                        }
                        printf("\nO Monstro te ataca e causa %d de dano, porem sua defesa bloqueia %d de dano",dano_monstro,*defesa);
                        Sleep(2000);
                    }
                    break;
                }
            }

            if (fugiu == 1)
            {
                printf("\nVoce conseguiu escapar da criatura, porem nao recuperou as recompensas deixadas por ela");
                Sleep(2000);
                ARSENAL_REAL(&*ataque,&*defesa,&*pocoes,&*moedas, &dificuldade,&vidaplayer, &*vidalimite);
            }
            else
            {
                system("cls");
                printf("\nBoa! É isso ai voce acabou ele");
                int moedas_adic = (VetorDificuldade[nro_aleatorio].hpMonstro)/2;
                *moedas = *moedas + floor(moedas_adic);
                printf("\nCom isso voce rebece mais %d, moedas totalizando %d moedas", moedas_adic, *moedas);
                *dificuldade = *dificuldade+1;
                Sleep(2000);
                ARSENAL_REAL(&*ataque,&*defesa,&*pocoes,&*moedas, &*dificuldade, &*vidaplayer, &*vidalimite);
            }
        }
    }

}
int main(/*tMonsterConfig M*/)
{
    setlocale(LC_ALL, "portuguese");

    while(menu())
    {
        system("cls");
    }
    return 0;
}

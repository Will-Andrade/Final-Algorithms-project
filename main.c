    /*Hospital internment project
     * Created by Willian Bonni dos Santos Andrade
     * Presented as the final project in the Algorithms 2 class
     * IFMT - Bachelor's degree in Computer Engineering 06/14/2019*/

    #include <stdio.h>
    #include <string.h>

    int medico1;
    int medico2;
    int medico3;

    int sala1;
    int sala2;
    int sala3;

    struct individuo {

        char nome[30];
        int idade;
        int dia_de_internacao;

    } pac[3];

    void cadastro_paciente () {  //Function for patient registration

        printf("\a\a \tDigite as informações para realizar a internação! \a\a\n");
        for (int i = 0; i < 3; i++) {
            printf(" \n Informe seu nome. \n ");
            scanf("%s", &pac[i].nome);
            printf(" Informe sua idade. \n ");
            scanf("%d", &pac[i].idade);
            printf(" Informe o dia de internação. \n ");
            scanf("%d", &pac[i].dia_de_internacao);
        }
    }

    void escolha_de_cirurgia () {  //Function to register the patient's main problem and lead him into surgery
        int opc;
        medico1 = medico2 = medico3 = sala1 = sala2 = sala3 = 0;
        for (int i = 0; i < 3; i++) {
            printf("\tInforme o motivo de ter sido internado\n");
            printf("\t1. Problemas no tórax\n \t2. Problemas no coração\n \t3. Traumatismo\n");
            scanf("%d", &opc);
            printf("\n \a\a\a \tAs salas cirúrgicas para os problemas tratados são de 1 a 3 respectivamente! \a\a\a \n");
            switch (opc) {
                case 1:
                    printf("\a\a \tO paciente precisa realizar uma cirurgia torácica imediatamente! \a\a\n");
                    if (medico1 == 0 && sala1 == 0) {
                        printf("Sala cirúrgica e médico responsável pronto! Cirurgia pode começar!");
                        medico1 += 1;
                        sala1 += 1;
                    } else if (medico1 == 1 && sala1 == 1) {
                        printf("Sala ocupada e médico responsável em operação! Cirurgia não pode ser realizada.");
                        medico1 -= 1;
                        sala1 -= 1;
                    }
                    break;

                case 2:
                    printf("\a\a \t O paciente precisa realizar uma cirurgia cardiovascular imediatamente! \a\a\n");
                    if (medico2 == 0 && sala2 == 0) {
                        printf("Sala cirúrgica e médico responsável pronto! Cirurgia pode começar!");
                        medico2 += 1;
                        sala2 += 1;
                    } else if (medico2 == 1 && sala2 == 1) {
                        printf("Sala ocupada e médico responsável em operação! Cirurgia não pode ser realizada.");
                        medico2 -= 1;
                        sala2 -= 1;
                    }
                    break;

                case 3:
                    printf("\a\a \tO paciente sofreu traumatismo e precisa ir para a sala de cirurgia imediatamente! \a\a\n");
                    if (medico3 == 0 && sala3 == 0) {
                        printf("Sala cirúrgica e médico responsável pronto! Cirurgia pode começar!");
                        medico3 += 1;
                        sala3 += 1;
                    } else if (medico3 == 1 && sala3 == 1) {
                        printf("Sala ocupada e médico responsável em operação! Cirurgia não pode ser realizada.");
                        medico3 -= 1;
                        sala3 -= 1;
                    }
                    break;
            }
        }
    }

    void  relatorio (){  //Function to make a report file of the patient's registration

        int i;
        FILE *arq;
        arq = fopen("Relatorio de internacao.txt", "w");
        for(i = 0; i < 3; i++){
            FILE *arq;
            arq=fopen("Relatorio de internacao.txt", "w");
            for(i = 0; i < 3; i++){
                fprintf(arq,"Nome: %s \n Idade: %d \n Dia de internação: %d \n", pac[i].nome, pac[i].idade, pac[i].dia_de_internacao);

            }
        }
        fclose (arq);
    }

    void relatorio_cirurgico () {  //Another file function but this time for a postoperative report

        int i;
        FILE *arquivo;
        arquivo = fopen ("Relatorio pos operatorio.txt", "w");
        for (i = 0; i < 3; i++) {
            FILE *arquivo;
            arquivo=fopen ("Relatorio pos operatorio.txt", "w");
            for (i = 0; i < 3; i++) {
                fprintf (arquivo, " O paciente %s \n Idade %d \n Internado no dia: %d \n obteve uma cirurgia de sucesso!\n", pac[i].nome, pac[i].idade, pac[i].dia_de_internacao);
            }
        }
        fclose (arquivo);
    }

    int main () {  //Main function with a menu of options for the user to choose from.

        int escolha;

        do {
            printf("\n\a\a \tEscolha sua opção! \a\a\n");
            printf(" 1. Cadastro de paciente\n 2. Escolha de cirurgia\n 3. Relatório\n 4. Relatório cirúrgico\n 5. Sair\n");
            scanf("%d", &escolha);
            switch (escolha) {
                case 1:  //Calls the registration function
                    cadastro_paciente ();
                    printf ("Se deseja imprimir um relatório deste paciente, aperte '3' a seguir!\n");
                    break;

                case 2:  //Calls the problem/surgery choice function
                    escolha_de_cirurgia ();
                    printf ("Se deseja imprimir um relatório pós operatório, aperte '4' a seguir!\n");
                    break;

                 case 3:  //Registration report
                     relatorio ();
                     break;

                case 4:  //Postoperative report
                    relatorio_cirurgico ();
                    break;

                default:
                    break;
            }
        } while (escolha != 5);
        return 0;
    }
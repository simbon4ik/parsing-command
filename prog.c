#include <stdio.h>
#include <getopt.h>

int main(int argc, char* argv[]){
    struct option elbrus_options[] = {
    {"elbrus1c+", no_argument, NULL,'1'}, {"elbrus=2c+", no_argument, NULL, '2'}, {"elbrus=2c3", no_argument, NULL, '3'}, {"elbrus=4c", no_argument, NULL,
    '4'}, {"elbrus=8c", no_argument, NULL, '8'}, {"elbrus=16c", no_argument, NULL, '6'}, {0, 0, 0, 0}
    };

    int opt = getopt_long(argc, argv, "mcst", elbrus_options, NULL);
    if (opt == -1){
        printf("Options are incorrect.");   //Обработка неккоректного случая
        return 0;
    } 
    
    printf("Options are correct: ");
    do{
        switch(opt){
            case 'm':
                printf("m");
                break;
            case 'c':
                printf("c");
                break;
            case 's':
                printf("s");
                break;
            case 't':
                printf("t");
                break;
            case '1':
                printf("elbrus=1c+");
                break;
            case '2':
                printf("elbrus=2c+");
                break;
            case '3':
                printf("elbrus=2c3");
                break;
            case '4':
                printf("elbrus=4c");
                break;
            case '6':
                printf("elbrus=8c");
                break;
            case '8':
                printf("elbrus=16c");
                break;
            default:
                break;
        }
        printf(", ");
    }while ( (opt = getopt_long(argc, argv, "mcst", elbrus_options, NULL) ) != -1);
    
    if (optind < argc){
        printf("non options: ");
        while (optind < argc){
            if (optind != argc - 1){
                 printf("%s, ", argv[optind++]);
            }else printf("%s\n", argv[optind++]);
        }
    }
    else printf("non options: \"nothing\" \n");
    return 0;
}

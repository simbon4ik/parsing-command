#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc == 1){      //Обработка запуска без аргументов
            printf("hint: %s <filename>\n", argv[0]);
            return -1;
    }
    opterr = 0;         //Убираем вывод об ошибке самого getopt
    struct option elbrus_options[] = {
    {"elbrus", required_argument, NULL,'e'}, {0, 0, 0, 0}       //Вводим длинный (--) аргумент elbrus
    };
    const char* ARGUMENTS[] = {"1c+", "2c+", "2c3", "4c", "8c", "16c"}; //Доступные значения аргументов для elbrus a
    int opt = getopt_long(argc, argv, "mcst", elbrus_options, NULL);    //Получение первого флага
   
    printf("Options are correct: ");    //Вывод о том, что опция корректна
    do{
        switch(opt){
            case 'm':
                printf("m");    //Вывод опции "m"
                break;
            case 'c':
                printf("c");    //"c"
                break;
            case 's':
                printf("s");    //"s"
                break;
            case 't':
                printf("t");    //"t"
                break;
            case 'e':           //Случай, когда elbrus, потому что мы его обозначили 'e'
                int flag_good_arg = 0;      //Флаг проверки на хороший аргумент
                size_t cnt_arguments = sizeof(ARGUMENTS) / sizeof(ARGUMENTS[0]);    //Количество аргументов, подходящих эльбрусу
                for (int i = 0; i < cnt_arguments; ++i){
                   if (strcmp(ARGUMENTS[i], optarg) == 0){      //Нашли нужный аргумент в списке доступных
                    printf("elbrus=%s", optarg);
                    flag_good_arg = 1;      //Все окей!)
                   }
                }
                if (flag_good_arg == 0){
                    printf("Argument is incorrect");   //Обработка неккоректного аргумента
                    return 1;
                }
                break;
            case '?':
                printf("\rOptions are incorrect. Incorrect option is: -%c\n", optopt);   //Доп. задание (вывод некорректной опции, в optopt записывает getopt при некорректной опции, а 
                // \r возвращает в начало строки вывода)
                return 2;
            default:
                printf("\rOptions are incorrect.\n");   //Не повезло с командой (нет аргументов вообще)
                return 3;
                break;
        }
        printf(", ");   //Для красивого вывода
    }while ( (opt = getopt_long(argc, argv, "mcst", elbrus_options, NULL) ) != -1);     //Идем до конца по аргументам
    
    if (optind < argc){     //Пишем остальные строки не-опции
        printf("non options: ");
        while (optind < argc){
            if (optind != argc - 1){
                 printf("%s, ", argv[optind++]);
            }else printf("%s\n", argv[optind++]);       //На последней красивый вывод
        }
    }
    else printf("non options: \"nothing\" \n");         //Если у нас только опции
    return 0;
}

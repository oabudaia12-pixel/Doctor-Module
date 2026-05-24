#include <stdio.h>
#include <string.h>

struct Schedule{
    char doctor[50];
    char day[20];
    char time[20];
};

struct Diagnostic{
    char patient[50];
    char diagnosis[100];
};

int main() {

    char user[20], pass[20];
    struct Schedule s[10];
    struct Diagnostic d[10];

    int scount = 0, dcount = 0;
    int choice, i;
    char search[50];

    printf("===== Doctor Login =====\n");
    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    if(strcmp(user,"doctor") != 0 || strcmp(pass,"1234") != 0){
        printf("Invalid Login!\n");
        return 0;
    }

    do{
        printf("\n===== Doctor Menu =====\n");
        printf("1. Add Schedule\n");
        printf("2. View Schedule\n");
        printf("3. Add Diagnostic\n");
        printf("4. View Diagnostic Report\n");
        printf("5. Search Patient Diagnostic\n");
        printf("0. Logout\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

        case 1:
            printf("Doctor Name: ");
            scanf("%s", s[scount].doctor);

            printf("Day: ");
            scanf("%s", s[scount].day);

            printf("Time: ");
            scanf("%s", s[scount].time);

            scount++;
            printf("Schedule Added!\n");
            break;

        case 2:
            printf("\n--- Doctor Schedule ---\n");
            for(i=0;i<scount;i++){
                printf("%s | %s | %s\n",
                s[i].doctor,s[i].day,s[i].time);
            }
            break;

        case 3:
            printf("Patient Name: ");
            scanf("%s", d[dcount].patient);

            printf("Diagnosis: ");
            scanf(" %[^\n]", d[dcount].diagnosis);

            dcount++;
            printf("Diagnostic Added!\n");
            break;

        case 4:
            printf("\n--- Diagnostic Report ---\n");
            for(i=0;i<dcount;i++){
                printf("%s : %s\n",
                d[i].patient,d[i].diagnosis);
            }
            break;

        case 5:
            printf("Enter Patient Name: ");
            scanf("%s", search);

            for(i=0;i<dcount;i++){
                if(strcmp(search,d[i].patient)==0){
                    printf("%s : %s\n",
                    d[i].patient,d[i].diagnosis);
                }
            }
            break;

        case 0:
            printf("Logout Successful!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    }while(choice != 0);

    return 0;
}

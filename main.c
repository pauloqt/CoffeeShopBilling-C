#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int DisplayMenu();
int selectOrder(char order, char size, int quantity);
int* getOrder(char* order, char* size, int* quantity);

struct menu{

    char name[20];
    double grande;
    double venti;

};



int main(){
    char name[50];
    char order, size;
    int quantity;
    double subtotal, discount, amntReceived, change;

    printf("\n\t       WELCOME TO SANDBOX COFFEE SHOP\n");
    DisplayMenu();
    printf("\tPress enter to order. ");
    getch();
    printf("\n---------------------------------------------------------\n");
    printf("\t\tSAND BOX COFFEE SHOP\n");
    printf("\t\t   ORDER RECEIPT\n");
    printf("\n\tNAME:                     ");
    fgets(name, 50, stdin);
    getOrder(&order, &size, &quantity);
    subtotal=selectOrder(order, size, quantity);
    printf("\n\t%DISCOUNT:              ");
    scanf("%lf", &discount);
    discount*=subtotal;
    printf("\tTOTAL DISCOUNT:         %.2lf\n", discount);
    subtotal-=discount;
    printf("\tGRAND TOTAL:            %.2lf\n", subtotal);
    printf("\n\tCASH:                   ");
    scanf("%lf", &amntReceived);
    change=amntReceived-subtotal;
    printf("\tCHANGE:                 %.2lf\n", change);
    printf("\n\tSAIL OFF WITHOUT A MAP! HAVE A GOOD DAY!");


}

int DisplayMenu(){

    printf(R"EOF(

                        MENU

        COFFEE                 (G) GRANDE  (V) VENTI
        (A) DRIP COFFEE             100        150
        (B) ESPRESSO                150        200
        (C) AMERICANO               150        200
        (D) MACCHIATO               175        225
        (E) CAPPUCCINO              200        250
        (F) LATTE                   200        250
        (G) COLD BREW               200        250

        OTHER DRINKS
        (H) ICED TEA                100        150
        (I) SODA                    100        150
        (J) APPLE JUICE             150        200

)EOF");

}

int selectOrder(char order, char size, int quantity){
double price, subtotal;
char display[20], sizeName[10];
    struct menu A;
    strcpy(A.name, "DRIP COFFEE");
    A.grande= 100;
    A.venti= 150;
    struct menu B;
    strcpy(B.name, "ESPRESSO");
    B.grande= 150;
    B.venti= 200;
    struct menu C;
    strcpy(C.name, "AMERICANO");
    C.grande= 150;
    C.venti= 200;
    struct menu D;
    strcpy(D.name, "MACCHIATO");
    D.grande= 175;
    D.venti= 225;
    struct menu E;
    strcpy(E.name, "CAPPUCCINO");
    E.grande= 200;
    E.venti= 250;
    struct menu F;
    strcpy(F.name, "LATTE");
    F.grande= 200;
    F.venti= 250;
    struct menu G;
    strcpy(G.name, "COLD BREW");
    G.grande= 200;
    G.venti= 250;
    struct menu H;
    strcpy(H.name, "ICED TEA");
    H.grande= 100;
    H.venti= 150;
    struct menu I;
    strcpy(I.name, "SODA");
    I.grande= 100;
    I.venti= 150;
    struct menu J;
    strcpy(J.name, "APPLE JUICE");
    J.grande= 150;
    J.venti= 200;

    printf("\n---------------------------------------------------------\n");
    size=toupper(size);
    switch (toupper(order)){
    case 'A': strcpy(display, A.name);
            if(size=='G'){price=A.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=A.venti; strcpy(sizeName, "VENTI");} break;
    case 'B': strcpy(display, B.name);
            if(size=='G'){price=B.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=B.venti; strcpy(sizeName, "VENTI");} break;
    case 'C': strcpy(display, C.name);
            if(size=='G'){price=C.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=C.venti; strcpy(sizeName, "VENTI");} break;
    case 'D': strcpy(display, D.name);
            if(size=='G'){price=D.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=D.venti; strcpy(sizeName, "VENTI");} break;
    case 'E': strcpy(display, E.name);
            if(size=='G'){price=E.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=E.venti; strcpy(sizeName, "VENTI");} break;
    case 'F': strcpy(display, F.name);
            if(size=='G'){price=F.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=F.venti; strcpy(sizeName, "VENTI");} break;
    case 'G': strcpy(display, G.name);
            if(size=='G'){price=G.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=G.venti; strcpy(sizeName, "VENTI");} break;
    case 'H': strcpy(display, H.name);
            if(size=='G'){price=H.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=H.venti; strcpy(sizeName, "VENTI");} break;
    case 'I': strcpy(display, I.name);
            if(size=='G'){price=I.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=I.venti; strcpy(sizeName, "VENTI");} break;
    case 'J': strcpy(display, J.name);
            if(size=='G'){price=J.grande;
            strcpy(sizeName, "GRANDE");}
            else{price=J.venti; strcpy(sizeName, "VENTI");} break;
    }
    fflush stdin;
    subtotal= price * quantity;
    printf("\tORDER:                  %d %s %s", quantity, sizeName, display);
    printf("\n\t                        %d x %.2lf", quantity, price);
    printf("\n\tSUBTOTAL:               %.2lf\t", subtotal);

    return subtotal;

}

int* getOrder(char* order, char* size, int* quantity){

    printf("\tLETTER OF ORDER (A-J):    ");
    scanf("%c", order);
    printf("\tSIZE (G OR V):            ");
    fflush stdin;
    scanf("%c", size);
    printf("\tQUANTITY:                 ");
    scanf("%d", quantity);

    return *order, *size, *quantity;

}



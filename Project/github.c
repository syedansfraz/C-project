
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#define MAXPRODUCTS 10  // max number of products
 
// define clear screen depending on the operating system
#ifdef unix
    #define clearscreen system("clear")
#endif
#ifdef _WIN32
    #define clearscreen system("cls")
#endif 
#ifdef _WIN64
    #define clearscreen system("cls")
#endif 

const char *MAINMENU = 
    "MAIN MENU\n"
    "---------\n\n"
    "1) List Product Codes\n"
    "2) View Product Volume\n"
    "3) Add Product\n"
    "4) Change Product Volume\n"
    "5) Delete Product\n"
    "6) Exit\n\n"
    "Enter choice (1-6): ";

const char *LISTPRODUCTS = 
    "LIST PRODUCT CODES\n"
    "------------------\n";

const char *PRODUCTVOLUME = 
    "PRODUCT VOLUME\n"
    "--------------\n";

const char *NEWPRODUCT = 
    "NEW PRODUCT\n"
    "-----------\n";

const char *CHANGEPRODUCTVOLUME = 
    "CHANGE PRODUCT VOLUME\n"
    "---------------------\n";

const char *DELETEPRODUCT = 
    "DELETE PRODUCT\n"
    "--------------\n";

const char *PRODUCTFILENAME = "stock.dat";






typedef struct {
    int code;               // κωδικός
    char description[100];  // περιγραφή
    int volume;             // ποσότητα αποθήκης
} product;  // δομή εγγραφής προιόντος

typedef struct _productNode *productNode;

struct _productNode {
    product data;
    productNode next;
};

typedef struct _list *list;

struct _list {
    productNode head;
    int size;
} ;

/* FUNCTION PROTOTYPES for main() */
list list_create();
productNode list_newnode(product);
void list_freenode(productNode);
productNode list_first(list);
productNode list_next(productNode);
product list_data(productNode);
int list_empty(list);
int list_size(list);
void list_insertfirst(list, productNode);
productNode list_deletefirst(list);
void list_insertafter(list, productNode, productNode);
void list_destroy(list);

list readlistfromfile(FILE*);
void listproductcodes(list);
int codeexists(list, int);
productNode list_getnodebycode(list);
productNode list_deletenode(list, productNode);
int writelisttofile(list);
void pressentertocontinue();
void addproducttolist(list l);

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *fp;
    list productlist;   // λίστα προιόντων
    int choice, code, volume;
    product p;
    productNode pn;
    
    /* Έλεγχος ύπαρξης αρχείου */ 
    if ( (fp = fopen(PRODUCTFILENAME, "r")) == NULL) { // δεν υπάρχει
        // δημιουργία λίστας προιόντων
        productlist = list_create();
    } else {    // υπάρχει 
        // διάβασμα λίστας προιόντων από αρχείο
        productlist = readlistfromfile(fp);
        // κλείσιμο αρχείου
        fclose(fp);
    }
        
    do {
        // clear screen
        clearscreen;
        // show menu
        printf("%s", MAINMENU);
        // get user choice
        scanf("%d", &choice);
        // take choice action
        switch(choice) {
            case 1: // list product codes
                // clear screen
                clearscreen;
                printf("%s", LISTPRODUCTS);
                listproductcodes(productlist);
                pressentertocontinue();
                break;
            case 2: // view product volume
                // clear screen
                clearscreen;
                printf("%s", PRODUCTVOLUME);
                pn = list_getnodebycode(productlist);
                printf("\nVolume of product %d is %d\n\n", pn->data.code, pn->data.volume);
                pressentertocontinue();
                break;
            case 3: // add product
                // clear screen
                clearscreen;
                printf("%s", NEWPRODUCT);
                addproducttolist(productlist);
                pressentertocontinue();
                break;
            case 4: // change product volume
                // clear screen
                clearscreen;
                printf("%s", CHANGEPRODUCTVOLUME);
                pn = list_getnodebycode(productlist);
                // prompt for volume until volume >= 0
                do {
                    printf("New volume : "); scanf("%d", &(pn->data.volume));
                    if (pn->data.volume < 0)
                        printf("\tVolume must be > 0!\n");
                } while(pn->data.volume < 0);
                pressentertocontinue();
                break;		
            case 5: // delete product
                // clear screen
                clearscreen;
                printf("%s", DELETEPRODUCT);
                list_freenode(list_deletenode(productlist, list_getnodebycode(productlist)));
                pressentertocontinue();
                break;		
            case 6: // exit
                printf("\nEXIT APP");
                writelisttofile(productlist);
                list_destroy(productlist);		                
        }
        
    } while( choice != 6 );
    
    return (EXIT_SUCCESS);
}

// Create list
list list_create() {
    list l = (list)malloc(sizeof(struct _list));
    assert(l);
    l->head = NULL;
    l->size = 0;
    return l;
}

// create new product node
productNode list_newnode(product p) {
    productNode pn = (productNode)malloc(sizeof(struct _productNode));
    assert(pn);
    pn->data = p;
    pn->next = NULL;
    return pn;
}

// free product node memory
void list_freenode(productNode pn) {
    assert(pn);
    free(pn);
}

// list's first product node
productNode list_first(list l) {
    assert(l);
    return l->head;
}

// product node after the given
productNode list_next(productNode pn) {
    assert(pn);
    return pn->next;
}

// product from product node
product list_data(productNode pn) {
    assert(pn);
    return pn->data;
}

// check if list of products is empty
int list_empty(list l) {
    assert(l);
    return (l->head == NULL);
}

// get product list size
int list_size(list l) {
    assert(l);
    return l->size;
}

// insert productNode in list's 1st position
void list_insertfirst(list l, productNode pn) {
    assert(l && pn);
    pn->next = l->head;
    l->head = pn;
    l->size++;
}

// delete 1st product node from list
productNode list_deletefirst(list l) {
    productNode ret;
    assert(l && l->head);
    ret = l->head;
    l->head = ret->next;
    l->size--;
    ret->next = NULL;
    return ret;
}

// insert product node after node
void list_insertafter(list l, productNode after, productNode pn) {
    assert(l && after && pn);
    pn->next = after->next;
    after->next = pn;
    l->size++;
}

// delete a specific product node
productNode list_deletenode(list l, productNode pn) {
    productNode p;
    assert(l && pn);
    if (pn == list_first(l))
        return list_deletefirst(l);
    for(p = list_first(l); p->next != pn; p = list_next(p));
    p->next = pn->next;
    pn->next = NULL;
    l->size--;
    return pn;
}

/* destroy list and free memory */
void list_destroy(list l) {
    while (!list_empty(l))
        list_freenode(list_deletefirst(l));
    free(l);
}

/* list product codes */
void listproductcodes(list l) {
    productNode pn;
    product p;
    // print labels
    printf("\n"
           "Code\tDescription\n"
           "----\t-----------\n");
    // print code and description for all list products
    for(pn = list_first(l); pn != NULL; pn = list_next(pn)) {
        p = list_data(pn);
        printf("%d\t%s\n", p.code, p.description);
    }
    // print an extra line
    printf("\n");
}

/* read all product data from file and create list */
list readlistfromfile(FILE *fp) {
    int n;
    // δημιουργία λίστας προιόντων
    list l = list_create();
    
    productNode pn;
    product p;
    // read all product records from file
    while((n = fread(&p, sizeof(product), 1, fp)) == 1)
         list_insertfirst(l, list_newnode(p));
    // check if there where any read errors
    if(n<0)
       fprintf(stderr, "File %s could not be entirely read!\n", PRODUCTFILENAME);
    // return list of products
    return l;
}


/* checks if code exists in list */
int codeexists(list l, int code) {
    productNode pn;
    for(pn = list_first(l); pn != NULL; pn = list_next(pn))
        if (pn->data.code == code)
            return 1;
    return 0;
}

/* get product node with specific product code */
productNode list_getnodebycode(list l) {
    productNode p;
    int code;
    assert(l && l->head);
    do {// prompt for code
        printf("\nEnter product code : ");
        // read code
        scanf("%d", &code);
        // search list for product with code
        for(p = list_first(l); p != NULL; p = list_next(p))
            if (p->data.code == code)
                break;
        if (!p)
            printf("\tThis code does not exist!");
    } while (!p);
    return p;  
}

/* write all product data to file from list */
int writelisttofile(list l) {
    FILE *fp;
    productNode pn;
    product p;
    assert(l);
    // open file for write with override
    if ((fp = fopen(PRODUCTFILENAME, "w+")) == NULL) {
        fprintf(stderr, "File %s could not be opened!\n", PRODUCTFILENAME);
        exit(0);
    }
    // write all product records to file
    for(pn = list_first(l); pn != NULL; pn = list_next(pn)) {
        // get product data from product node
        p = list_data(pn);
        // write product data to fle
        if (fwrite(&p, sizeof(product), 1, fp) != 1) {
            fprintf(stderr, "Could not save data for product %d!\n", p.code);
            fclose(fp);
            exit(0);
        }
    }
    // close file
    fclose(fp);
    exit(1);
}

void pressentertocontinue() {
    printf("Press any key to continue");
    getchar();
    getchar();
}

void addproducttolist(list l) {
    product p;
    // prompt for code until code exists
    do {
        printf("\nCode : "); scanf("%d", &p.code);
        if (codeexists(l, p.code))
            printf("\tThis code exists!");
    } while (codeexists(l, p.code));
    // prompt for description
    printf("Description : "); 
    int i = 0, c;
    c = getchar();
    while ((c = getchar()) != '\n') {
        p.description[i++] = c;
    }
    // prompt for volume until volume >= 0
    do {
        printf("Volume : "); scanf("%d", &p.volume);
        if (p.volume < 0)
            printf("\tVolume must be > 0!\n");
    } while(p.volume < 0);
    // add product in the first node of list
    list_insertfirst(l, list_newnode(p));
}
 printf("Which id number you want to change");
        scanf("%d",&modify);
        printf("What do you want to change\n1.Price\n2.Expiry date\n3.");
        scanf("%d",&wmodify);
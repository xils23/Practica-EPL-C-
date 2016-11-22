// Conversio de enter positiu de notació decimal a binari i octal

#include <stdio.h>


#define M 20        // Maxim 20 digits

// Prototipus accions i funcions auxiliars
void transformar(int v, char d[ ],int &l, int base,  bool &error);
void mostrar(int v, char d[ ],int l, int base, bool error);

int main(){
    
    int v;              // valor a transformar
    
    char d[M];          // contindra els digits de la transformacio

    int l;              // nombre de digits de la transformacio
    
    bool error;         // Validar que la transformacio requereix 20 digits com a maxim
    
    do{
        printf("Introduir un valor enter POSITIU en notació decimal. Mida maxima de la transformació %d \n", M);
        scanf("%d",&v);
    } while (v<0);
    
    
    // transformacio en binari
    transformar(v, d, l, 2, error);
	printf("Transformació en binari:\n");
    mostrar(v, d, l, 2, error);
    
    
    // transformacio en octal
    transformar(v, d, l, 8, error);
	printf("Transformació en octal:\n");	
    mostrar(v, d, l, 8, error);
}

// Accions auxiliars

void transformar(int v, char d[ ],int &l, int base, bool &error){
    int c, r;
    
    l=0;
    c=v/base;
    r=v%base;
    
    while(c>0 && l<M){
        d[l]='0'+r;
        l=l+1;
        v=c;
        c=v/base;
        r=v%base;
    }
    if (l<M) {
        d[l]='0'+r;
        l=l+1;
        error=false;
    } else {
        error=true;
    }
    
}

void mostrar(int v, char d[ ],int l, int base, bool error){
    int i;
    
    if (error) {
        printf("ERROR: La transformació de %d a base %d requereix més de %d dígits \n",v, base, M);
    } else {
        printf("Transformació del nombre %d: \t", v);
        
        for (i=l-1; i>=0; i--){
            putchar(d[i]);
        }
        putchar('\n');
    }
}








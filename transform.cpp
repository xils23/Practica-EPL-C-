// Conversio de enter positiu de notació decimal a binari i octal

#include <stdio.h>
#include <stdlib.h>

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)


       // Maxim 20 digits

// Prototipus accions i funcions auxiliars
void transformar(int v, char d[ ],int &l, int base,  bool &error);
void mostrar(int v, char d[ ],int l, int base, bool error);

int main(){
  setlocale (LC_ALL, "");
 	bindtextdomain ("transform", "/usr/share/locale/");
  textdomain ("transform");

    int v;              // valor a transformar

    char d[20];          // contindra els digits de la transformacio

    int l;              // nombre de digits de la transformacio

    bool error;         // Validar que la transformacio requereix 20 digits com a maxim

    do{
        printf(_("Introduir un valor enter POSITIU en notació decimal. Mida maxima de la transformació 20 \n"));
        scanf("%d",&v);
    } while (v<0);


    // transformacio en binari
    transformar(v, d, l, 2, error);
	printf(_("Transformació en binari:\n"));
    mostrar(v, d, l, 2, error);


    // transformacio en octal
    transformar(v, d, l, 8, error);
	printf(_("Transformació en octal:\n"));
    mostrar(v, d, l, 8, error);
}

// Accions auxiliars

void transformar(int v, char d[ ],int &l, int base, bool &error){
    int c, r;

    l=0;
    c=v/base;
    r=v%base;

    while(c>0 && l<20){
        d[l]='0'+r;
        l=l+1;
        v=c;
        c=v/base;
        r=v%base;
    }
    if (l<20) {
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
        printf(_("ERROR: La transformació de requereix més de 20 dígits \n"));
    } else {
        printf(_("Transformació del nombre: \t"));

        for (i=l-1; i>=0; i--){
            putchar(d[i]);
        }
        putchar('\n');
    }
}

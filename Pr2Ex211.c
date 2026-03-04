/*
Marco Rondón, 1794984
Mario Roda, 1792216
*/
# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int niu;
    float notes[5];
} Alu;

float mitjana(float [],int );

int main(){
    FILE *dades;
    int n, i, j, ll, num_lin = 0, lrg = 0;
        
    Alu *alumnes;
    
    // Obrim el fitxer Llista.txt
    dades=fopen("./Llista.txt","r");
    if(dades==NULL){
        printf("\nNo s'ha accedit al fitxer de dades\n");
        return 1;
    }
    // Contem el nombre de línies
    while((ll = fgetc(dades)) != EOF){
        if (ll == '\n'){
            num_lin++;
        }
    }
    printf("\nHi ha %d linies al document.\n",num_lin);
    rewind(dades);
    // Reservem memoria per l'estructura Alu tenint en compte el nombre d'alumnes
    if ((alumnes = (Alu *)malloc(sizeof(Alu)*num_lin)) == NULL){
        printf("Error: no hi ha espai suficient en la memoria.");
        return 1;
    }
    // Llegim el document i guardem les dades en les estructures Alu.
    while(!(fscanf(dades,"%i;",&n)==EOF)){
        alumnes[lrg].niu=n;
        for(i=0;i<4;i++){
            fscanf(dades,"%f",&alumnes[lrg].notes[i]);
            fgetc(dades);//llegeix i descarta els ; i el \n
        }
        alumnes[lrg].notes[4]=mitjana(alumnes[lrg].notes,4);
        lrg++;
    }
    fclose(dades);
    // Imprimim les dades
    for(j=0;j<lrg;j++){
        printf("%d | ",alumnes[j].niu);
        for(i=0;i<4;i++){
            printf("%5.1f",alumnes[j].notes[i]);
        }
        printf(" |%6.2f",alumnes[j].notes[4]);
        printf("\n");
    }
    printf("\nS'ha llegit informacio de %d linies.\n\n",lrg);
    

    free(alumnes);
    return 0;
}

float mitjana(float dades[],int n){
    int i;
    float m=0.;
    for(i=0;i<n;i++)
    {
        m+=dades[i];
    }
    return m/n;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct nod
{
    char nume[20];      //vectorul de structuri
    int x,y;
};
#define IN 99999
typedef struct nod nod;
void main(int argc,char *argv[])
{
    FILE *coordonate,*coord_finale,*avarii,*rezultat;
    int x1,y1,x2,y2,x3,y3,r1,r2,r3,A,B,C,D,E,F;
    int nr_loc,i,j,k,nod_dest,N,co;
    int **cost;
    char satelit[15],avarie1[20],avarie2[20];
    if((coordonate=fopen(argv[1],"r"))==NULL);
    if((coord_finale=fopen(argv[4],"w"))==NULL);
    if((avarii=fopen(argv[2],"r"))==NULL);          //deschiderea fisierelor
    if((rezultat=fopen(argv[5],"w"))==NULL);
    fscanf(coordonate,"%d",&nr_loc);
    nod *v;
	cost=(int**)malloc(nr_loc*sizeof(int*));
  	for(i=1;i<=nr_loc;i++)
        cost[i]=(int*)malloc(nr_loc*sizeof(int));   //alocarea dinamica a matricei
	v=(nod*)malloc(nr_loc*sizeof(nod));
	for(k=1;k<=nr_loc;k++)
    {
        fscanf(coordonate,"%s",v[k].nume);
        fscanf(coordonate,"%s",satelit);
        fscanf(coordonate,"%d",&x1);
        fscanf(coordonate,"%d",&y1);
        fscanf(coordonate,"%d",&r1);
        fscanf(coordonate,"%s",satelit);
        fscanf(coordonate,"%d",&x2);
        fscanf(coordonate,"%d",&y2);            //citirea de coordonate ale centrului si raza, pentru cele 3 cercuri
        fscanf(coordonate,"%d",&r2);
        fscanf(coordonate,"%s",satelit);
        fscanf(coordonate,"%d",&x3);
        fscanf(coordonate,"%d",&y3);
        fscanf(coordonate,"%d",&r3);
        C=(r1*r1-r2*r2+x2*x2-x1*x1+y2*y2-y1*y1);
        F=(r2*r2-r3*r3+x3*x3-x2*x2+y3*y3-y2*y2);
        A=(-2)*x1+2*x2;
        D=(-2)*x2+2*x3;
        B=(-2)*y1+2*y2;                                 //rezolvarea sistemului
        E=(-2)*y2+2*y3;
        v[k].x=(C*E-F*B)/(A*E-D*B);
        v[k].y=(C*D-F*A)/(B*D-E*A);
    }
    fclose(coordonate);
    for(i=1;i<=nr_loc;i++)
        fprintf(coord_finale,"%d %d\n",v[i].x,v[i].y);      //scrierea in fisierul de iesire a coordonatelor
    fclose(coord_finale);
    for(i=1;i<=nr_loc;i++)
        for(j=1;j<=nr_loc;j++)
            if(i==j) cost[i][j]=0;                          //calcularea costurilor si introducerea lor in matrice
                else
                    cost[i][j]=sqrt((v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y));
    while((fscanf(avarii,"%s",avarie1)==1)&&(fscanf(avarii,"%s",avarie2)==1))
    {
        for(i=1;i<=nr_loc;i++)
            if (strcmp(avarie1,v[i].nume)==0)
                break;
        for(j=1;j<=nr_loc;j++)
            if(strcmp(avarie2,v[j].nume)==0)    //scanarea de avarii si modificarea costurilor respective in matrice
                break;
        cost[i][j]=0;
        cost[j][i]=0;
    }
    fclose(avarii);
    for(i=1;i<=nr_loc;i++)
        if(strcmp(argv[3],v[i].nume)==0)    //gasirea nodului in care trebuie sa ajungem
            nod_dest=i;
    for(i=1;i<=nr_loc;i++)
        for(j=1;j<=nr_loc;j++)
            if(cost[i][j]==0)
                cost[i][j]=IN;              //elementele 0 din matrice le am facut IN
    for(k=1;k<=nr_loc;k++)
        for(i=1;i<=nr_loc;i++)
            for(j=1;j<=nr_loc;j++)
                if((cost[i][k] + cost[k][j])<cost[i][j])
                    cost[i][j]=(cost[i][k] + cost[k][j]);   //algoritmul Floyd-Warshall
    fprintf(rezultat,"%d",cost[1][nod_dest]);       //afisarea rezultatului
    fclose(rezultat);
    free(cost);
    free(v);
}

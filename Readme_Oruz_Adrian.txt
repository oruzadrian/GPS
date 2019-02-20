	M-am folosit de un vector de structuri pentru a memora numele locatiei citite si ulterior a coordonatelor sale (pentru fiecare locatie in parte).
	Coordonatele le am calculat rezolvand sistemul dat folosint metoda reducerii.
	A fost nevoie sa scanez si satelitul cu toate ca nu mi-a fost folositor si de aceea l am suprascris in stringul satelit.
	In matricea (alocata dinamic) cost am bagat pe diagonala principala 0, iar in rest costul dintre nodurile respective(i,j).M-am folosit de formula distantei (a fost nevoie sa includ math.h si sa pun -lm in makefile).
	Unde am avut avarii am facut nodurile respective 0.
	Am comparat destinatia data de checker cu numele din vectorul de structuri ca sa aflu nodul destinatie.
	Am implementat algoritmul Floyd-Warshall (m-am folosit de o valoare foarte mare IN) si am obtinut pe prima linie costul minim de la nodul 1 catre toate celelalte noduri.

								Oruz Adrian 312AB
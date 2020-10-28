/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Calendrier
  Auteur.e.s  : Sarah Jallon, Davide Caracol Mendes
  Date        : 27/10/2020
  But         : le but du programme est d'afficher un calendrier d'une année précise
  					 entre 1900 et 2100. L'utilisateur choisi l'année qu'il veut afficher.
  					 A la fin du programme ce dernier peut choisir de recommencer l'opération
  					 autant de fois qu'il le souhaite.

  Remarque(s) : à compléter

  Compilateur : Mingw-w64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#define IGNORE_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define CLEAR_BUFFER  cin.clear()

enum class Mois {JANVIER, FEVRIER, MARS, AVRIL, MAI, JUIN ,JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE};


int main() {

 // ----------------------------------------------------------------------------------------------
 // constantes du programme
 const int  ANNEE_DEPART = 1900;
 const int  ANNEE_FIN    = 2100;
 const char TIRET        = '-';

 char recommencer;

 // ----------------------------------------------------------------------------------------------
 // Introduction du programme
 cout << "Ce programme vous affiche le calendrier de l'annee que vous desirez." << endl;

 // ----------------------------------------------------------------------------------------------
 // Entrée utilisateur et contrôles des valeurs et des types de valeurs.

 int  anneeChoisie;
 bool bonneAnnee;
do{
 do {
	cout << "Entrer une valeur [" << ANNEE_DEPART << TIRET << ANNEE_FIN << "] :";
	cin >> anneeChoisie;

	bonneAnnee = anneeChoisie > ANNEE_FIN || anneeChoisie < ANNEE_DEPART || cin.fail();
	if(bonneAnnee){
 	 cout << "/!\\ recommencer" << endl;
		CLEAR_BUFFER;
		IGNORE_BUFFER;
	}

 }  while (bonneAnnee);

 // ----------------------------------------------------------------------------------------------
 //Chercher si notre année est bissextile
	bool bissextile = false;

	if ((anneeChoisie%4 == 0 && anneeChoisie%100 != 0) || ( anneeChoisie%400 == 0)) {
		bissextile = true;
	}


 // ----------------------------------------------------------------------------------------------
 //Affichage les mois dans l'ordre

	unsigned jours;
 for (int i=1; i < 13; i++) {

	 switch (Mois(i - 1)) {
		 case Mois::JANVIER  : cout << "JANVIER " ;
		 							  jours = 31; break;
		 case Mois::FEVRIER  : if(bissextile) {
		 						      jours = 28;
		 				           } else {
		 	                     jours = 29;
		                       };
		                       cout << "FEVRIER ";
		                       break;
		 case Mois::MARS     : cout << "MARS "    ;
		 							  jours = 31; break;
		 case Mois::AVRIL    : cout << "AVRIL "   ;
		                       jours << 30; break;
		 case Mois::MAI      : cout << "MAI "     ;
		 							  jours = 31; break;
		 case Mois::JUIN     : cout << "JUIN "     ;
		                       jours = 30; break;
		 case Mois::JUILLET  : cout << "JUILLET " ;
		 							  jours = 31; break;
		 case Mois::AOUT     : cout << "AOUT "    ;
		 							  jours = 31; break;
		 case Mois::SEPTEMBRE: cout << "SEPTEMBRE ";
		                       jours = 30; break;
		 case Mois::OCTOBRE  : cout << "OCTOBRE " ;
		 							  jours = 31; break;
		 case Mois::NOVEMBRE : cout << "NOVEMBRE ";
		 	                    jours = 30; break;
		 case Mois::DECEMBRE : cout << "DECEMBRE ";
		 						     jours = 31; break;
	 }
	 //TODO chercher formule pour afficher nombre de jours sur une seule ligne
	 cout << anneeChoisie << endl;
	const int N_DEPART = 1;
	const int NB_COLONNES = 7;
	 unsigned n = N_DEPART, noColonne = 1;
	 while (n <= jours) {
		 cout << setw(2) << n; // affiche le nombre @SAR : Insérer une constante 2
		 if (noColonne == NB_COLONNES) {
			 cout << endl; // change de ligne
			 noColonne = 0;
		 } else {
			 if (n != jours) {
				 cout << " ";
			 }
		 }
		 noColonne++;
		 n++;
	 }
	 cout << endl << endl;


 }

 // ----------------------------------------------------------------------------------------------
 // fin de programme
	do {
		cout << "voulez-vous recommencer [O/N]";
		cin  >> recommencer;
	} while (recommencer != 'N' && recommencer != 'O');

	} while ( recommencer == 'O');
	IGNORE_BUFFER;
	return EXIT_SUCCESS;
}
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
using namespace std;

#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

int main() {

 // ----------------------------------------------------------------------------------------------
 // constantes du programme
 const int  ANNEE_DEPART = 1900;
 const int  ANNEE_FIN    = 2100;
 const char TIRET        = '-';

 // ----------------------------------------------------------------------------------------------
 // Introduction du programme
 cout << "Ce programme vous affiche le calendrier de l'annee que vous desirez." << endl;

 // ----------------------------------------------------------------------------------------------
 //

 int annee_choisie;
 cout << "Entrer une valeur [" << ANNEE_DEPART << TIRET << ANNEE_FIN << "] :" << endl;
 cin >> annee_choisie;
 while (annee_choisie > ANNEE_FIN || annee_choisie < ANNEE_DEPART || !cin) {
 	cin.clear();
 	CLEAR_BUFFER;

 	cout << "/!\\ recommencer" << endl;
 	cout << "Entrer une valeur [" << ANNEE_DEPART << TIRET << ANNEE_FIN << "] :";
 	cin >> annee_choisie;
 }
 cout << annee_choisie;

 return EXIT_SUCCESS;
}

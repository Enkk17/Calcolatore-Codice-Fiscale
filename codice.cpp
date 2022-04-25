#pragma warning(disable : 4996) //se non si usa visual studio eliminare 
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	char a_mesi[12] = {'A', 'B', 'C', 'D', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'T'};
	char vocale_cognome,vocale_nome;
	int len_cognome, len_nome,mese;
	ifstream File;
	string nome,cognome,anno,risultato,data, giorno,codice_comune,citta,database;

	bool femmina = false;
	cout << "PER UN CORRETTO FUNZIONAMENTO DEL PROGRAMMA SI PREGA DI SCRIVERE TUTTO IN MAIUSCOLO! "<<endl;
	system("pause");


	cout << "inserisci il tuo nome ";
	cin >> nome;
	cout << "inserisci il tuo cognome ";
	cin >> cognome;
	cout << "inserisci il giorno in cui sei nato ";
	cin >> giorno;
	cout << "inserisci il mese in cui sei nato ";
	cin >> mese;
	mese = mese-1;
	cout << "inserisci l'anno in cui sei nato ";
	cin >> anno;
	cout << "in che città sei nato? ";
	cin.ignore();
	getline(cin,citta);
	int verifica;
	cout << "Se sei maschio digita 0 altrimenti digita 1 ";
	cin >> verifica;
	if (verifica == 1)
	{
		femmina = true;
	}
	//rimuoviamo tutti i segni di puntaggiatura presenti nel cognome
	cognome.erase(remove_if(cognome.begin(), cognome.end(), ispunct), cognome.end());

	//prendiamo la lunghezza del nome e cognome
	len_nome = nome.size();
	len_cognome = cognome.size();

	//ciclo for per prendere le lettere del cognome
	for (int j = 0; j < len_cognome; j++)
	{
		if(cognome[j] == 'a' || cognome[j] == 'e' || cognome[j] == 'i' || cognome[j] == 'o' || cognome[j] == 'u' || cognome[j] == 'A' || cognome[j] == 'E' || cognome[j] == 'I' || cognome[j] == 'O' || cognome[j] == 'U')
		{
			vocale_cognome = cognome[j];
			cognome.erase(j, 1);
			len_cognome--;
			j--;
		}
	}

	//ciclo for per prendere le lettere del nome
	for (int j = 0; j < len_nome; j++)
	{
		if (nome[j] == 'a' || nome[j] == 'e' || nome[j] == 'i' || nome[j] == 'o' || nome[j] == 'u' || nome[j] == 'A' || nome[j] == 'E' || nome[j] == 'I' || nome[j] == 'O' || nome[j] == 'U' || nome[j] == ' ')
		{
			vocale_nome = nome[j];
			nome.erase(j, 1);
			len_nome--;
			j--;
		}
	}

	//cancelliamo le prime due cifre dell'anno
	anno.erase(0, 2);
	int app = stoi(giorno);

	//verifica se utente è femmina
	if (femmina == true)
	{
		app = app + 40;
		data = app;
	}
	else {
		data = giorno;
	}
	
	//cerchiamo il codice della città nel file
	File.open("lista-codici.txt");
	while (!File.eof())
	{
		getline(File, database);
		if (_strnicmp(citta.c_str(), database.c_str(), citta.size()) == 0)
		{
			const char *punto_virgola = strrchr(database.c_str(), ';');
			if (punto_virgola != NULL)
			{
				codice_comune = punto_virgola + 1;
			}
		}
	}
	risultato = cognome + vocale_cognome + nome + anno + a_mesi[mese] + data + codice_comune;

	//calcolo del carattere di controllo (una lettera)
	char pos_dispari[254], pos_pari[254];
	int lun_codice = risultato.size();
	//creiamo un array char che prende come dimensione la lunghezza del codice fiscale aggiungendo un posto per il carattere di controllo
	char* codice_fiscale=new char[lun_codice+1];
	char controllo_lettere[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
	'H','I','J', 'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	//convertiamo la stringa in un array di char
	strcpy(codice_fiscale, risultato.c_str());

	//calcoliamo il carattere finale di controllo
	for (int j = 0; j < lun_codice; j++)
	{
		if (j == 0 || j == 2 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16 || j==18 || j==20)
		{
			pos_pari[j] = codice_fiscale[j];
		}
		if (j == 1 || j == 3 || j == 5 || j == 7 || j == 9 || j == 11 || j == 13 || j == 15 || j == 17 ||j==19 || j==21)
		{
			pos_dispari[j] = codice_fiscale[j];
		}
	}
	int somma = 0;
	int somma_dispari = 0;
	for (int j = 0; j < 254; j++)
	{
		if (pos_pari[j] == '1' || pos_pari[j] == 'B')
		{
			somma = somma + 1;
		}
		if (pos_pari[j] == '2' || pos_pari[j] == 'C')
		{
			somma = somma + 2;
		}
		if (pos_pari[j] == '3' || pos_pari[j] == 'D')
		{
			somma = somma + 3;
		}
		if (pos_pari[j] == '4' || pos_pari[j] == 'E')
		{
			somma = somma + 4;
		}
		if (pos_pari[j] == '5' || pos_pari[j] == 'F')
		{
			somma = somma + 5;
		}
		if (pos_pari[j] == '6' || pos_pari[j] == 'G')
		{
			somma = somma + 6;
		}
		if (pos_pari[j] == '7' || pos_pari[j] == 'H')
		{
			somma = somma + 7;
		}
		if (pos_pari[j] == '8' || pos_pari[j] == 'I')
		{
			somma = somma + 8;
		}
		if (pos_pari[j] == '9' || pos_pari[j] == 'J')
		{
			somma = somma + 9;
		}
		if (pos_pari[j] == 'K')
		{
			somma = somma + 10;
		}
		if (pos_pari[j] == 'L')
		{
			somma = somma + 11;
		}
		if (pos_pari[j] == 'M')
		{
			somma = somma + 12;
		}
		if (pos_pari[j] == 'N')
		{
			somma = somma + 13;
		}
		if (pos_pari[j] == 'O')
		{
			somma = somma + 14;
		}
		if (pos_pari[j] == 'P')
		{
			somma = somma + 15;
		}
		if (pos_pari[j] == 'Q')
		{
			somma = somma + 16;
		}
		if (pos_pari[j] == 'R')
		{
			somma = somma + 17;
		}
		if (pos_pari[j] == 'S')
		{
			somma = somma + 18;
		}
		if (pos_pari[j] == 'T')
		{
			somma = somma + 19;
		}
		if (pos_pari[j] == 'U')
		{
			somma = somma + 20;
		}
		if (pos_pari[j] == 'V')
		{
			somma = somma + 21;
		}
		if (pos_pari[j] == 'W')
		{
			somma = somma + 22;
		}
		if (pos_pari[j] == 'X')
		{
			somma = somma + 23;
		}
		if (pos_pari[j] == 'Y')
		{
			somma = somma + 24;
		}
		if (pos_pari[j] == 'Z')
		{
			somma = somma+ 25;
		}
		if (pos_dispari[j] == '0' || pos_dispari[j] == 'A')
		{
			somma_dispari = somma_dispari + 1;
		}
		if (pos_dispari[j] == '2' || pos_dispari[j] == 'C')
		{
			somma_dispari = somma_dispari + 5;
		}
		if (pos_dispari[j] == '3' || pos_dispari[j] == 'D')
		{
			somma_dispari = somma_dispari + 7;
		}
		if (pos_dispari[j] == '4' || pos_dispari[j] == 'E')
		{
			somma_dispari = somma_dispari + 9;
		}
		if (pos_dispari[j] == '5' || pos_dispari[j] == 'F')
		{
			somma_dispari = somma_dispari + 13;
		}
		if (pos_dispari[j] == '6' || pos_dispari[j] == 'G')
		{
			somma_dispari = somma_dispari + 15;
		}
		if (pos_dispari[j] == '7' || pos_dispari[j] == 'H')
		{
			somma_dispari = somma_dispari + 17;
		}
		if (pos_dispari[j] == '8' || pos_dispari[j] == 'I')
		{
			somma_dispari = somma_dispari + 19;
		}
		if (pos_dispari[j] == '9' || pos_dispari[j] == 'J')
		{
			somma_dispari = somma_dispari + 21;
		}
		if (pos_dispari[j] == 'K')
		{
			somma_dispari = somma_dispari + 2;
		}
		if (pos_dispari[j] == 'L')
		{
			somma_dispari = somma_dispari + 4;
		}
		if (pos_dispari[j] == 'M')
		{
			somma_dispari = somma_dispari + 18;
		}
		if (pos_dispari[j] == 'N')
		{
			somma_dispari = somma_dispari + 20;
		}
		if (pos_dispari[j] == 'O')
		{
			somma_dispari = somma_dispari + 11;
		}
		if (pos_dispari[j] == 'P')
		{
			somma_dispari = somma_dispari + 3;
		}
		if (pos_dispari[j] == 'Q')
		{
			somma_dispari = somma_dispari + 6;
		}
		if (pos_dispari[j] == 'R')
		{
			somma_dispari = somma_dispari + 8;
		}
		if (pos_dispari[j] == 'S')
		{
			somma_dispari = somma_dispari + 12;
		}
		if (pos_dispari[j] == 'T')
		{
			somma_dispari = somma_dispari + 14;
		}
		if (pos_dispari[j] == 'U')
		{
			somma_dispari = somma_dispari + 16;
		}
		if (pos_dispari[j] == 'V')
		{
			somma_dispari= somma_dispari + 10;
		}
		if (pos_dispari[j] == 'W')
		{
			somma_dispari = somma_dispari + 22;
		}
		if (pos_dispari[j] == 'X')
		{
			somma_dispari = somma_dispari + 25;
		}
		if (pos_dispari[j] == 'Y')
		{
			somma_dispari = somma_dispari + 24;
		}
		if (pos_dispari[j] == 'Z')
		{
			somma_dispari=somma_dispari+23;
		}
	}

	//calcolo finale del carattere di controllo
	int somma_finale = somma + somma_dispari*2;
	
	//dividiamo tutto per 26 e col risultato ricaviamo il carattere di controllo
	somma_finale = somma_finale / 26;

	//stampa codice fiscale
	risultato = cognome + vocale_cognome + nome + anno + a_mesi[mese] + data + codice_comune+controllo_lettere[somma_finale];
	cout << risultato;

	return 0;
}

// PROGRAMA --> Manipulació d'arxius
// AUTOR --> Pablo Abad Ortega
// DATA --> 09/12/2025

#include <iostream> // entrada i sortida (cin/cout)
#include <fstream> // manipulació d'arxius (ifstream)
#include <string> // ús del tipus de dada string
#include <cmath> // funcions matemàtiques (pow)

using namespace std; // espai de noms

unsigned short leer_short(ifstream& archivo) // funció per a llegir valor de 16 bits
{
	unsigned char byte_1, byte_2; // guarda els bytes per al valor de 16 bits
	byte_1 = archivo.get(); // llegeix el següent byte
	byte_2 = archivo.get(); // llegeix el següent byte
	// corregeix (desplaça) les posicions del segon byte per al número real que representa el total de bits
	return (unsigned short)(byte_1 | (byte_2 << 8));
}

int main()
{
	string nombre_archivo("D:\\AluCiclesGS1\\Manipulació de fitxers\\homer_gif.gif"); // ubicacio de l'arxiu gif
	// declara la variable sense inicialitzar-la amb una ruta fixa
	string nombre_archivo("homer_gif.gif");

	// obre l'arxiu. c_str() per a convertir el string a una cadena d'estil de C
	ifstream archivo(nombre_archivo, ifstream::binary);

	if (archivo.fail()) // comprova si ha fallat en obrir
	{
		cout << "ERROR: NO S'HA TROBAT --> " << nombre_archivo << endl;
		return 1; // en cas que falli, acaba el programa amb l'error
	}

	char firma[4]; // llegeix la "firma"

	archivo.read(firma, 3); // llegeix els 3 bytes de la firma (G, I, F)
	firma[3] = '\0'; // tanca la cadena amb el terminador nul

	char version[4]; // llegeix la versió de l'array de 4 caràcters

	archivo.read(version, 3); // llegeix els 3 bytes de la versió
	version[3] = '\0'; // tanca la cadena de versió

	if (string(firma) != "GIF") // comprova que la firma sigui realment la que és
	{
		cout << "NO ÉS UN ARXIU GIF - LA FIRMA ÉS --> " << firma << endl;
		archivo.close(); // tanca l'arxiu
		return 1; // acaba el programa amb l'error
	}

	unsigned short anchura = leer_short(archivo); // llegeix l'amplada de la imatge

	unsigned short altura = leer_short(archivo); // llegeix l'altura de la imatge

	unsigned char campo_empaquetado = archivo.get(); // llegeix els bytes de la imatge

	archivo.close(); // tanca l'arxiu

	// guarda els 3 bits que indiquen la mida de la taula de colors i suma 1 (N+1)
	int numero_bits_color = (campo_empaquetado & 0b00000111) + 1;

	// calcula el nombre total de colors (2 elevat al nombre de bits per color)
	int numero_colores = (int)pow(2, numero_bits_color);

	// ensenya tots els resultats per pantalla.
	cout << "FORMAT --> " << "GIF" << version << endl;
	cout << "AMPLADA --> " << anchura << " pixels" << endl;
	cout << "ALTURA --> " << altura << " pixels" << endl;
	cout << "NOMBRE DE COLORS --> " << numero_colores << endl;

	return 0; // final del programa
}
// PROGRAMA --> Sistema de Target a C++
// AUTOR --> Pablo Abad Ortega
// FECHA --> 27/11/2025

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// ESTRUCTURA DE DADES
struct Enemic // estructura de l'enemic
{
    int id = -1; // identificador únic
    double x = -1; // coordenades X
    double y = -1; // coordenades Y
    int healt_point = 30; // punts de vida
};

// FUNCIONS
Enemic* generar_enemics(int cantidad) // retorna punter a enemic.
{
    // reservar la memòria en un array d'una quantitat d'enemics donada per la variable "cantidad".
    Enemic* Array_Enemic = new Enemic[cantidad]; // creem un array de quantitat enemics

    // Omplir array d'"enemics"
    for (int i = 0; i < cantidad; i++)
    {
        cout << "ENEMIC " << i << endl; // Mostra el número de l'enemic actual.
        Array_Enemic[i].id = i; // assigno l'índex de "i" com la ID d'aquest enemic
        cout << Array_Enemic[i].id << endl; // mostra la ID per pantalla

        Array_Enemic[i].x = 1 + rand() % 10; // assigno la coordenada X de forma aleatòria entre 1 i 10
        Array_Enemic[i].y = 1 + rand() % 10; // assigno la coordenada Y de forma aleatòria entre 1 i 10
        cout << "(" << Array_Enemic[i].x << ", " << Array_Enemic[i].y << ")" << endl; // mostra les coordenades generades per a l'enemic.
    }

    return Array_Enemic; // retorna el punter a l'array creat
}

// BUSCAR ENEMICS APROP
int buscar_enemics_propers(Enemic* lista, int cantidad) // crear funció "buscar_enemics_propers"
{
    Enemic* mes_proxim = nullptr; // inicia el punter per a l'enemic (a l'inici està nul)
    double distancia_minima = 1000000.0; // inicia distància mínima gran
    cout << "SISTEMA D'ORIENTACIÓ ACTIVAT" << endl; // imprimeix text per pantalla


    // Posició fixa del jugador (0.0)
    double jugador_x = 0.0; // Coordenada X jugador
    double jugador_y = 0.0; // Coordenada Y jugador

    // Iteració per enemics
    for (int i = 0; i < cantidad; i++) // Bucle per enemics
    {
        // X i Y
        double d_x = lista[i].x - jugador_x; // Diferència eix X
        double d_y = lista[i].y - jugador_y; // Diferència eix Y

        // aplico pitàgores per a la distància FÓRMULA --> d = sqrt( dx^2 + dy^2 )
        double distancia_actual = std::sqrt(std::pow(d_x, 2) + std::pow(d_y, 2));

        // buscar la distància mínima
        if (distancia_actual < distancia_minima) // Si és més a prop
        {
            distancia_minima = distancia_actual; // Actualitza distància mínima
            mes_proxim = &lista[i]; // Guarda punter a enemic
        }
    }

    if (mes_proxim != nullptr) // Comprova si el punter es va actualitzar
    {
        cout << "S'HA TROBAT (LA ID ÉS --> " << mes_proxim->id << ") DISTÀNCIA DE --> " << distancia_minima << endl;
        return mes_proxim->id; // retorna la id de l'enemic proper
    }
    else
    {
        cout << "NO S'HA TROBAT L'ENEMIC!" << endl; //
        return -1; // retorna -1 en cas que no es trobi cap enemic vàlid
    }

    return 0;
}

// FUNCIÓ PRINCIPAL
int main() // inici del programa
{
    cout << "INTRODUEIX UNA QUANTITAT D'ENEMICS (MÍN. 3) --> " << endl; // imprimeix text per pantalla demanant el número
    int cantidad = 3; // variable per guardar l'entrada de l'usuari
    // cin >> cantidad; // l'usuari posa el número i es guarda a la variable

    Enemic* enemics_meus = generar_enemics(cantidad); // crea array per als enemics
    int target = buscar_enemics_propers(enemics_meus, cantidad); // busca l'enemic més proper

    return 0;
}
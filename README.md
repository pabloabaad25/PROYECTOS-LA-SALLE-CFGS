# 🚀 Portfolio de Programación: Gestión de Archivos y Algoritmia

¡Bienvenido a mi repositorio de prácticas! Aquí recojo una serie de proyectos desarrollados durante el curso, donde exploro desde la manipulación de sistemas de archivos en **Java** hasta el análisis binario y la gestión de memoria dinámica en **C++**.

---

## 📁 Estructura del Repositorio

En este repositorio he organizado mis trabajos según el lenguaje y el desafío técnico planteado. A continuación, detallo qué he realizado en cada documento:

### ☕ Proyectos en Java (I/O y Persistencia)

* **`PAO_RA1_P1.java` - Gestión de Sistema de Archivos**
    En este primer contacto con la clase `File`, desarrollé una herramienta de consola para interactuar con el sistema operativo. Implementé funciones para listar directorios, crear archivos `.txt`, comprobar permisos y generar nombres de ruta únicos.

* **`PAO_RA1_P2.java` - Sistema de Login con Persistencia**
    Aquí di un paso más allá creando un **sistema de autenticación**. Programé una lógica que permite registrar usuarios y contraseñas en un archivo plano, para luego validarlos mediante un motor de búsqueda que lee y parsea el archivo línea a línea usando `BufferedReader`.

* **`PAORA1P23.java` - Manipulación de XML (DOM)**
    Este es uno de los proyectos más complejos en Java. Utilicé la API **W3C DOM** para gestionar una base de datos de "Clash Royale" en formato XML. He programado funciones para añadir nodos de jugadores y simular partidas que actualizan automáticamente las estadísticas (copas) dentro del archivo `clash.xml`.



---

### 💻 Proyectos en C++ (Bajo Nivel y Algoritmia)

* **`Manipulació de fitxers.cpp` - Análisis Binario de GIFs**
    En este proyecto me enfoqué en el nivel más bajo de los datos. Realicé un programa que abre archivos en modo binario para leer sus "cabeceras". Mediante operaciones **Bitwise** (desplazamiento de bits) y máscaras, extraigo la versión, dimensiones (ancho/alto) y la tabla global de colores de cualquier imagen GIF.

* **`Sistema de Orientació amb Punters.cpp` - Lógica de Targeting**
    He desarrollado un sistema de detección de objetivos para videojuegos. Utilizando **punteros y reserva de memoria dinámica**, genero enemigos en un plano 2D y aplico el **Teorema de Pitágoras** para calcular distancias euclidianas, identificando en tiempo real cuál es el enemigo más próximo al jugador.



* **`Simulador de daus.cpp` - Interfaz ASCII y Azar**
    Combiné la generación de números aleatorios con **Arte ASCII**. Creé un simulador de dados D6 y D12 que imprime visualmente las caras en la consola, incluyendo una validación de entrada de usuario y control de pausas mediante la API de Windows (`windows.h`).

---

## 🛠️ Tecnologías y Conceptos Aplicados

| Tecnología | Conceptos Clave |
| :--- | :--- |
| **Java** | XML DOM, I/O Streams, Parsing de Strings, Manejo de Excepciones. |
| **C++** | Punteros, Memoria Dinámica, Operaciones Binarias, Geometría Analítica. |
| **Formatos** | TXT, XML, GIF (Estructura Binaria). |

## ⚙️ Instrucciones de Uso

1. **Java:** Compilar con `javac nombre_archivo.java` y ejecutar con `java nombre_archivo`.
2. **C++:** Compilar con cualquier estándar C++11 o superior (G++, Visual Studio, CLion). 
   * *Nota: El simulador de dados utiliza `windows.h`, por lo que está optimizado para entornos Windows.*

---
> Proyectos realizados por **Pablo Abad Ortega** - 2025.

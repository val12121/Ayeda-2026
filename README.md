### 📁 Práctica 1: Conceptos Básicos
Implementación fundamental de la Hormiga de Langton sobre un tablero de tamaño fijo.
* **Objetivo:** Control de movimiento básico y estados de color (Blanco/Negro).
* **Ejecutable:** `main.exe`

### 📁 Práctica 2: Generalización
Introducción de la **Hormiga Generalizada** (Ant_X) y gestión de múltiples colores y reglas.
* **Novedades:** Uso de reglas de giro personalizadas (L/R) y archivo de configuración.
* **Librería clave:** `colors.h` para visualización en terminal.

### 📁 Práctica 3: Ecosistema Evolucionado
Versión final con jerarquía de clases, interacción entre especies y tableros dinámicos.
* **Hormigas:** - `Herbivore`: Recolecta vida según el color que pisa.
  - `Carnivore`: Caza herbívoras basándose en el color de la celda (Depredación cromática).
* **Tableros (Tapes):**
  - `TapeSliding`: Tablero infinito que crece dinámicamente usando `SlidingVector`.
  - `TapePeriodic`: Mundo toroidal (la hormiga aparece por el lado opuesto).
  - `TapeReflective`: Rebote en los bordes.

---

## 🛠️ Estructura de Archivos (P03)

| Componente | Archivos |
| :--- | :--- |
| **Núcleo** | `main.cc`, `simulator.cc`, `simulator.h` |
| **Tableros** | `tape.cc`, `tape_sliding.cc`, `tape_sliding.h`, `tape_periodic.h` |
| **Hormigas** | `ant.cc`, `ant_x.cc`, `ant_herb.cc`, `ant_car.cc` |
| **Utilidades** | `sliding_vector.h`, `colors.h` |

---

## 💻 Compilación y Ejecución

Para compilar la versión más reciente (Práctica 3), utiliza el siguiente comando en tu terminal:

```bash
g++ -o main ant.cc ant_x.cc main.cc simulator.cc tape.cc tape_sliding.cc ant_herb.cc ant_car.cc
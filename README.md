# ds-linked-list

Implementación de **Linked List**, **Stack** y **Queue** en C++ desde cero, usando punteros, manejo manual de memoria y pruebas unitarias con Google Test.

## Demo

Las estructuras se pueden visualizar generando archivos `.dot` con Graphviz.

![Demo](outputs/linkedlist.png)

Pagina de muestra de las estructuras:
https://ds-visualizer-sigma.vercel.app/

### Requisitos para la visualización

Instalar Graphviz:

**Windows (ejecutable oficial):**
Descargar desde https://graphviz.org/download/ y marcar "Add Graphviz to PATH" durante la instalación.

**Windows (MSYS2/pacman):**
```bash
pacman -S mingw-w64-ucrt-x86_64-graphviz
```

**Linux:**
```bash
sudo apt install graphviz
```

Verificar instalación:
```bash
dot -V
```

### Generar imágenes

Correr el ejecutable principal genera los `.dot` y `.png` automáticamente en `outputs/`:
```bash
./ds_linked_list
```

Archivos generados:
- `outputs/linkedlist.dot` / `outputs/linkedlist.png`
- `outputs/stack.dot` / `outputs/stack.png`
- `outputs/queue.dot` / `outputs/queue.png`

## Estructuras implementadas

| Estructura | Archivo | Descripción |
|-----------|---------|-------------|
| `Node` | `include/Node.h` | Nodo base con dato y puntero al siguiente |
| `List` | `include/List.h` | Clase abstracta con interfaz común |
| `LinkedList` | `include/LinkedList.h` | Lista enlazada con `head` y `tail` (penúltimo) |
| `StackComposicion` | `include/StackComposicion.h` | Pila LIFO por composición sobre LinkedList |
| `QueueComposicion` | `include/QueueComposicion.h` | Cola FIFO por composición sobre LinkedList |

## Decisiones de diseño

- `Stack` y `Queue` usan **composición** sobre `LinkedList`  (no herencia) para no exponer operaciones que no tienen sentido semánticamente (insertar en medio de una pila, por ejemplo)
- `tail` apunta al **penúltimo nodo** para que `insert` al final sea O(1), `remove` al final sigue siendo O(n) ya que `tail` no puede retroceder sin recorrer la lista para O(1) en ambos extremos se necesitaria lista doblemente enlazada.
- `[[nodiscard]]` en todos los métodos que retornan valores para evitar ignorar resultados accidentalmente

## Complejidad

| Operación          | LinkedList | Stack     | Queue        |
|--------------------|------------|-----------|--------------|
| Insert inicio      | O(1)       | O(1) push | —            |
| Insert final       | O(1)       | —         | O(1) enqueue |
| Insert medio       | O(n)       | —         | —            |
| Remove inicio      | O(1)       | O(1) pop  | O(1) dequeue |
| Remove final       | O(n)       | —         | —            |
| Remove medio       | O(n)       | —         | —            |
| Search             | O(n)       | —         | —            |
| SearchPos inicio   | O(1)       | O(1) top  | O(1) front   |
| SearchPos final    | O(1)       | —         | —            |
| SearchPos medio    | O(n)       | —         | —            |

## Estructura del proyecto

```
ds-linked-list/
├── .clangd
├── .gitignore
├── CMakeLists.txt
├── README.md
├── include/
│   ├── List.h
│   ├── Node.h
│   ├── LinkedList.h
│   ├── StackComposicion.h
│   └── QueueComposicion.h
├── src/
│   ├── main.cpp
│   ├── Node.cpp
│   ├── LinkedList.cpp
│   ├── StackComposicion.cpp
│   └── QueueComposicion.cpp
└── test/
    ├── NodeTest.cpp
    ├── LinkedListTest.cpp
    ├── StackComposicionTest.cpp
    └── QueueComposicionTest.cpp
```

## Requisitos

- C++20 o superior
- CMake 4.1+
- CLion o cualquier compilador g++/clang++
- Google Test (instalado via `pacman -S mingw-w64-ucrt-x86_64-gtest` en Windows/MSYS2)

## Compilar y ejecutar
> Si usas CLion, el build es automático. Para compilar manualmente desde terminal:
```bash
mkdir cmake-build-debug && cd cmake-build-debug
cmake ..
cmake --build .
```

Ejecutar programa principal:
```bash
./ds_linked_list
```

Ejecutar tests:
```bash
./ds_linked_list_test
```

## Tests

| Suite | Tests | Estado |
|-------|-------|--------|
| `NodeTest` | 5 | ✅ |
| `LinkedListTest` | 27 | ✅ |
| `StackComposicionTest` | 12 | ✅ |
| `QueueComposicionTest` | 12 | ✅ |
| **Total** | **56** | ✅ |

## Topics

`data-structures` `linked-list` `stack` `queue` `cpp` `cmake` `googletest` `algorithms`
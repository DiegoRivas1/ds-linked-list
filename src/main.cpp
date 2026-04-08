#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "StackComposicion.h"
#include "QueueComposicion.h"

void saveDot(const std::string& content, const std::string& filename) {
    std::ofstream file("../outputs/" + filename);
    file << content;
    file.close();
    std::cout << "Generado: outputs/" << filename << "\n";
}

int main() {

    std::string structures[3] = {"linkedlist", "stack", "queue"};
    std::cout << "=== LinkedList ===\n";
    LinkedList list;
    int cantidadNodos = 0;
    for (int i = 0; i < cantidadNodos; i++) {
        list.insert(i + 1, i);
    }
    list.print();

    std::string nombreArchivo = structures[0] + ".dot";
    saveDot(list.toDot(), nombreArchivo);

    std::cout << "=== Stack ===\n";
    StackComposicion stack;

    for (int i = 0; i < cantidadNodos; i++) {
        stack.push(i + 1);
    }
    std::cout << stack;

    nombreArchivo = structures[1] + ".dot";
    saveDot(stack.toDot(), nombreArchivo);

    std::cout << "=== Queue ===\n";
    QueueComposicion queue;
    for (int i = 0; i < cantidadNodos; i++) {
        queue.enqueue(i + 1);
    }
    std::cout << queue;

    nombreArchivo = structures[2] + ".dot";
    saveDot(queue.toDot(), nombreArchivo);

    // Ejecucion automatica
    for (const auto& name : structures) {
        std::string cmd = "dot -Tpng ../outputs/";
        cmd += name;
        cmd += ".dot -o ../outputs/";
        cmd += name;
        cmd += ".png";

        int result = system(cmd.c_str());
        if (result == 0) {
            std::cout << "Imagen generada: outputs/" << name << ".png\n";
        } else {
            std::cout << "Error al generar: outputs/" << name << ".png\n";
        }
    }

    return 0;
}
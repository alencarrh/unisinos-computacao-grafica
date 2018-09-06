#include "../headers/System.h"
#include "../headers/Cubo.h"
#include <vector>
#include <stdio.h>

/*

    Cubo


    for GRUPO : MESH.GRUPOS
        vector<float> vs;//deletar no final do loop
        for FACE in GRUPO.FACES
            for VERTICE in FACE.VERTICES
                V = MESH->VERTICES[VERTICE]
                vs.push_back(V.x, V.y, V.z); //são 3 push_back
            
        criar VAO
        criar VBOs (1 VBO vertice, 1 VBO normais, 1 VBO texture OU utilizar 1 VBO com OFFSETs)
        //Não precisa manter o VBO, somente os VAO na memória. Porque o VBO já está na OpenGL.
        //
        
        // Passar os dados para cada VBO.
        passarDados()
        
        //
        definir_layout() //vertexAttribute

        

*/

/*
    Desenhar

    main loop
        {   
            ...

            for GRUPO : MESH.GRUPOS
                glBindVAO(GRUPO->vao)
                glDrawArrays(TRIANGULO, 0, GRUPO->numero_de_vertices)
            
            ...
    
        }





        Model Matrix:
            -> Deve fazer a transalação, rotação e escala do objeto.

        View Matrix:
            -> Comera -> Traz a câmera do bar do alemão para a sala de aula.
                -> Para o objeto ser visto do ponto e da direção camera.

        Projction Matrix:
            -> Aplicar perspectiva




        Leitura OBJ:
            identificar maiorX, maiorY, maiorZ, menorX, menorY, menorZ
            camera -> mantendo a direção no 0,0,0 (target)
            
           

        angulo para cooredenada se utiliza sin(), cos()
        cos() = x
        sin() = y

        target = cos() + sin();


*/

int main() {

    Cubo* cubo = new Cubo(800, 800, "Cubo!");
    
    System* system = new System(cubo);
    
    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }
    
    
    system->run();

}

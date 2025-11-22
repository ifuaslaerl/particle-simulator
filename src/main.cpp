#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../include/Config.hpp"
#include "../include/Simulation.hpp"

void escape_exit(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

int main(){
    if(!glfwInit()){
        std::cerr << "Falha ao Inicializar Biblioteca GLFW3" << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

    if(!window){
        std::cerr << "Falha ao Inicializar Janela de execução" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, escape_exit);

    // Initialize Simulation
    Simulation sim;

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);

        // Update Physics
        sim.update();
        
        // Render
        sim.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

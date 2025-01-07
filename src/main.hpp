#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
GLFWwindow* window;
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

int initWinGLFW(GLFWwindow*& window) {
    
    if(!glfwInit()){
        std::cerr << "Failed to init glfw...";
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    window = glfwCreateWindow(800, 600, "CHRISTMAS TREE", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to display window" << std::endl;
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "failed to init GLAD" << std::endl;
        return -1;
    }
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}


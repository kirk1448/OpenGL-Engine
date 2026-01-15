#include <iostream>
#include <glew.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(void)
{
    const int WIDTH = 640;
    const int HEIGHT = 360;

    // Initialize GLFW
    if (!glfwInit())
    {
        std::cout << "Failed to setup GLFW!" << std::endl;
        return -1;
    }

    // Setting up GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Engine", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to setup window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to setup GLEW!" << std::endl;
        return -1;
    }

    // Init viewport
    glViewport(0, 0, WIDTH, HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Finally start window loop
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
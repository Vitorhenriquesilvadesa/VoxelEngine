#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define DEBUG_ERROR(cause, message) std::cerr << cause << "::" << message << std::endl

int main()
{
	if (!glfwInit())
	{
		DEBUG_ERROR("glfwInit", "Could not initialize GLFW.");
	}

	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Test", NULL, NULL);

	if (window == NULL)
	{
		DEBUG_ERROR("glfwCreateWindow", "Could not create GLFW window.");
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		DEBUG_ERROR("gladLoadGLLoader", "Could not load OpenGL functions.");
	}

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>

int main();

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	glfwInit();   //initialize GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);    //告诉GLFW我们使用GL主版本号为3，次版本号为3，即OpenGL3.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	  //告诉GLFW我们使用GL主版本号为3，次版本号为3，即OpenGL3.2
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Mac需要

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);  //通知GLFW将我们窗口的上下文设置为当前线程的主上下文

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))		 //初始化GLAD
	{																 //以确保能调用
		std::cout << "Failed to initialize GLAD" << std::endl;		 //任何OpenGL的函数
		return -1;													 //
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //告诉GLFW我们希望每当窗口调整大小的时候调用这个函数framebuffer_size_callback

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);  //告诉OpenGL渲染窗口的尺寸大小
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
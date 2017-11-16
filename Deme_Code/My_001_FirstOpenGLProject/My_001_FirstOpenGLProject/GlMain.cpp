#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>

int main();

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	glfwInit();   //initialize GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);    //����GLFW����ʹ��GL���汾��Ϊ3���ΰ汾��Ϊ3����OpenGL3.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	  //����GLFW����ʹ��GL���汾��Ϊ3���ΰ汾��Ϊ3����OpenGL3.2
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Mac��Ҫ

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);  //֪ͨGLFW�����Ǵ��ڵ�����������Ϊ��ǰ�̵߳���������

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))		 //��ʼ��GLAD
	{																 //��ȷ���ܵ���
		std::cout << "Failed to initialize GLAD" << std::endl;		 //�κ�OpenGL�ĺ���
		return -1;													 //
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //����GLFW����ϣ��ÿ�����ڵ�����С��ʱ������������framebuffer_size_callback

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
	glViewport(0, 0, width, height);  //����OpenGL��Ⱦ���ڵĳߴ��С
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
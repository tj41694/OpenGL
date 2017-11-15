#ifndef SHADER_H
#define SHADER_H

#include <glad\glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
class Shader
{
public:
	// 程序ID
	unsigned int ID;

	// 构造器读取并构建着色器
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// 使用/激活程序
	void use();
	// uniform工具函数
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setFloat(const std::string &name, float value1, float value2, float value3) const;
	void setVec3(const std::string &name, glm::vec3 vector);
	void setMatrix4fv(const std::string &name, GLsizei matrixNum, GLboolean transpose, const glm::mat4 mat) const;
	~Shader();
};

#endif
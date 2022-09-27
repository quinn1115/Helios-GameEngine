#include <Graphics/Shader.h>
#include <Debug/Logger.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/gl.h>


using namespace Helios;


Shader::Shader(std::string a_VertexFile, std::string a_FragmentFile)
{
	
	std::string shaderPath = "Resources/Shader/";

	std::string vFullPath = (shaderPath + a_VertexFile);
	std::string fFullPath = (shaderPath + a_FragmentFile);

	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		vShaderFile.open(vFullPath);
		fShaderFile.open(fFullPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch(std::ifstream::failure e)
	{
		Log::LogError("SHADER: File not successfully read.");
	}

	vShaderCode = vertexCode.c_str();
	fShaderCode = fragmentCode.c_str();
	
	CompileShader();


}

Shader::~Shader()
{}


void Shader::CompileShader()
{
	int success;
	char infoLog[512];

	m_Vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_Vertex, 1, &vShaderCode, NULL);
	glCompileShader(m_Vertex);

	glGetShaderiv(m_Vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m_Vertex, 512, NULL, infoLog);
		Log::LogError("SHADER::VERTEX::COMPILATION_FAILED\n {}", infoLog);
	}
	
	m_Fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_Fragment, 1, &fShaderCode, NULL);
	glCompileShader(m_Fragment);

	glGetShaderiv(m_Fragment, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(m_Fragment, 512, NULL, infoLog);
		Log::LogError("SHADER::FRAGMENT::COMPILATION_FAILED\n {}", infoLog);
	}


	m_ProgramID = glCreateProgram();
	glAttachShader(m_ProgramID, m_Vertex);
	glAttachShader(m_ProgramID, m_Fragment);
	glLinkProgram(m_ProgramID);

	glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);
	if (!success) 
	{
		glGetProgramInfoLog(m_ProgramID, 512, NULL, infoLog);
		Log::LogError("SHADER::PROGRAM::LINKING_FAILED\n {}", infoLog);
	}

	glDeleteShader(m_Vertex);
	glDeleteShader(m_Fragment);

}

void Shader::SetBool(const std::string& a_Name, bool a_Value) const
{
	glUniform1i(glGetUniformLocation(m_ProgramID, a_Name.c_str()), static_cast<int>(a_Value));
}

void Shader::SetInt(const std::string& a_Name, int a_Value) const
{
	glUniform1i(glGetUniformLocation(m_ProgramID, a_Name.c_str()), a_Value);
}
void Shader::SetFloat(const std::string& a_Name, float a_Value) const 
{
	glUniform1f(glGetUniformLocation(m_ProgramID, a_Name.c_str()), a_Value);
}

void Shader::SetVec3(const std::string& a_Name, const glm::vec3& a_Vec) const 
{
	glUniform3fv(glGetUniformLocation(m_ProgramID, a_Name.c_str()), 1, &a_Vec[0]);
}
void Shader::SetMat4(const std::string& a_Name, const glm::mat4& a_Mat) const 
{
	
	glUniformMatrix4fv(glGetUniformLocation(m_ProgramID, a_Name.c_str()), 1, GL_FALSE, &a_Mat[0][0]);
}

void Shader::Use()
{
	glUseProgram(m_ProgramID);
}

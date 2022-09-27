#pragma once
#include <string>
#include <glm.hpp>

namespace Helios
{
	class Shader
	{
	public:
		Shader(std::string a_VertexFile, std::string a_FragmentFile);
		~Shader();

		void Use();
		void CompileShader();


		void SetBool(const std::string& a_Name, bool a_Value) const;
		void SetInt(const std::string& a_Name, int a_Value) const;
		void SetFloat(const std::string& a_Name, float a_Value) const;
	
		void SetVec3(const std::string& a_Name, const glm::vec3& a_Vec) const;
		void SetMat4(const std::string& a_Name, const glm::mat4& a_Mat) const;

	private:

		unsigned int m_ProgramID;

		const char* vShaderCode;
		const char* fShaderCode;

		unsigned int m_Vertex, m_Fragment;

	};
}
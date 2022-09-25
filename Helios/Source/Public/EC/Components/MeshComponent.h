#pragma once
#include "EC/Component.h"
#include <vector>
#include <glm.hpp>

namespace Helios
{
	class Shader;

	struct FVertex
	{
		std::vector<glm::vec3> position;
		std::vector<glm::vec3> normal;
		std::vector<glm::vec2> UVCoors;
	};

	class MeshComponent : public Component
	{
	public:
		MeshComponent(std::string a_CompTag);
		~MeshComponent();

		void Init() override;
		void Update(float deltaTime) override;

		void SetupMesh();
		void ClearMeshData();

		//Getter/Setters
		Shader* GetShader() { return m_pShader; }
		void SetShader(Shader* a_pShader) { m_pShader = a_pShader; }


	private:
		
		std::vector<FVertex> m_VertexData;
		std::vector<unsigned int> m_Indices;
		Shader* m_pShader;

		unsigned int VBO, VAO, EBO;
	};
}
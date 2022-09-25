#include "EC/Components/MeshComponent.h"
#include <Graphics/Shader.h>
#include "glad/gl.h"

using namespace Helios;


MeshComponent::MeshComponent(std::string a_CompTag)
	: Component(a_CompTag)
{}

MeshComponent::~MeshComponent()
{}


void MeshComponent::Init()
{

	m_pShader = new Shader();
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	SetupMesh();
}

void MeshComponent::Update(float deltaTime)
{}

void MeshComponent::SetupMesh()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VAO);
	glBufferData(GL_ARRAY_BUFFER, m_VertexData.size() * sizeof(FVertex), &m_VertexData[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &m_Indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(FVertex), (void*)0);

	glBindVertexArray(0);
}

void MeshComponent::ClearMeshData()
{
	m_VertexData.clear();
	m_Indices.clear();
}

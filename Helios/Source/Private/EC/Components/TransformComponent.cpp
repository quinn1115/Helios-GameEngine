#include "EC/Components/TransformComponent.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/quaternion.hpp>

using namespace Helios;


TransformComponent::TransformComponent(std::string a_CompTag)
	: Component(a_CompTag)
{}

TransformComponent::~TransformComponent()
{}

void TransformComponent::Init()
{
	m_Transform = Transform();
}

void TransformComponent::AddPosition(glm::vec3 a_Position)
{
	m_Transform.Translation += a_Position;

}

void TransformComponent::SetPosition(glm::vec3 a_Position)
{
	m_Transform.Translation = a_Position;
}

void TransformComponent::AddRotation(glm::vec3 a_Rotation)
{
	m_Transform.Rotation += a_Rotation;
}

void TransformComponent::SetRotation(glm::vec3 a_Rotation)
{
	m_Transform.Rotation = a_Rotation;
}



void TransformComponent::AddScale(glm::vec3 a_Scale)
{
	m_Transform.Scale += a_Scale;
}

void TransformComponent::SetScale(glm::vec3 a_Scale)
{
	m_Transform.Scale = a_Scale;
}

glm::mat4 TransformComponent::GetTransform()
{
	glm::mat4 rotMat = glm::toMat4(glm::quat(m_Transform.Rotation));

	return glm::translate(glm::mat4(1.0f), m_Transform.Translation) * rotMat * glm::scale(glm::mat4(1.0f), m_Transform.Scale);
}
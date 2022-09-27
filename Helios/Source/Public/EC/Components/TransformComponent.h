#pragma once
#include "EC/Component.h"
#include "glm.hpp"
#include "gtx/quaternion.hpp"

namespace Helios
{
	struct Transform
	{
		glm::vec3 Translation = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::quat Rotation = glm::quat(glm::vec3(0,0,0));
		glm::vec3 Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	};

	class TransformComponent : public Component
	{
	public:

		TransformComponent(std::string a_CompTag);
		~TransformComponent();

		void Init() override;
		void Update(float deltaTime) override;

		void AddPosition(glm::vec3 a_Position);
		void SetPosition(glm::vec3 a_Position);

		void AddRotation(glm::vec3 a_Rotation);
		void SetRotation(glm::vec3 a_Rotation);
		

		void AddScale(glm::vec3 a_Scale);
		void SetScale(glm::vec3 a_Scale);

		glm::mat4 GetTransform();


	private:
		Transform m_Transform;
	};
}
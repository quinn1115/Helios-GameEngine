#pragma once


namespace Helios
{
	class TransformComponent;

	class Entity
	{
	public:
		Entity();
		virtual	~Entity();


		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void LateTick(float deltaTime);
		virtual void Render();


	private:
		TransformComponent* m_pTransformComp;

	};
}
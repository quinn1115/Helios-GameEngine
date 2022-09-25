#include "EC/Entity.h"
#include "EC/Components/TransformComponent.h"

using namespace Helios;

Entity::Entity()
{
	m_pTransformComp = new TransformComponent("TransformComp");
}

Entity::~Entity()
{
}

void Entity::BeginPlay()
{
}

void Entity::Tick(float deltaTime)
{
}

void Entity::LateTick(float deltaTime)
{
}

void Entity::Render()
{
	
}

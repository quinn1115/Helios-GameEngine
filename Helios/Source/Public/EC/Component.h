#pragma once
#include <string>

namespace Helios
{
	class Component
	{
	public:
		//Constructors
		Component(std::string a_CompTag);
		virtual ~Component();

		//Functionality
		virtual void Init() abstract;
		virtual void Update(float deltaTime) abstract;
	
		//Getter/Setters
		std::string GetTag() { return m_CompTag; }
		void SetTag(std::string a_CompTag) { m_CompTag = a_CompTag; }

	private:
		//Member Variables
		std::string m_CompTag;
	};
}
#pragma once
#include "engine.h"
#include "id.h"

class ENGINE_API Object
{

public:
	Object(const ID iID = ID()) : m_id(iID) {}
	virtual ~Object() {}

	bool operator == (const Object& obj) const { return this->m_id == obj.m_id; }
	bool operator != (const Object& obj) const { return this->m_id != obj.m_id; }

	bool operator == (const ID& id) const { return this->m_id == id; }
	bool operator != (const ID& id) const { return this->m_id != id; }

protected:
	ID m_id;

};


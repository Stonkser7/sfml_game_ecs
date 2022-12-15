#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H



enum ComponentID {
	Position,
	Rotation,
	Direction,
	Acceleration,
	Speed,

	Count			//keep it latest
};

const size_t MAX_COMPONENTS = ComponentID::Count;

class ComponentManager
{
public:

private:
};

#endif
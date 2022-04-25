#pragma once

class Component
{

};

class MConsoleTransform :Component
{
public:

	int x;
	int y;
};

class MObject {

public:
	MObject();
	virtual ~MObject();

	virtual void Start() {};
	virtual void Update() {};
	virtual void Render() {};


private:
};
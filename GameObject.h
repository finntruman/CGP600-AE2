#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT
#include <xnamath.h>
#include <vector>

struct VERTEX_BUFFER
{
	XMFLOAT3 Pos;
	XMFLOAT4 Col;
};

class GameObject
{
protected:
	std::vector<VERTEX_BUFFER> m_vertexBuffer;
	XMMATRIX m_world; // world transform = scale * rotation * translation
	XMMATRIX m_scale;
	XMMATRIX m_rotation;
	XMMATRIX m_translate;

public:
	GameObject();
	~GameObject();
	virtual void Update();

	XMMATRIX GetWorld() { return m_world; }

	void ScaleBy(float x, float y, float z);
	void ScaleTo(float x, float y, float z);
	void RotateBy(float x, float y, float z);
	void RotateTo(float x, float y, float z);
	void Translate(float x, float y, float z);
	void SetPosition(float x, float y, float z);
};


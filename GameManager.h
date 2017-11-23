#pragma once
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <dxerr.h>
#include <stdio.h>

#include <forward_list>

class GameObject;

class GameManager
{
private:
	static GameManager* p_manager; // singleton GameManager

	std::forward_list<GameObject*> m_instanceList;
	std::forward_list<GameObject*> m_destructionList;

	////////////////////////////
	// DIRECTX SETUP
	////////////////////////////
	int DirectXSetup(HINSTANCE hInstance, int nCmdShow);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	HRESULT InitialiseWindow(HINSTANCE hInstance, int nCmdShow);
	HRESULT InitialiseD3D();
	HRESULT InitialiseGraphics();
	void ShutdownD3D();

public:
	GameManager(HINSTANCE hInstance, int nCmdShow);
	~GameManager();
	void Update();

	GameObject* Instantiate(GameObject* obj);
};


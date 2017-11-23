//#include <windows.h>
//#include <d3d11.h>
//#include <d3dx11.h>
//#include <dxerr.h>
//#include <stdio.h>

#include "GameManager.h"

//int (WINAPIV * __vsnprintf_s)(char *, size_t, const char*, va_list) = _vsnprintf;

////////////////////////////
// GLOBAL VARS
////////////////////////////
//char		g_programName[100]	= "Finn Truman CGP600 AE2";
//HINSTANCE	g_hInst				= NULL;
//HWND		g_hWnd				= NULL;
//D3D_DRIVER_TYPE         g_driverType		= D3D_DRIVER_TYPE_NULL;
//D3D_FEATURE_LEVEL       g_featureLevel		= D3D_FEATURE_LEVEL_11_0;
//ID3D11Device*           g_pD3DDevice		= NULL;
//ID3D11DeviceContext*    g_pImmediateContext = NULL;
//IDXGISwapChain*         g_pSwapChain		= NULL;
//ID3D11RenderTargetView* g_pBackBufferRTView = NULL;
//ID3D11Buffer*			g_pVertexBuffer		= NULL;
//ID3D11VertexShader*		g_pVertexShader		= NULL;
//ID3D11PixelShader*		g_pPixelShader		= NULL;
//ID3D11InputLayout*		g_pInputLayout		= NULL;
//ID3D11Buffer*			g_pConstantBuffer0	= NULL;
//ID3D11Buffer*			g_pConstantBuffer1	= NULL;
//ID3D11DepthStencilView* g_pZBuffer			= NULL;

////////////////////////////
// FORWARD DECLARATIONS
////////////////////////////
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HRESULT InitialiseWindow(HINSTANCE hInstance, int nCmdShow);
//HRESULT InitialiseD3D();
//HRESULT InitialiseGraphics();
//void ShutdownD3D();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	/*if (FAILED(InitialiseWindow(hInstance, nCmdShow)))
	{
		DXTRACE_MSG("Failed to create Window");
		return 0;
	}

	if (FAILED(InitialiseD3D()))
	{
		DXTRACE_MSG("Failed to create Device");
		return 0;
	}*/

	GameManager* game = new GameManager(hInstance, nCmdShow);

	// Main message loop
	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			game->Update();
		}
	}

	//ShutdownD3D();

	return (int)msg.wParam;
}

////////////////////////////
//
////////////////////////////
//HRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hdc;
//
//	switch (message)
//	{
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		EndPaint(hWnd, &ps);
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	//case WM_KEYDOWN:
//	//	if (wParam == VK_ESCAPE)
//	//		DestroyWindow(g_hWnd);
//
//		return 0;
//
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//
//	return 0;
//}

//HRESULT InitialiseWindow(HINSTANCE hInstance, int nCmdShow)
//{
//	// Give app window a own name
//	char Name[100] = "Hello World\0";
//
//	// Register class
//	WNDCLASSEX wcex = { 0 };
//	wcex.cbSize = sizeof(WNDCLASSEX);
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = WndProc;
//	wcex.hInstance = hInstance;
//	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wcex.lpszClassName = Name;
//
//	if (!RegisterClassEx(&wcex)) return E_FAIL;
//
//	// Create window
//	g_hInst = hInstance;
//	RECT rc = { 0, 0, 640, 480 };
//	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
//	g_hWnd = CreateWindow(Name, g_programName, WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left,
//		rc.bottom - rc.top, NULL, NULL, hInstance, NULL);
//	if (!g_hWnd)
//		return E_FAIL;
//
//	ShowWindow(g_hWnd, nCmdShow);
//
//	return S_OK;
//}

//HRESULT InitialiseD3D()
//{
//	HRESULT hr = S_OK;
//
//	RECT rc;
//	GetClientRect(g_hWnd, &rc);
//	UINT width = rc.right - rc.left;
//	UINT height = rc.bottom - rc.top;
//
//	UINT createDeviceFlags = 0;
//
//#ifdef _DEBUG
//	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
//#endif
//
//	D3D_DRIVER_TYPE driverTypes[] =
//	{
//		D3D_DRIVER_TYPE_HARDWARE, // comment out this line if you need to test D3D 11.0 functionality on hardware that doesn't support it
//		D3D_DRIVER_TYPE_WARP, // comment this out also to use reference device
//		D3D_DRIVER_TYPE_REFERENCE,
//	};
//	UINT numDriverTypes = ARRAYSIZE(driverTypes);
//
//	D3D_FEATURE_LEVEL featureLevels[] =
//	{
//		D3D_FEATURE_LEVEL_11_0,
//		D3D_FEATURE_LEVEL_10_1,
//		D3D_FEATURE_LEVEL_10_0,
//	};
//	UINT numFeatureLevels = ARRAYSIZE(featureLevels);
//
//	DXGI_SWAP_CHAIN_DESC sd;
//	ZeroMemory(&sd, sizeof(sd));
//	sd.BufferCount = 1;
//	sd.BufferDesc.Width = width;
//	sd.BufferDesc.Height = height;
//	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//	sd.BufferDesc.RefreshRate.Numerator = 60;
//	sd.BufferDesc.RefreshRate.Denominator = 1;
//	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//	sd.OutputWindow = g_hWnd;
//	sd.SampleDesc.Count = 1;
//	sd.SampleDesc.Quality = 0;
//	sd.Windowed = true;
//
//	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
//	{
//		g_driverType = driverTypes[driverTypeIndex];
//		hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL,
//			createDeviceFlags, featureLevels, numFeatureLevels,
//			D3D11_SDK_VERSION, &sd, &g_pSwapChain,
//			&g_pD3DDevice, &g_featureLevel, &g_pImmediateContext);
//		if (SUCCEEDED(hr))
//			break;
//	}
//
//	if (FAILED(hr))
//		return hr;
//
//	// Get pointer to back buffer texture
//	ID3D11Texture2D *pBackBufferTexture;
//	hr = g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
//		(LPVOID*)&pBackBufferTexture);
//
//	if (FAILED(hr)) return hr;
//
//	// Use the back buffer texture pointer to create the render target view
//	hr = g_pD3DDevice->CreateRenderTargetView(pBackBufferTexture, NULL,
//		&g_pBackBufferRTView);
//	pBackBufferTexture->Release();
//
//	if (FAILED(hr)) return hr;
//
//	// Create a Z Buffer texture
//	D3D11_TEXTURE2D_DESC tex2dDesc;
//	ZeroMemory(&tex2dDesc, sizeof(tex2dDesc));
//
//	tex2dDesc.Width = width;
//	tex2dDesc.Height = height;
//	tex2dDesc.ArraySize = 1;
//	tex2dDesc.MipLevels = 1;
//	tex2dDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
//	tex2dDesc.SampleDesc.Count = sd.SampleDesc.Count;
//	tex2dDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
//	tex2dDesc.Usage = D3D11_USAGE_DEFAULT;
//
//	ID3D11Texture2D *pZBufferTexture;
//	hr = g_pD3DDevice->CreateTexture2D(&tex2dDesc, NULL, &pZBufferTexture);
//
//	if (FAILED(hr)) return hr;
//
//	//Create the Z Buffer
//	CD3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc;
//	ZeroMemory(&dsvDesc, sizeof(dsvDesc));
//
//	dsvDesc.Format = tex2dDesc.Format;
//	dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
//
//	g_pD3DDevice->CreateDepthStencilView(pZBufferTexture, &dsvDesc, &g_pZBuffer);
//	pZBufferTexture->Release();
//
//	// Set the render target view
//	g_pImmediateContext->OMSetRenderTargets(1, &g_pBackBufferRTView, g_pZBuffer);
//
//	// Set the viewport
//	D3D11_VIEWPORT viewport;
//
//	viewport.TopLeftX = 0;
//	viewport.TopLeftY = 0;
//	viewport.Width = width;
//	viewport.Height = height;
//	viewport.MinDepth = 0.0f;
//	viewport.MaxDepth = 1.0f;
//
//	g_pImmediateContext->RSSetViewports(1, &viewport);
//
//	return S_OK;
//}
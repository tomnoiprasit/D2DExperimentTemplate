// Windows Header Files:
#include <windows.h>
#include <windowsx.h>
#include <vector>
#include <random>

// D2D
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

// --------- Specific includes

#include "GameTime.h"
#include "Background.h"
#include "LabelDisplayBox.h"
#include "TUtils.h"

// Libraries
#pragma comment(lib, "d2d1")
#pragma comment(lib, "Dwrite")
#pragma comment(lib, "Windowscodecs")

template<class Interface>
inline void SafeRelease(
	Interface **ppInterfaceToRelease
	)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

#ifndef Assert
#if defined( DEBUG ) || defined( _DEBUG )
#define Assert(b) do {if (!(b)) {OutputDebugStringA("Assert: " #b "\n");}} while(0)
#else
#define Assert(b)
#endif //DEBUG || _DEBUG
#endif

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

#define FRAME_RATE 33.3333
#define SCREEN_UPDATE 0.01
#define APP_WINDOW_WIDTH 800
#define APP_WINDOW_HEIGHT 600
#define APP_WINDOW_CAPTION "NCST - Game Project"

class BaseApp
{
public:
	BaseApp();
	~BaseApp();

	// Register the window class and call methods for instantiating drawing resources
	HRESULT initialize();

	// Process and dispatch messages
	void runMessageLoop();

private:
	HWND mainWindowHandle;
	ID2D1Factory * d2dFactory = NULL;
	ID2D1HwndRenderTarget* renderingTarget = NULL;
	IWICImagingFactory* wicImaingFactory = NULL;
	IWICBitmapDecoder* wicBitmapDecoder = NULL;
	IWICFormatConverter* wicFormatConverter = NULL;
	IWICBitmapFrameDecode* wicBitmapFrameDecode = NULL;
	IDWriteFactory* d2dDWriteFactory = NULL;

	// Initialize device-independent resources.
	HRESULT createDeviceIndependentResources();
	// Initialize device-dependent resources.
	HRESULT createDeviceResources(HWND);
	// Resize the render target.
	void onResize(UINT, UINT);


	// Release device-dependent resource.
	//void DiscardDeviceResources();

	// The windows procedure.
	static LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);


	std::vector<ID2D1Bitmap*> spriteSheets;
	std::vector<std::vector<D2D1_RECT_F>> sprites;
	std::vector<std::string> spriteSheetFiles;

	std::vector<D2D1_COLOR_F> brushColor;
	std::vector<ID2D1SolidColorBrush*> solidBrushes;

	std::vector<IDWriteTextFormat*> textFormats;
	std::vector<std::string> fonts;
	std::vector<float> fontSizes;

	GameTime gameTime;

	// The following methods are likely needed
	// to be modified to your own apps

	void initializeGameAssets();
	// Load configuration file
	void loadConfig();
	// Draw content.
	HRESULT onRender();

	// main update
	void update();
	
	// cleaning up
	void cleanUp();

	// Handle keyboard.
	HRESULT onKeyDown(WPARAM);
	// Handle mouse
	void onLButtonDown(int, int, DWORD);
	void onMouseMove(int, int, DWORD);
	void onLButtonUp();

	// Your game specific methods after this.

	Background background;
	std::vector<LabelDisplayBox> labels;

};

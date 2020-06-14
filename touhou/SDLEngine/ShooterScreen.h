#pragma once
#include "../MemoryLeakChecker.h"
#include "ShooterObject.h"

typedef enum SHOOTERSCREEN_RENDERER
{
	RENDERER_DIRECTX = 0,
	RENDERER_OPENGL
} SHOOTERSCREEN_RENDERER;

#ifdef __NDS__
#define DEFAULT_WINDOW_WIDTH  256
#define DEFAULT_WINDOW_HEIGHT (2*192)
#else
#define DEFAULT_WINDOW_WIDTH  640
#define DEFAULT_WINDOW_HEIGHT 480
#endif

#define VERBOSE_VIDEO   0x00000001
#define VERBOSE_MODES   0x00000002
#define VERBOSE_RENDER  0x00000004
#define VERBOSE_EVENT   0x00000008

typedef struct
{
	/* SDL init flags */
	Uint32 flags;
	Uint32 verbose;

	/* Video info */
	const char *videodriver;
	int display;
	std::string window_title;
	const char *window_icon;
	Uint32 window_flags;
	int window_x;
	int window_y;
	int window_w;
	int window_h;
	int depth;
	int refresh_rate;
	int num_windows;
	SDL_Window **windows;

	/* Renderer info */
	const char *renderdriver;
	Uint32 render_flags;
	SDL_bool skip_renderer;
	SDL_Renderer **renderers;

	/* GL settings */
	int gl_red_size;
	int gl_green_size;
	int gl_blue_size;
	int gl_alpha_size;
	int gl_buffer_size;
	int gl_depth_size;
	int gl_stencil_size;
	int gl_double_buffer;
	int gl_accum_red_size;
	int gl_accum_green_size;
	int gl_accum_blue_size;
	int gl_accum_alpha_size;
	int gl_stereo;
	int gl_multisamplebuffers;
	int gl_multisamplesamples;
	int gl_retained_backing;
	int gl_accelerated;
	int gl_major_version;
	int gl_minor_version;
} CommonState;

class ShooterScreen : public ShooterObject
{
private:
	int width;
	int height;
	int bpp;
	bool bFullScreen;
	bool bVSync;
	SHOOTERSCREEN_RENDERER iRenderer;

	CommonState *state;

	bool MakeScreenSurface();	//내부 함수.

	CommonState *CommonCreateState(std::string IN_WindowTitle);
	int CommonArg(CommonState * state, int index);
	SDL_bool CommonInit(CommonState * state);
	void CommonQuit(CommonState * state);
	void PrintRenderer(SDL_RendererInfo * info);
	void PrintRendererFlag(Uint32 flag);
	void ShooterScreen :: PrintPixelFormat(Uint32 format);
	SDL_Surface * LoadIcon(const char *file);

public:

	~ShooterScreen();
	bool MakeScreen(int IN_width, int IN_Height, int IN_bpp, bool IN_fullscreen, bool IN_VSync = true, SHOOTERSCREEN_RENDERER IN_Renderer = RENDERER_DIRECTX);
	bool FreeScreen();
	bool SetWindowCaption(std::string IN_string);
	bool FillColor(Uint8 IN_r = 0x00, Uint8 IN_g = 0x00, Uint8 IN_b = 0x00, Uint8 IN_a = 0xFF);
	bool Flip();
	bool GetFormat(SDL_PixelFormat ** OUT_Format);
	bool GetState(CommonState ** OUT_State);

};
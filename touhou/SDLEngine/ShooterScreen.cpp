#include "ShooterScreen.h"

ShooterScreen :: ~ShooterScreen()
{
	FreeScreen();
}

bool ShooterScreen :: MakeScreenSurface()
{
    state = CommonCreateState("");
	state->render_flags |= SDL_RENDERER_ACCELERATED;

	if (bVSync == true)
	{

		state->render_flags |= SDL_RENDERER_PRESENTVSYNC;
		state->refresh_rate = 60;
	}
	if (bFullScreen == true)
	{
		state->window_flags |= SDL_WINDOW_FULLSCREEN;
		state->num_windows = 1;
	}

	state->depth = bpp;
	state->window_w = width;
	state->window_h = height;

	if (iRenderer == RENDERER_DIRECTX)
	{
		state->renderdriver = "";
	}
	else if ( iRenderer == RENDERER_OPENGL)
	{
		state->renderdriver = "opengl";
	}

	state->verbose = VERBOSE_VIDEO | VERBOSE_RENDER;

	CommonInit(state);
	return true;

}

bool ShooterScreen :: MakeScreen(int IN_width, int IN_Height, int IN_bpp, bool IN_fullscreen, bool IN_VSync, SHOOTERSCREEN_RENDERER IN_Renderer)
{
	if (GetLoaded() == false)
	{
		printf ("Making Screen %dx%dx%d", IN_width, IN_Height, IN_bpp);
		if (IN_fullscreen == true)
		{
			printf (" (fullscreen) ... ");
		}
		else
		{
			printf (" (windowed) ... ");
		}
		printf ("\n");

		width = IN_width;
		height = IN_Height;
		bpp = IN_bpp;
		bFullScreen = IN_fullscreen;
		bVSync = IN_VSync;
		iRenderer = IN_Renderer;
		if (MakeScreenSurface() == true)
		{
			printf ("OK\n");
		}
		else
		{
			printf ("Failed\n");
			return false;
		}

		SetLoaded(true);
		return true;
	}
	
	return false;
}

bool ShooterScreen :: FreeScreen()
{
	if (GetLoaded() == true)
	{
		CommonQuit(state);
		SetLoaded(false);
		return true;
	}
	return false;
}

bool ShooterScreen :: SetWindowCaption(std::string IN_string)
{
	if (GetLoaded() == true)
	{
		char str[256];
		std::strcpy(str, IN_string.c_str());		//tohoxp custom
		//state->window_title = IN_string;
		SDL_SetWindowTitle(*(state->windows), str);

		return true;
	}
	return false;
}

bool ShooterScreen :: FillColor(Uint8 IN_r, Uint8 IN_g, Uint8 IN_b, Uint8 IN_a)
{
	if (GetLoaded() == true)
	{
		for (int i = 0; i < state->num_windows; ++i)
		{
			SDL_SetRenderDrawColor(state->renderers[i], IN_r, IN_g, IN_b, IN_a);
			SDL_RenderClear(state->renderers[i]);
		}
		return true;
	}

	return false;
}


bool ShooterScreen :: Flip()
{
	if (GetLoaded() == true)
	{
		for (int i = 0; i < state->num_windows; ++i) {
			SDL_RenderPresent(state->renderers[i]);
		}
		return true;
	}
	printf ("Flip Failed\n");
	return false;
}

//포인터 매개변수를 받고 그 매개변수에 포인터를 출력시키려면 이중 포인터를 써줘야되는것같다.
bool ShooterScreen :: GetFormat(SDL_PixelFormat ** OUT_Format)
{

	if (GetLoaded() == true)
	{
		
		return true;
	}

	return false;
}

bool ShooterScreen :: GetState(CommonState ** OUT_State)
{
	if (GetLoaded() == true)
	{
		*OUT_State = state;
		return true;
	}

	return false;
}


//by sam latinga
CommonState * ShooterScreen :: CommonCreateState(std::string IN_WindowTitle)
{
	CommonState *state = (CommonState*)(SDL_calloc(1, sizeof(*state)));
	if (!state) {
		SDL_OutOfMemory();
		return NULL;
	}

	/* Initialize some defaults */
	state->window_title = IN_WindowTitle;
	state->window_flags = 0;
	state->window_x = SDL_WINDOWPOS_UNDEFINED;
	state->window_y = SDL_WINDOWPOS_UNDEFINED;
	state->window_w = DEFAULT_WINDOW_WIDTH;
	state->window_h = DEFAULT_WINDOW_HEIGHT;
	state->num_windows = 1;
	
	/* Set some very sane GL defaults */
	state->gl_red_size = 3;
	state->gl_green_size = 3;
	state->gl_blue_size = 2;
	state->gl_alpha_size = 0;
	state->gl_buffer_size = 0;
	state->gl_depth_size = 16;
	state->gl_stencil_size = 0;
	state->gl_double_buffer = 1;
	state->gl_accum_red_size = 0;
	state->gl_accum_green_size = 0;
	state->gl_accum_blue_size = 0;
	state->gl_accum_alpha_size = 0;
	state->gl_stereo = 0;
	state->gl_multisamplebuffers = 0;
	state->gl_multisamplesamples = 0;
	state->gl_retained_backing = 1;
	state->gl_accelerated = -1;

	return state;
}

SDL_bool ShooterScreen :: CommonInit(CommonState * state)
{
	int i, j, m, n, w, h;
	SDL_DisplayMode fullscreen_mode;

	{
		if (state->verbose & VERBOSE_VIDEO) {
			n = SDL_GetNumVideoDrivers();
			if (n == 0) {
				printf("No built-in video drivers\n");
			} else {
				printf("Built-in video drivers:");
				for (i = 0; i < n; ++i) {
					if (i > 0) {
						printf( ",");
					}
					printf(" %s", SDL_GetVideoDriver(i));
				}
				printf("\n");
			}
		}
		if (SDL_VideoInit(state->videodriver) < 0) {
			printf("Couldn't initialize video driver: %s\n",
				SDL_GetError());
			return SDL_FALSE;
		}
		if (state->verbose & VERBOSE_VIDEO) {
			printf("Video driver: %s\n",
				SDL_GetCurrentVideoDriver());
		}

		/* Upload GL settings */
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, state->gl_red_size);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, state->gl_green_size);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, state->gl_blue_size);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, state->gl_alpha_size);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, state->gl_double_buffer);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, state->gl_buffer_size);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, state->gl_depth_size);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, state->gl_stencil_size);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, state->gl_accum_red_size);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, state->gl_accum_green_size);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, state->gl_accum_blue_size);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, state->gl_accum_alpha_size);
		SDL_GL_SetAttribute(SDL_GL_STEREO, state->gl_stereo);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, state->gl_multisamplebuffers);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, state->gl_multisamplesamples);
		if (state->gl_accelerated >= 0) {
			SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL,
				state->gl_accelerated);
		}
		SDL_GL_SetAttribute(SDL_GL_RETAINED_BACKING, state->gl_retained_backing);
		if (state->gl_major_version) {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, state->gl_major_version);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, state->gl_minor_version);
		}

		if (state->verbose & VERBOSE_MODES) {
			SDL_Rect bounds;
			SDL_DisplayMode mode;
			int bpp;
			Uint32 Rmask, Gmask, Bmask, Amask;

			n = SDL_GetNumVideoDisplays();
			fprintf(stderr, "Number of displays: %d\n", n);
			for (i = 0; i < n; ++i) {
				fprintf(stderr, "Display %d:\n", i);

				SDL_zero(bounds);
				SDL_GetDisplayBounds(i, &bounds);
				fprintf(stderr, "Bounds: %dx%d at %d,%d\n", bounds.w, bounds.h, bounds.x, bounds.y);

				SDL_GetDesktopDisplayMode(i, &mode);
				SDL_PixelFormatEnumToMasks(mode.format, &bpp, &Rmask, &Gmask,
					&Bmask, &Amask);
				fprintf(stderr,
					"  Current mode: %dx%d@%dHz, %d bits-per-pixel (%s)\n",
					mode.w, mode.h, mode.refresh_rate, bpp,
					SDL_GetPixelFormatName(mode.format));
				if (Rmask || Gmask || Bmask) {
					fprintf(stderr, "      Red Mask   = 0x%.8x\n", Rmask);
					fprintf(stderr, "      Green Mask = 0x%.8x\n", Gmask);
					fprintf(stderr, "      Blue Mask  = 0x%.8x\n", Bmask);
					if (Amask)
						fprintf(stderr, "      Alpha Mask = 0x%.8x\n", Amask);
				}

				/* Print available fullscreen video modes */
				m = SDL_GetNumDisplayModes(i);
				if (m == 0) {
					fprintf(stderr, "No available fullscreen video modes\n");
				} else {
					fprintf(stderr, "  Fullscreen video modes:\n");
					for (j = 0; j < m; ++j) {
						SDL_GetDisplayMode(i, j, &mode);
						SDL_PixelFormatEnumToMasks(mode.format, &bpp, &Rmask,
							&Gmask, &Bmask, &Amask);
						fprintf(stderr,
							"    Mode %d: %dx%d@%dHz, %d bits-per-pixel (%s)\n",
							j, mode.w, mode.h, mode.refresh_rate, bpp,
							SDL_GetPixelFormatName(mode.format));
						if (Rmask || Gmask || Bmask) {
							fprintf(stderr, "        Red Mask   = 0x%.8x\n",
								Rmask);
							fprintf(stderr, "        Green Mask = 0x%.8x\n",
								Gmask);
							fprintf(stderr, "        Blue Mask  = 0x%.8x\n",
								Bmask);
							if (Amask)
								fprintf(stderr,
								"        Alpha Mask = 0x%.8x\n",
								Amask);
						}
					}
				}
			}
		}

		if (state->verbose & VERBOSE_RENDER) {
// 			SDL_RendererInfo info;
// 
// 			n = SDL_GetNumRenderDrivers();
// 			if (n == 0) {
// 				printf("No built-in render drivers\n");
// 			} else {
// 				printf("Built-in render drivers:\n");
// 				for (i = 0; i < n; ++i) {
// 					SDL_GetRenderDriverInfo(i, &info);
// 					PrintRenderer(&info);
// 				}
// 			}
		}

		SDL_zero(fullscreen_mode);
		switch (state->depth) {
		case 8:
			fullscreen_mode.format = SDL_PIXELFORMAT_INDEX8;
			break;
		case 15:
			fullscreen_mode.format = SDL_PIXELFORMAT_RGB555;
			break;
		case 16:
			fullscreen_mode.format = SDL_PIXELFORMAT_RGB565;
			break;
		case 24:
			fullscreen_mode.format = SDL_PIXELFORMAT_RGB24;
			break;
		default:
			fullscreen_mode.format = SDL_PIXELFORMAT_RGB888;
			break;
		}
		fullscreen_mode.refresh_rate = state->refresh_rate;

		state->windows =
			(SDL_Window **) SDL_malloc(state->num_windows *
			sizeof(*state->windows));
		state->renderers =
			(SDL_Renderer **) SDL_malloc(state->num_windows *
			sizeof(*state->renderers));
		if (!state->windows || !state->renderers) {
			fprintf(stderr, "Out of memory!\n");
			return SDL_FALSE;
		}
		for (i = 0; i < state->num_windows; ++i) {
			char title[1024];

// 			if (state->num_windows > 1) {
// 				SDL_snprintf(title, SDL_arraysize(title), "%s %d",
// 					state->window_title.c_str(), i + 1);
// 			} else {
// 				SDL_strlcpy(title, state->window_title.c_str(), SDL_arraysize(title));
// 			}
			state->windows[i] =
				SDL_CreateWindow(state->window_title.c_str(), state->window_x, state->window_y,
				state->window_w, state->window_h,
				state->window_flags);
			if (!state->windows[i]) {
				fprintf(stderr, "Couldn't create window: %s\n",
					SDL_GetError());
				return SDL_FALSE;
			}
			SDL_GetWindowSize(state->windows[i], &w, &h);
			if (!(state->window_flags & SDL_WINDOW_RESIZABLE) &&
				(w != state->window_w || h != state->window_h)) {
					printf("Window requested size %dx%d, got %dx%d\n", state->window_w, state->window_h, w, h);
					state->window_w = w;
					state->window_h = h;
			}
			if (SDL_SetWindowDisplayMode(state->windows[i], &fullscreen_mode) < 0) {
				fprintf(stderr, "Can't set up fullscreen display mode: %s\n",
					SDL_GetError());
				return SDL_FALSE;
			}

			if (state->window_icon) {
				SDL_Surface *icon = LoadIcon(state->window_icon);
				if (icon) {
					SDL_SetWindowIcon(state->windows[i], icon);
					SDL_FreeSurface(icon);
				}
			}

			SDL_ShowWindow(state->windows[i]);

			state->renderers[i] = NULL;

			if (!state->skip_renderer
				&& (state->renderdriver
				|| !(state->window_flags & SDL_WINDOW_OPENGL))) {
					m = -1;
					if (state->renderdriver) {
						SDL_RendererInfo info;
						n = SDL_GetNumRenderDrivers();
						for (j = 0; j < n; ++j) {
							SDL_GetRenderDriverInfo(j, &info);
							if (SDL_strcasecmp(info.name, state->renderdriver) ==
								0) {
									m = j;
									break;
							}
						}
						if (m == n) {
							fprintf(stderr,
								"Couldn't find render driver named %s",
								state->renderdriver);
							return SDL_FALSE;
						}
					}
					state->renderers[i] = SDL_CreateRenderer(state->windows[i],
						m, state->render_flags);
					if (!state->renderers[i]) {
						fprintf(stderr, "Couldn't create renderer: %s\n",
							SDL_GetError());
						return SDL_FALSE;
					}
					if (state->verbose & VERBOSE_RENDER) {
						SDL_RendererInfo info;

						fprintf(stderr, "Current renderer:\n");
						SDL_GetRendererInfo(state->renderers[i], &info);
						PrintRenderer(&info);
					}
			}
		}
	}

	return SDL_TRUE;
}

void ShooterScreen :: CommonQuit(CommonState * state)
{
	int i;

	if (state->windows) {
		SDL_free(state->windows);
	}
	if (state->renderers) {
		for (i = 0; i < state->num_windows; ++i) {
			if (state->renderers[i] != 0) {
				SDL_DestroyRenderer(state->renderers[i]);
			}
		}
		SDL_free(state->renderers);
	}

	SDL_VideoQuit();

	SDL_free(state);

	printf ("Screen Delete OK.\n");
}

void ShooterScreen :: PrintRenderer(SDL_RendererInfo * info)
{
	int i, count;

	fprintf(stderr, "  Renderer %s:\n", info->name);

	fprintf(stderr, "    Flags: 0x%8.8X", info->flags);
	fprintf(stderr, " (");
	count = 0;
	for (i = 0; i < sizeof(info->flags) * 8; ++i) {
		Uint32 flag = (1 << i);
		if (info->flags & flag) {
			if (count > 0) {
				fprintf(stderr, " | ");
			}
			PrintRendererFlag(flag);
			++count;
		}
	}
	fprintf(stderr, ")\n");

	fprintf(stderr, "    Texture formats (%d): ", info->num_texture_formats);
	for (i = 0; i < (int) info->num_texture_formats; ++i) {
		if (i > 0) {
			fprintf(stderr, ", ");
		}
		PrintPixelFormat(info->texture_formats[i]);
	}
	fprintf(stderr, "\n");

	if (info->max_texture_width || info->max_texture_height) {
		fprintf(stderr, "    Max Texture Size: %dx%d\n",
			info->max_texture_width, info->max_texture_height);
	}
}

void ShooterScreen :: PrintRendererFlag(Uint32 flag)
{
	switch (flag) {
	case SDL_RENDERER_PRESENTVSYNC:
		fprintf(stderr, "PresentVSync");
		break;
	case SDL_RENDERER_ACCELERATED:
		fprintf(stderr, "Accelerated");
		break;
	default:
		fprintf(stderr, "0x%8.8x", flag);
		break;
	}
}

void ShooterScreen :: PrintPixelFormat(Uint32 format)
{
	switch (format) {
	case SDL_PIXELFORMAT_UNKNOWN:
		fprintf(stderr, "Unknwon");
		break;
	case SDL_PIXELFORMAT_INDEX1LSB:
		fprintf(stderr, "Index1LSB");
		break;
	case SDL_PIXELFORMAT_INDEX1MSB:
		fprintf(stderr, "Index1MSB");
		break;
	case SDL_PIXELFORMAT_INDEX4LSB:
		fprintf(stderr, "Index4LSB");
		break;
	case SDL_PIXELFORMAT_INDEX4MSB:
		fprintf(stderr, "Index4MSB");
		break;
	case SDL_PIXELFORMAT_INDEX8:
		fprintf(stderr, "Index8");
		break;
	case SDL_PIXELFORMAT_RGB332:
		fprintf(stderr, "RGB332");
		break;
	case SDL_PIXELFORMAT_RGB444:
		fprintf(stderr, "RGB444");
		break;
	case SDL_PIXELFORMAT_RGB555:
		fprintf(stderr, "RGB555");
		break;
	case SDL_PIXELFORMAT_BGR555:
		fprintf(stderr, "BGR555");
		break;
	case SDL_PIXELFORMAT_ARGB4444:
		fprintf(stderr, "ARGB4444");
		break;
	case SDL_PIXELFORMAT_ABGR4444:
		fprintf(stderr, "ABGR4444");
		break;
	case SDL_PIXELFORMAT_ARGB1555:
		fprintf(stderr, "ARGB1555");
		break;
	case SDL_PIXELFORMAT_ABGR1555:
		fprintf(stderr, "ABGR1555");
		break;
	case SDL_PIXELFORMAT_RGB565:
		fprintf(stderr, "RGB565");
		break;
	case SDL_PIXELFORMAT_BGR565:
		fprintf(stderr, "BGR565");
		break;
	case SDL_PIXELFORMAT_RGB24:
		fprintf(stderr, "RGB24");
		break;
	case SDL_PIXELFORMAT_BGR24:
		fprintf(stderr, "BGR24");
		break;
	case SDL_PIXELFORMAT_RGB888:
		fprintf(stderr, "RGB888");
		break;
	case SDL_PIXELFORMAT_BGR888:
		fprintf(stderr, "BGR888");
		break;
	case SDL_PIXELFORMAT_ARGB8888:
		fprintf(stderr, "ARGB8888");
		break;
	case SDL_PIXELFORMAT_RGBA8888:
		fprintf(stderr, "RGBA8888");
		break;
	case SDL_PIXELFORMAT_ABGR8888:
		fprintf(stderr, "ABGR8888");
		break;
	case SDL_PIXELFORMAT_BGRA8888:
		fprintf(stderr, "BGRA8888");
		break;
	case SDL_PIXELFORMAT_ARGB2101010:
		fprintf(stderr, "ARGB2101010");
		break;
	case SDL_PIXELFORMAT_YV12:
		fprintf(stderr, "YV12");
		break;
	case SDL_PIXELFORMAT_IYUV:
		fprintf(stderr, "IYUV");
		break;
	case SDL_PIXELFORMAT_YUY2:
		fprintf(stderr, "YUY2");
		break;
	case SDL_PIXELFORMAT_UYVY:
		fprintf(stderr, "UYVY");
		break;
	case SDL_PIXELFORMAT_YVYU:
		fprintf(stderr, "YVYU");
		break;
	default:
		fprintf(stderr, "0x%8.8x", format);
		break;
	}
}

SDL_Surface *	ShooterScreen :: LoadIcon(const char *file)
{
	SDL_Surface *icon;

	/* Load the icon surface */
	icon = SDL_LoadBMP(file);
	if (icon == NULL) {
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return (NULL);
	}

	if (icon->format->palette) {
		/* Set the colorkey */
		SDL_SetColorKey(icon, 1, *((Uint8 *) icon->pixels));
	}

	return (icon);
}
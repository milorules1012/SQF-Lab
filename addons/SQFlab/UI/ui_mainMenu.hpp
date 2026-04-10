/*
	SQF Lab — main menu dialog (SQFLab_MainMenu).
	Implemented entries only: Light sources, Markers, Particles.
*/
#ifndef SQFLAB_UI_MAINMENU_HPP
#define SQFLAB_UI_MAINMENU_HPP

#include "\SQFLab\UI\ui_mainMenu_controls.hpp"

#define SQFLAB_MM_PROFILE_COLOR(a) { "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.3843])", "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.7019])", "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.8862])", a }

/* Panel placement (safe zone coordinates) */
#define SQFLAB_MM_PANEL_W 0.38
#define SQFLAB_MM_PANEL_H 0.28
#define SQFLAB_MM_PANEL_X (safeZoneX + (safeZoneW - SQFLAB_MM_PANEL_W) * 0.5)
#define SQFLAB_MM_PANEL_Y (safeZoneY + (safeZoneH - SQFLAB_MM_PANEL_H) * 0.5)

/* Inner layout (absolute screen units, derived from panel placement) */
#define SQFLAB_MM_PAD_SIDE 0.014
#define SQFLAB_MM_PAD_TOP 0.012
#define SQFLAB_MM_TITLE_H 0.05
#define SQFLAB_MM_AFTER_TITLE_GAP 0.010
#define SQFLAB_MM_BTN_H 0.046
#define SQFLAB_MM_BTN_GAP 0.006
#define SQFLAB_MM_BTN_W (SQFLAB_MM_PANEL_W - (SQFLAB_MM_PAD_SIDE * 2))

#define SQFLAB_MM_Y_FIRST_BTN (SQFLAB_MM_PANEL_Y + SQFLAB_MM_PAD_TOP + SQFLAB_MM_TITLE_H + SQFLAB_MM_AFTER_TITLE_GAP)
#define SQFLAB_MM_Y_LIGHTSOURCES SQFLAB_MM_Y_FIRST_BTN
#define SQFLAB_MM_Y_MARKERS (SQFLAB_MM_Y_LIGHTSOURCES + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_PARTICLES (SQFLAB_MM_Y_MARKERS + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)

class SQFLab_MainMenu
{
	idd = SQFLAB_MM_IDD;
	movingEnable = 0;
	enableSimulation = 1;
	enableDisplay = 1;

	class controlsBackground
	{
		class Veil: RscText
		{
			idc = -1;
			x = "safeZoneXAbs";
			y = "safeZoneY";
			w = "safeZoneWAbs";
			h = "safeZoneH";
			colorBackground[] = { 0, 0, 0, 0.45 };
		};
	};

	class controls
	{
		class Background: RscText
		{
			idc = -1;
			x = SQFLAB_MM_PANEL_X;
			y = SQFLAB_MM_PANEL_Y;
			w = SQFLAB_MM_PANEL_W;
			h = SQFLAB_MM_PANEL_H;
			colorBackground[] = {0.10, 0.10, 0.10, 0.95};
		};

		class Title: RscText
		{
			idc = -1;
			x = SQFLAB_MM_PANEL_X + SQFLAB_MM_PAD_SIDE;
			y = SQFLAB_MM_PANEL_Y + SQFLAB_MM_PAD_TOP;
			w = SQFLAB_MM_BTN_W;
			h = SQFLAB_MM_TITLE_H;
			text = $STR_SQFLAB_Main_Title;
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_MM_PROFILE_COLOR(0.9);
			colorText[] = { 1, 1, 1, 1 };
		};

		class BtnLightSources: RscButtonMenu
		{
			idc = SQFLAB_MM_IDC_BTN_LIGHTSOURCES;
			x = SQFLAB_MM_PANEL_X + SQFLAB_MM_PAD_SIDE;
			y = SQFLAB_MM_Y_LIGHTSOURCES;
			w = SQFLAB_MM_BTN_W;
			h = SQFLAB_MM_BTN_H;
			text = $STR_SQFLAB_Main_LightSources;
			colorBackground[] = SQFLAB_MM_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_MM_PROFILE_COLOR(1);
			action = "[] call SQFLab_fnc_lightsMenu";
		};

		class BtnMarkers: BtnLightSources
		{
			idc = SQFLAB_MM_IDC_BTN_MARKERS;
			y = SQFLAB_MM_Y_MARKERS;
			text = $STR_SQFLAB_Main_Markers;
			action = "[] call SQFLab_fnc_markersMenu";
		};

		class BtnParticles: BtnLightSources
		{
			idc = SQFLAB_MM_IDC_BTN_PARTICLES;
			y = SQFLAB_MM_Y_PARTICLES;
			text = $STR_SQFLAB_Main_Particles;
			action = "[] call SQFLab_fnc_particlesMenu";
		};
	};
};

#endif

/*
	SQF Lab — main menu dialog (SQFLab_MainMenu).
	Button order: alphabetical. Y positions chain off SQFLAB_MM_Y_FIRST_BTN using
	SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP for each step down.
*/
#ifndef SQFLAB_UI_MAINMENU_HPP
#define SQFLAB_UI_MAINMENU_HPP

#define SQFLAB_MM_IDD 86540

#define SQFLAB_MM_IDC_BTN_ANIMATIONS 86541
#define SQFLAB_MM_IDC_BTN_ATTACHTO 86542
#define SQFLAB_MM_IDC_BTN_CAMERA 86543
#define SQFLAB_MM_IDC_BTN_DRAWICON3D 86544
#define SQFLAB_MM_IDC_BTN_LIGHTSOURCES 86545
#define SQFLAB_MM_IDC_BTN_MARKERS 86546
#define SQFLAB_MM_IDC_BTN_PARTICLES 86547
#define SQFLAB_MM_IDC_BTN_SELECTIONVIEWER 86548
#define SQFLAB_MM_IDC_BTN_TURRET 86549
#define SQFLAB_MM_IDC_BTN_UIEDITOR 86550
#define SQFLAB_MM_IDC_BTN_WEATHER 86551

#define SQFLAB_MM_PROFILE_COLOR(a) { "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.3843])", "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.7019])", "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.8862])", a }

/* Panel placement (safe zone coordinates) */
#define SQFLAB_MM_PANEL_W 0.38
#define SQFLAB_MM_PANEL_H 0.78
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

/* First row = below title + gap; each next row moves down by (button height + gap). */
#define SQFLAB_MM_Y_FIRST_BTN (SQFLAB_MM_PANEL_Y + SQFLAB_MM_PAD_TOP + SQFLAB_MM_TITLE_H + SQFLAB_MM_AFTER_TITLE_GAP)

#define SQFLAB_MM_Y_ANIMATIONS SQFLAB_MM_Y_FIRST_BTN
#define SQFLAB_MM_Y_ATTACHTO (SQFLAB_MM_Y_ANIMATIONS + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_CAMERA (SQFLAB_MM_Y_ATTACHTO + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_DRAWICON3D (SQFLAB_MM_Y_CAMERA + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_LIGHTSOURCES (SQFLAB_MM_Y_DRAWICON3D + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_MARKERS (SQFLAB_MM_Y_LIGHTSOURCES + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_PARTICLES (SQFLAB_MM_Y_MARKERS + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_SELECTIONVIEWER (SQFLAB_MM_Y_PARTICLES + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_TURRET (SQFLAB_MM_Y_SELECTIONVIEWER + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_UIEDITOR (SQFLAB_MM_Y_TURRET + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)
#define SQFLAB_MM_Y_WEATHER (SQFLAB_MM_Y_UIEDITOR + SQFLAB_MM_BTN_H + SQFLAB_MM_BTN_GAP)

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
			text = "SQF Lab";
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_MM_PROFILE_COLOR(0.9);
			colorText[] = { 1, 1, 1, 1 };
		};

		class BtnAnimations: RscButtonMenu
		{
			idc = SQFLAB_MM_IDC_BTN_ANIMATIONS;
			x = SQFLAB_MM_PANEL_X + SQFLAB_MM_PAD_SIDE;
			y = SQFLAB_MM_Y_ANIMATIONS;
			w = SQFLAB_MM_BTN_W;
			h = SQFLAB_MM_BTN_H;
			text = "Animations";
			colorBackground[] = SQFLAB_MM_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_MM_PROFILE_COLOR(1);
			tooltip = "";
			action = "";
		};

		class BtnAttachTo: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_ATTACHTO;
			y = SQFLAB_MM_Y_ATTACHTO;
			text = "AttachTo";
		};

		class BtnCamera: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_CAMERA;
			y = SQFLAB_MM_Y_CAMERA;
			text = "Camera";
		};

		class BtnDrawIcon3D: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_DRAWICON3D;
			y = SQFLAB_MM_Y_DRAWICON3D;
			text = "DrawIcon3D";
		};

		class BtnLightSources: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_LIGHTSOURCES;
			y = SQFLAB_MM_Y_LIGHTSOURCES;
			text = "Light sources";
		};

		class BtnMarkers: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_MARKERS;
			y = SQFLAB_MM_Y_MARKERS;
			text = "Markers";
		};

		class BtnParticles: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_PARTICLES;
			y = SQFLAB_MM_Y_PARTICLES;
			text = "Particles";
			action = "[] call SQFLab_fnc_particlesMenu";
		};

		class BtnSelectionViewer: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_SELECTIONVIEWER;
			y = SQFLAB_MM_Y_SELECTIONVIEWER;
			text = "Selection viewer";
		};

		class BtnTurret: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_TURRET;
			y = SQFLAB_MM_Y_TURRET;
			text = "Turret";
		};

		class BtnUIEditor: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_UIEDITOR;
			y = SQFLAB_MM_Y_UIEDITOR;
			text = "UI editor";
		};

		class BtnWeather: BtnAnimations
		{
			idc = SQFLAB_MM_IDC_BTN_WEATHER;
			y = SQFLAB_MM_Y_WEATHER;
			text = "Weather";
		};
	};
};

#endif

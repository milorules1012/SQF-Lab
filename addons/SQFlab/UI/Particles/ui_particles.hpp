#ifndef SQFLAB_UI_PARTICLES_HPP
#define SQFLAB_UI_PARTICLES_HPP

#include "\SQFLab\UI\Particles\ui_particles_controls.hpp"

#define SQFLAB_PROFILE_COLOR(a) { "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.3843])", "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.7019])", "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.8862])", a }

#define SQFLAB_PANEL_W 0.68
#define SQFLAB_PANEL_H 1.06
#define SQFLAB_PANEL_GAP 0.02
#define SQFLAB_TOTAL_W ((SQFLAB_PANEL_W * 2) + SQFLAB_PANEL_GAP)
#define SQFLAB_PANEL_X (safeZoneX + ((safeZoneW - SQFLAB_TOTAL_W) * 0.5) + SQFLAB_PANEL_W + SQFLAB_PANEL_GAP)
#define SQFLAB_PANEL_Y (safeZoneY + (safeZoneH - SQFLAB_PANEL_H) * 0.5)
#define SQFLAB_PREVIEW_X (SQFLAB_PANEL_X - SQFLAB_PANEL_GAP - SQFLAB_PANEL_W)
#define SQFLAB_PREVIEW_Y SQFLAB_PANEL_Y

#define SQFLAB_PAD_SIDE 0.015
#define SQFLAB_PAD_TOP 0.012
#define SQFLAB_TITLE_H 0.05
#define SQFLAB_SECTION_H 0.03
#define SQFLAB_ROW_H 0.04
#define SQFLAB_ROW_GAP 0.008
#define SQFLAB_SECTION_GAP 0.008
#define SQFLAB_BOTTOM_GAP 0.050

#define SQFLAB_LABEL_W 0.20
#define SQFLAB_VALUE_W 0.08
#define SQFLAB_SLIDER_W (SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2) - SQFLAB_LABEL_W - SQFLAB_VALUE_W - 0.02)
#define SQFLAB_SLIDER_X (SQFLAB_PANEL_X + SQFLAB_PAD_SIDE + SQFLAB_LABEL_W + 0.012)
#define SQFLAB_VALUE_X (SQFLAB_SLIDER_X + SQFLAB_SLIDER_W + 0.008)

#define SQFLAB_Y_TYPE_TITLE (SQFLAB_PANEL_Y + SQFLAB_PAD_TOP + SQFLAB_TITLE_H + SQFLAB_SECTION_GAP)
#define SQFLAB_Y_TYPE_ROW (SQFLAB_Y_TYPE_TITLE + SQFLAB_SECTION_H + 0.006)
#define SQFLAB_Y_COLORS_TITLE (SQFLAB_Y_TYPE_ROW + SQFLAB_ROW_H + SQFLAB_SECTION_GAP)
#define SQFLAB_Y_COLOR_PREVIEW (SQFLAB_Y_COLORS_TITLE + SQFLAB_SECTION_H + 0.006)
#define SQFLAB_Y_COLOR_R (SQFLAB_Y_COLOR_PREVIEW + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_COLOR_G (SQFLAB_Y_COLOR_R + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_COLOR_B (SQFLAB_Y_COLOR_G + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_COLOR_A (SQFLAB_Y_COLOR_B + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_PARAMS_TITLE (SQFLAB_Y_COLOR_A + SQFLAB_ROW_H + SQFLAB_SECTION_GAP)

#define SQFLAB_Y_FIRST (SQFLAB_Y_PARAMS_TITLE + SQFLAB_SECTION_H + 0.006)
#define SQFLAB_Y_SIZE SQFLAB_Y_FIRST
#define SQFLAB_Y_LIFETIME (SQFLAB_Y_SIZE + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_INTERVAL (SQFLAB_Y_LIFETIME + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_MOVEVEL (SQFLAB_Y_INTERVAL + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_ROTVEL (SQFLAB_Y_MOVEVEL + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_WEIGHT (SQFLAB_Y_ROTVEL + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_VOLUME (SQFLAB_Y_WEIGHT + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_Y_RUBBING (SQFLAB_Y_VOLUME + SQFLAB_ROW_H + SQFLAB_ROW_GAP)
#define SQFLAB_BTN_W 0.16
#define SQFLAB_BTN_GAP 0.01
#define SQFLAB_Y_BOTTOM_BTN (SQFLAB_PANEL_Y + SQFLAB_PANEL_H - SQFLAB_PAD_TOP - 0.04)

class SQFLab_ParticlesMenu
{
	idd = SQFLAB_IDD;
	movingEnable = 0;
	enableSimulation = 1;
	enableDisplay = 1;
	onLoad = "_this call SQFLab_fnc_particlesInit";
	onUnload = "_this call SQFLab_fnc_particlesCleanup";

	class controlsBackground
	{
		class Veil: RscText
		{
			idc = -1;
			x = "safeZoneXAbs";
			y = "safeZoneY";
			w = "safeZoneWAbs";
			h = "safeZoneH";
			colorBackground[] = {0, 0, 0, 0.45};
		};

		class Background: RscText
		{
			idc = -1;
			x = SQFLAB_PANEL_X;
			y = SQFLAB_PANEL_Y;
			w = SQFLAB_PANEL_W;
			h = SQFLAB_PANEL_H;
			colorBackground[] = {0.10, 0.10, 0.10, 0.95};
		};
		class PreviewBackground: Background
		{
			x = SQFLAB_PREVIEW_X;
			y = SQFLAB_PREVIEW_Y;
		};
	};

	class controls
	{
		class PreviewTitle: RscText
		{
			idc = SQFLAB_IDC_PREVIEW_TITLE;
			x = SQFLAB_PREVIEW_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_PREVIEW_Y + SQFLAB_PAD_TOP;
			w = SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2);
			h = SQFLAB_TITLE_H;
			text = $STR_SQFLAB_Common_Preview;
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.9);
			colorText[] = {1, 1, 1, 1};
		};
		class PreviewPicture: RscPicture
		{
			idc = SQFLAB_IDC_PREVIEW_PICTURE;
			x = SQFLAB_PREVIEW_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_PREVIEW_Y + SQFLAB_PAD_TOP + SQFLAB_TITLE_H + SQFLAB_SECTION_GAP;
			w = SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2);
			h = SQFLAB_PANEL_H - (SQFLAB_PAD_TOP * 2) - SQFLAB_TITLE_H - SQFLAB_SECTION_GAP;
			text = "";
		};

		class Title: RscText
		{
			idc = -1;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_PANEL_Y + SQFLAB_PAD_TOP;
			w = SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2);
			h = SQFLAB_TITLE_H;
			text = $STR_SQFLAB_Particles_Title;
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.9);
			colorText[] = {1, 1, 1, 1};
		};

		class BtnFire: RscButtonMenu
		{
			idc = SQFLAB_IDC_BTN_FIRE;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_Y_TYPE_ROW;
			w = 0.12;
			h = 0.036;
			text = $STR_SQFLAB_Particles_Fire;
			action = "uiNamespace setVariable ['SQFLab_particles_previewType','fire']; [] call SQFLab_fnc_particlesOnSlider;";
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_PROFILE_COLOR(1);
		};
		class BtnSmoke: BtnFire
		{
			idc = SQFLAB_IDC_BTN_SMOKE;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE + 0.13;
			text = $STR_SQFLAB_Particles_Smoke;
			action = "uiNamespace setVariable ['SQFLab_particles_previewType','smoke']; [] call SQFLab_fnc_particlesOnSlider;";
		};
		class BtnDrop: BtnFire
		{
			idc = SQFLAB_IDC_BTN_DROP;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE + 0.26;
			text = $STR_SQFLAB_Particles_Drop;
			action = "uiNamespace setVariable ['SQFLab_particles_previewType','drop']; [] call SQFLab_fnc_particlesOnSlider;";
		};

		class TypeTitle: RscText
		{
			idc = -1;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_Y_TYPE_TITLE;
			w = SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2);
			h = SQFLAB_SECTION_H;
			text = $STR_SQFLAB_Particles_TypeTitle;
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.35);
		};

		class ParamsTitle: RscText
		{
			idc = -1;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_Y_PARAMS_TITLE;
			w = SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2);
			h = SQFLAB_SECTION_H;
			text = $STR_SQFLAB_Particles_ParamsTitle;
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.35);
		};

		class ColorsTitle: RscText
		{
			idc = -1;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_Y_COLORS_TITLE;
			w = SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2);
			h = SQFLAB_SECTION_H;
			text = $STR_SQFLAB_Particles_ColorsTitle;
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.35);
		};

		class LabelSize: RscText
		{
			idc = -1;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_Y_SIZE;
			w = SQFLAB_LABEL_W;
			h = SQFLAB_ROW_H;
			text = $STR_SQFLAB_Particles_Size;
			colorBackground[] = {0, 0, 0, 0};
		};
		class SliderSize: RscSlider
		{
			idc = SQFLAB_IDC_SLIDER_SIZE;
			x = SQFLAB_SLIDER_X;
			y = SQFLAB_Y_SIZE;
			w = SQFLAB_SLIDER_W;
			h = SQFLAB_ROW_H;
			type = 43; // CT_XSLIDER
			style = 1024; // SL_HORZ + SL_TEXTURES
			color[] = {1, 1, 1, 0.6};
			colorActive[] = {1, 1, 1, 1};
			colorDisable[] = {1, 1, 1, 0.4};
			colorDisabled[] = {1, 1, 1, 0.2};
			shadow = 0;
			lineSize = 0.1;
			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
			thumb = "\a3\3DEN\Data\Controls\CtrlXSlider\thumb_ca.paa";
			tooltipColorText[] = {1, 1, 1, 1};
			tooltipColorBox[] = {1, 1, 1, 1};
			tooltipColorShade[] = {0, 0, 0, 0.65};
			onSliderPosChanged = "_this call SQFLab_fnc_particlesOnSlider";
		};
		class ValueSize: LabelSize
		{
			idc = SQFLAB_IDC_VALUE_SIZE;
			x = SQFLAB_VALUE_X;
			w = SQFLAB_VALUE_W;
			style = 1;
			text = "0";
		};

		class LabelLifeTime: LabelSize { y = SQFLAB_Y_LIFETIME; text = $STR_SQFLAB_Particles_LifeTime; };
		class SliderLifeTime: SliderSize { idc = SQFLAB_IDC_SLIDER_LIFETIME; y = SQFLAB_Y_LIFETIME; };
		class ValueLifeTime: ValueSize { idc = SQFLAB_IDC_VALUE_LIFETIME; y = SQFLAB_Y_LIFETIME; };

		class LabelInterval: LabelSize { y = SQFLAB_Y_INTERVAL; text = $STR_SQFLAB_Particles_SpawnInterval; };
		class SliderInterval: SliderSize { idc = SQFLAB_IDC_SLIDER_INTERVAL; y = SQFLAB_Y_INTERVAL; };
		class ValueInterval: ValueSize { idc = SQFLAB_IDC_VALUE_INTERVAL; y = SQFLAB_Y_INTERVAL; };

		class LabelMoveVel: LabelSize { y = SQFLAB_Y_MOVEVEL; text = $STR_SQFLAB_Particles_MoveVelocity; };
		class SliderMoveVel: SliderSize { idc = SQFLAB_IDC_SLIDER_MOVEVEL; y = SQFLAB_Y_MOVEVEL; };
		class ValueMoveVel: ValueSize { idc = SQFLAB_IDC_VALUE_MOVEVEL; y = SQFLAB_Y_MOVEVEL; };

		class LabelRotVel: LabelSize { y = SQFLAB_Y_ROTVEL; text = $STR_SQFLAB_Particles_RotationVelocity; };
		class SliderRotVel: SliderSize { idc = SQFLAB_IDC_SLIDER_ROTVEL; y = SQFLAB_Y_ROTVEL; };
		class ValueRotVel: ValueSize { idc = SQFLAB_IDC_VALUE_ROTVEL; y = SQFLAB_Y_ROTVEL; };

		class LabelWeight: LabelSize { y = SQFLAB_Y_WEIGHT; text = $STR_SQFLAB_Particles_Weight; };
		class SliderWeight: SliderSize { idc = SQFLAB_IDC_SLIDER_WEIGHT; y = SQFLAB_Y_WEIGHT; };
		class ValueWeight: ValueSize { idc = SQFLAB_IDC_VALUE_WEIGHT; y = SQFLAB_Y_WEIGHT; };

		class LabelVolume: LabelSize { y = SQFLAB_Y_VOLUME; text = $STR_SQFLAB_Particles_Volume; };
		class SliderVolume: SliderSize { idc = SQFLAB_IDC_SLIDER_VOLUME; y = SQFLAB_Y_VOLUME; };
		class ValueVolume: ValueSize { idc = SQFLAB_IDC_VALUE_VOLUME; y = SQFLAB_Y_VOLUME; };

		class LabelRubbing: LabelSize { y = SQFLAB_Y_RUBBING; text = $STR_SQFLAB_Particles_Rubbing; };
		class SliderRubbing: SliderSize { idc = SQFLAB_IDC_SLIDER_RUBBING; y = SQFLAB_Y_RUBBING; };
		class ValueRubbing: ValueSize { idc = SQFLAB_IDC_VALUE_RUBBING; y = SQFLAB_Y_RUBBING; };

		class LabelColorR: LabelSize { y = SQFLAB_Y_COLOR_R; text = $STR_SQFLAB_Common_ColorR; };
		class SliderColorR: SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_R; y = SQFLAB_Y_COLOR_R; };
		class ValueColorR: ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_R; y = SQFLAB_Y_COLOR_R; };

		class LabelColorG: LabelSize { y = SQFLAB_Y_COLOR_G; text = $STR_SQFLAB_Common_ColorG; };
		class SliderColorG: SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_G; y = SQFLAB_Y_COLOR_G; };
		class ValueColorG: ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_G; y = SQFLAB_Y_COLOR_G; };

		class LabelColorB: LabelSize { y = SQFLAB_Y_COLOR_B; text = $STR_SQFLAB_Common_ColorB; };
		class SliderColorB: SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_B; y = SQFLAB_Y_COLOR_B; };
		class ValueColorB: ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_B; y = SQFLAB_Y_COLOR_B; };

		class LabelColorA: LabelSize { y = SQFLAB_Y_COLOR_A; text = $STR_SQFLAB_Common_ColorA; };
		class SliderColorA: SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_A; y = SQFLAB_Y_COLOR_A; };
		class ValueColorA: ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_A; y = SQFLAB_Y_COLOR_A; };

		class ColorPreview: RscButtonMenu
		{
			idc = SQFLAB_IDC_COLOR_PREVIEW;
			x = SQFLAB_PANEL_X + SQFLAB_PAD_SIDE;
			y = SQFLAB_Y_COLOR_PREVIEW;
			w = SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2);
			h = SQFLAB_ROW_H;
			text = $STR_SQFLAB_Common_ColorPreview;
			style = 2;
			action = "";
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_PROFILE_COLOR(0.9);
		};

		class CloseBtn: RscButtonMenu
		{
			idc = SQFLAB_IDC_BTN_CLOSE;
			x = SQFLAB_PANEL_X + SQFLAB_PANEL_W - SQFLAB_PAD_SIDE - SQFLAB_BTN_W;
			y = SQFLAB_Y_BOTTOM_BTN;
			w = SQFLAB_BTN_W;
			h = 0.04;
			text = $STR_SQFLAB_Common_Close;
			action = "closeDialog 2";
			colorBackground[] = SQFLAB_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_PROFILE_COLOR(1);
		};
		class ExportBtn: CloseBtn
		{
			idc = SQFLAB_IDC_BTN_EXPORT;
			x = SQFLAB_PANEL_X + SQFLAB_PANEL_W - SQFLAB_PAD_SIDE - (SQFLAB_BTN_W * 3) - (SQFLAB_BTN_GAP * 2);
			w = SQFLAB_BTN_W;
			text = $STR_SQFLAB_Common_Export;
			action = "[] call SQFLab_fnc_particlesExport";
		};
		class HideUiBtn: CloseBtn
		{
			idc = SQFLAB_IDC_BTN_HIDE_UI;
			x = SQFLAB_PANEL_X + SQFLAB_PANEL_W - SQFLAB_PAD_SIDE - (SQFLAB_BTN_W * 2) - SQFLAB_BTN_GAP;
			w = SQFLAB_BTN_W;
			text = $STR_SQFLAB_Common_HideUI;
			action = "[] call SQFLab_fnc_particlesToggleUi";
		};
	};
};

#endif

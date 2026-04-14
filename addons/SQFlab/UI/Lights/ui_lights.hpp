#ifndef SQFLAB_UI_LIGHTS_HPP
#define SQFLAB_UI_LIGHTS_HPP

#include "\SQFLab\UI\Lights\ui_lights_controls.hpp"

#define SQFLAB_LT_PROFILE_COLOR(a) { "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.3843])", "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.7019])", "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.8862])", a }

#define SQFLAB_LT_PANEL_W 0.68
#define SQFLAB_LT_PANEL_H 1.28
#define SQFLAB_LT_PANEL_GAP 0.02
#define SQFLAB_LT_TOTAL_W ((SQFLAB_LT_PANEL_W * 2) + SQFLAB_LT_PANEL_GAP)
#define SQFLAB_LT_PANEL_X (safeZoneX + ((safeZoneW - SQFLAB_LT_TOTAL_W) * 0.5) + SQFLAB_LT_PANEL_W + SQFLAB_LT_PANEL_GAP)
#define SQFLAB_LT_PANEL_Y (safeZoneY + (safeZoneH - SQFLAB_LT_PANEL_H) * 0.5)
#define SQFLAB_LT_PREVIEW_X (SQFLAB_LT_PANEL_X - SQFLAB_LT_PANEL_GAP - SQFLAB_LT_PANEL_W)
#define SQFLAB_LT_PREVIEW_Y SQFLAB_LT_PANEL_Y

#define SQFLAB_LT_PAD_SIDE 0.015
#define SQFLAB_LT_PAD_TOP 0.012
#define SQFLAB_LT_TITLE_H 0.05
#define SQFLAB_LT_SECTION_H 0.03
#define SQFLAB_LT_ROW_H 0.04
#define SQFLAB_LT_ROW_GAP 0.008
#define SQFLAB_LT_SECTION_GAP 0.008
#define SQFLAB_LT_CHK_H 0.028
#define SQFLAB_LT_BTN_H 0.036

#define SQFLAB_LT_LABEL_W 0.20
#define SQFLAB_LT_VALUE_W 0.08
#define SQFLAB_LT_LABEL_SIZEEX 0.032
#define SQFLAB_LT_SLIDER_W (SQFLAB_LT_PANEL_W - (SQFLAB_LT_PAD_SIDE * 2) - SQFLAB_LT_LABEL_W - SQFLAB_LT_VALUE_W - 0.02)
#define SQFLAB_LT_SLIDER_X (SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE + SQFLAB_LT_LABEL_W + 0.012)
#define SQFLAB_LT_VALUE_X (SQFLAB_LT_SLIDER_X + SQFLAB_LT_SLIDER_W + 0.008)

#define SQFLAB_LT_Y_TYPE_TITLE (SQFLAB_LT_PANEL_Y + SQFLAB_LT_PAD_TOP + SQFLAB_LT_TITLE_H + SQFLAB_LT_SECTION_GAP)
#define SQFLAB_LT_Y_TYPE_ROW (SQFLAB_LT_Y_TYPE_TITLE + SQFLAB_LT_SECTION_H + 0.006)
#define SQFLAB_LT_Y_XFORM_TITLE (SQFLAB_LT_Y_TYPE_ROW + SQFLAB_LT_BTN_H + SQFLAB_LT_SECTION_GAP)
#define SQFLAB_LT_Y_POS_EDIT (SQFLAB_LT_Y_XFORM_TITLE + SQFLAB_LT_SECTION_H + 0.006)
#define SQFLAB_LT_Y_DIR (SQFLAB_LT_Y_POS_EDIT + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_UP (SQFLAB_LT_Y_DIR + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_COL_TITLE (SQFLAB_LT_Y_UP + SQFLAB_LT_ROW_H + SQFLAB_LT_SECTION_GAP)
#define SQFLAB_LT_Y_COL_PREVIEW (SQFLAB_LT_Y_COL_TITLE + SQFLAB_LT_SECTION_H + 0.006)
#define SQFLAB_LT_Y_COL_R (SQFLAB_LT_Y_COL_PREVIEW + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_COL_G (SQFLAB_LT_Y_COL_R + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_COL_B (SQFLAB_LT_Y_COL_G + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_AMB_R (SQFLAB_LT_Y_COL_B + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_AMB_G (SQFLAB_LT_Y_AMB_R + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_AMB_B (SQFLAB_LT_Y_AMB_G + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_INTENSITY (SQFLAB_LT_Y_AMB_B + SQFLAB_LT_ROW_H + SQFLAB_LT_SECTION_GAP)
#define SQFLAB_LT_Y_FLARE_TITLE (SQFLAB_LT_Y_INTENSITY + SQFLAB_LT_ROW_H + SQFLAB_LT_SECTION_GAP)
#define SQFLAB_LT_Y_FLARE_CHK (SQFLAB_LT_Y_FLARE_TITLE + SQFLAB_LT_SECTION_H + 0.006)
#define SQFLAB_LT_Y_FLARE_SIZE (SQFLAB_LT_Y_FLARE_CHK + SQFLAB_LT_CHK_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_FLARE_MAX (SQFLAB_LT_Y_FLARE_SIZE + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_MISC_TITLE (SQFLAB_LT_Y_FLARE_MAX + SQFLAB_LT_ROW_H + SQFLAB_LT_SECTION_GAP)
#define SQFLAB_LT_Y_MISC_ROW (SQFLAB_LT_Y_MISC_TITLE + SQFLAB_LT_SECTION_H + 0.006)
#define SQFLAB_LT_Y_REFLECTOR_TITLE (SQFLAB_LT_Y_MISC_ROW + SQFLAB_LT_BTN_H + SQFLAB_LT_SECTION_GAP)
#define SQFLAB_LT_Y_CONE_OUT (SQFLAB_LT_Y_REFLECTOR_TITLE + SQFLAB_LT_SECTION_H + 0.006)
#define SQFLAB_LT_Y_CONE_IN (SQFLAB_LT_Y_CONE_OUT + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)
#define SQFLAB_LT_Y_CONE_COEF (SQFLAB_LT_Y_CONE_IN + SQFLAB_LT_ROW_H + SQFLAB_LT_ROW_GAP)

#define SQFLAB_LT_BTN_W 0.16
#define SQFLAB_LT_BTN_GAP 0.01
#define SQFLAB_LT_Y_BOTTOM_BTN (SQFLAB_LT_PANEL_Y + SQFLAB_LT_PANEL_H - SQFLAB_LT_PAD_TOP - 0.04)

class SQFLab_LightsMenu
{
	idd = SQFLAB_LT_IDD;
	movingEnable = 0;
	enableSimulation = 1;
	enableDisplay = 1;
	onLoad = "_this call SQFLab_fnc_lightsInit";
	onUnload = "_this call SQFLab_fnc_lightsCleanup";

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
			x = SQFLAB_LT_PANEL_X;
			y = SQFLAB_LT_PANEL_Y;
			w = SQFLAB_LT_PANEL_W;
			h = SQFLAB_LT_PANEL_H;
			colorBackground[] = {0.10, 0.10, 0.10, 0.95};
		};
		class PreviewBackground: Background
		{
			x = SQFLAB_LT_PREVIEW_X;
			y = SQFLAB_LT_PREVIEW_Y;
		};
	};

	class controls
	{
		class PreviewTitle: RscText
		{
			idc = SQFLAB_LT_IDC_PREVIEW_TITLE;
			x = SQFLAB_LT_PREVIEW_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_PREVIEW_Y + SQFLAB_LT_PAD_TOP;
			w = SQFLAB_LT_PANEL_W - (SQFLAB_LT_PAD_SIDE * 2);
			h = SQFLAB_LT_TITLE_H;
			text = $STR_SQFLAB_Common_Preview;
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_LT_PROFILE_COLOR(0.9);
			colorText[] = {1, 1, 1, 1};
		};
		class PreviewPicture: RscPicture
		{
			idc = SQFLAB_LT_IDC_PREVIEW_PICTURE;
			x = SQFLAB_LT_PREVIEW_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_PREVIEW_Y + SQFLAB_LT_PAD_TOP + SQFLAB_LT_TITLE_H + SQFLAB_LT_SECTION_GAP;
			w = SQFLAB_LT_PANEL_W - (SQFLAB_LT_PAD_SIDE * 2);
			h = SQFLAB_LT_PANEL_H - (SQFLAB_LT_PAD_TOP * 2) - SQFLAB_LT_TITLE_H - SQFLAB_LT_SECTION_GAP;
			text = "";
		};

		class Title: RscText
		{
			idc = -1;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_PANEL_Y + SQFLAB_LT_PAD_TOP;
			w = SQFLAB_LT_PANEL_W - (SQFLAB_LT_PAD_SIDE * 2);
			h = SQFLAB_LT_TITLE_H;
			text = $STR_SQFLAB_Lights_Title;
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_LT_PROFILE_COLOR(0.9);
			colorText[] = {1, 1, 1, 1};
		};

		class TypeTitle: RscText
		{
			idc = -1;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_Y_TYPE_TITLE;
			w = SQFLAB_LT_PANEL_W - (SQFLAB_LT_PAD_SIDE * 2);
			h = SQFLAB_LT_SECTION_H;
			text = $STR_SQFLAB_Lights_LightType;
			colorBackground[] = SQFLAB_LT_PROFILE_COLOR(0.35);
			sizeEx = SQFLAB_LT_LABEL_SIZEEX;
		};
		class BtnPoint: RscButtonMenu
		{
			idc = SQFLAB_LT_IDC_BTN_POINT;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_Y_TYPE_ROW;
			w = 0.14;
			h = SQFLAB_LT_BTN_H;
			text = $STR_SQFLAB_Lights_Point;
			action = "uiNamespace setVariable ['SQFLab_lights_type','point']; [] call SQFLab_fnc_lightsOnSlider;";
			colorBackground[] = SQFLAB_LT_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_LT_PROFILE_COLOR(1);
		};
		class BtnReflector: BtnPoint
		{
			idc = SQFLAB_LT_IDC_BTN_REFLECTOR;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE + 0.15;
			text = $STR_SQFLAB_Lights_Reflector;
			action = "uiNamespace setVariable ['SQFLab_lights_type','reflector']; [] call SQFLab_fnc_lightsOnSlider;";
		};

		class XformTitle: TypeTitle
		{
			y = SQFLAB_LT_Y_XFORM_TITLE;
			text = $STR_SQFLAB_Lights_Transform;
			tooltip = $STR_SQFLAB_Lights_Transform_Tooltip;
		};
		class LabelPos: RscText
		{
			idc = -1;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_Y_POS_EDIT;
			w = SQFLAB_LT_LABEL_W;
			h = SQFLAB_LT_ROW_H;
			text = $STR_SQFLAB_Lights_Position;
			sizeEx = SQFLAB_LT_LABEL_SIZEEX;
			colorBackground[] = {0, 0, 0, 0};
		};
		class EditPos: RscEdit
		{
			idc = SQFLAB_LT_IDC_EDIT_POS;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE + SQFLAB_LT_LABEL_W + 0.01;
			y = SQFLAB_LT_Y_POS_EDIT;
			w = SQFLAB_LT_PANEL_W - (SQFLAB_LT_PAD_SIDE * 2) - SQFLAB_LT_LABEL_W - 0.01;
			h = SQFLAB_LT_ROW_H;
			sizeEx = SQFLAB_LT_LABEL_SIZEEX;
			onKillFocus = "[] call SQFLab_fnc_lightsOnSlider";
			onKeyUp = "[] call SQFLab_fnc_lightsOnSlider";
		};

		class LabelDir: LabelPos { y = SQFLAB_LT_Y_DIR; text = $STR_SQFLAB_Lights_Dir; };
		class SliderDir: RscSlider
		{
			idc = SQFLAB_LT_IDC_SLIDER_DIR;
			x = SQFLAB_LT_SLIDER_X;
			y = SQFLAB_LT_Y_DIR;
			w = SQFLAB_LT_SLIDER_W;
			h = SQFLAB_LT_ROW_H;
			type = 43;
			style = 1024;
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
			onSliderPosChanged = "_this call SQFLab_fnc_lightsOnSlider";
		};
		class ValueDir: LabelPos
		{
			idc = SQFLAB_LT_IDC_VALUE_DIR;
			x = SQFLAB_LT_VALUE_X;
			w = SQFLAB_LT_VALUE_W;
			y = SQFLAB_LT_Y_DIR;
			style = 1;
			text = "0";
		};

		class LabelUp: LabelPos { y = SQFLAB_LT_Y_UP; text = $STR_SQFLAB_Lights_Up; };
		class SliderUp: SliderDir
		{
			idc = SQFLAB_LT_IDC_SLIDER_UP;
			y = SQFLAB_LT_Y_UP;
		};
		class ValueUp: ValueDir
		{
			idc = SQFLAB_LT_IDC_VALUE_UP;
			y = SQFLAB_LT_Y_UP;
		};

		class ColTitle: TypeTitle
		{
			y = SQFLAB_LT_Y_COL_TITLE;
			text = $STR_SQFLAB_Lights_Color;
		};
		class ColorPreview: RscButtonMenu
		{
			idc = SQFLAB_LT_IDC_COLOR_PREVIEW;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_Y_COL_PREVIEW;
			w = SQFLAB_LT_PANEL_W - (SQFLAB_LT_PAD_SIDE * 2);
			h = SQFLAB_LT_ROW_H;
			text = $STR_SQFLAB_Lights_LightColorPreview;
			style = 2;
			action = "";
			colorBackground[] = SQFLAB_LT_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_LT_PROFILE_COLOR(0.9);
		};

		class LabelColR: LabelPos { y = SQFLAB_LT_Y_COL_R; text = $STR_SQFLAB_Lights_LightR; };
		class SliderColR: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_COL_R; y = SQFLAB_LT_Y_COL_R; };
		class ValueColR: ValueDir { idc = SQFLAB_LT_IDC_VALUE_COL_R; y = SQFLAB_LT_Y_COL_R; };

		class LabelColG: LabelPos { y = SQFLAB_LT_Y_COL_G; text = $STR_SQFLAB_Lights_LightG; };
		class SliderColG: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_COL_G; y = SQFLAB_LT_Y_COL_G; };
		class ValueColG: ValueDir { idc = SQFLAB_LT_IDC_VALUE_COL_G; y = SQFLAB_LT_Y_COL_G; };

		class LabelColB: LabelPos { y = SQFLAB_LT_Y_COL_B; text = $STR_SQFLAB_Lights_LightB; };
		class SliderColB: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_COL_B; y = SQFLAB_LT_Y_COL_B; };
		class ValueColB: ValueDir { idc = SQFLAB_LT_IDC_VALUE_COL_B; y = SQFLAB_LT_Y_COL_B; };

		class LabelAmbR: LabelPos { y = SQFLAB_LT_Y_AMB_R; text = $STR_SQFLAB_Lights_AmbientR; };
		class SliderAmbR: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_AMB_R; y = SQFLAB_LT_Y_AMB_R; };
		class ValueAmbR: ValueDir { idc = SQFLAB_LT_IDC_VALUE_AMB_R; y = SQFLAB_LT_Y_AMB_R; };

		class LabelAmbG: LabelPos { y = SQFLAB_LT_Y_AMB_G; text = $STR_SQFLAB_Lights_AmbientG; };
		class SliderAmbG: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_AMB_G; y = SQFLAB_LT_Y_AMB_G; };
		class ValueAmbG: ValueDir { idc = SQFLAB_LT_IDC_VALUE_AMB_G; y = SQFLAB_LT_Y_AMB_G; };

		class LabelAmbB: LabelPos { y = SQFLAB_LT_Y_AMB_B; text = $STR_SQFLAB_Lights_AmbientB; };
		class SliderAmbB: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_AMB_B; y = SQFLAB_LT_Y_AMB_B; };
		class ValueAmbB: ValueDir { idc = SQFLAB_LT_IDC_VALUE_AMB_B; y = SQFLAB_LT_Y_AMB_B; };

		class LabelIntensity: LabelPos
		{
			y = SQFLAB_LT_Y_INTENSITY;
			text = $STR_SQFLAB_Lights_Power;
			tooltip = $STR_SQFLAB_Lights_Power_Tooltip;
		};
		class SliderIntensity: SliderDir
		{
			idc = SQFLAB_LT_IDC_SLIDER_INTENSITY;
			y = SQFLAB_LT_Y_INTENSITY;
		};
		class ValueIntensity: ValueDir
		{
			idc = SQFLAB_LT_IDC_VALUE_INTENSITY;
			y = SQFLAB_LT_Y_INTENSITY;
		};

		class FlareTitle: TypeTitle
		{
			y = SQFLAB_LT_Y_FLARE_TITLE;
			text = $STR_SQFLAB_Lights_FlareTitle;
		};
		class LabelFlareChk: LabelPos
		{
			y = SQFLAB_LT_Y_FLARE_CHK;
			h = SQFLAB_LT_CHK_H;
			text = $STR_SQFLAB_Lights_UseFlare;
		};
		class ChkFlare: RscCheckBox
		{
			idc = SQFLAB_LT_IDC_CHK_FLARE;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE + SQFLAB_LT_LABEL_W + 0.006;
			y = SQFLAB_LT_Y_FLARE_CHK;
			w = 0.03;
			h = SQFLAB_LT_CHK_H;
			checked = 1;
			onCheckedChanged = "[] call SQFLab_fnc_lightsOnSlider";
		};

		class LabelFlareSize: LabelPos { y = SQFLAB_LT_Y_FLARE_SIZE; text = $STR_SQFLAB_Lights_FlareSize; };
		class SliderFlareSize: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_FLARE_SIZE; y = SQFLAB_LT_Y_FLARE_SIZE; };
		class ValueFlareSize: ValueDir { idc = SQFLAB_LT_IDC_VALUE_FLARE_SIZE; y = SQFLAB_LT_Y_FLARE_SIZE; };

		class LabelFlareMax: LabelPos { y = SQFLAB_LT_Y_FLARE_MAX; text = $STR_SQFLAB_Lights_FlareMaxDist; };
		class SliderFlareMax: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_FLARE_MAX; y = SQFLAB_LT_Y_FLARE_MAX; };
		class ValueFlareMax: ValueDir { idc = SQFLAB_LT_IDC_VALUE_FLARE_MAX; y = SQFLAB_LT_Y_FLARE_MAX; };

		class MiscTitle: TypeTitle
		{
			y = SQFLAB_LT_Y_MISC_TITLE;
			text = $STR_SQFLAB_Lights_PreviewTime;
			tooltip = $STR_SQFLAB_Lights_PreviewTime_Tooltip;
		};
		class BtnPreviewDay: BtnPoint
		{
			idc = SQFLAB_LT_IDC_BTN_DAY;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE;
			y = SQFLAB_LT_Y_MISC_ROW;
			w = 0.14;
			text = $STR_SQFLAB_Lights_Day;
			tooltip = $STR_SQFLAB_Lights_Day_Tooltip;
			action = "[] call SQFLab_fnc_lightsSetTimeDay";
		};
		class BtnPreviewNight: BtnPreviewDay
		{
			idc = SQFLAB_LT_IDC_BTN_NIGHT;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PAD_SIDE + 0.15;
			text = $STR_SQFLAB_Lights_Night;
			tooltip = $STR_SQFLAB_Lights_Night_Tooltip;
			action = "[] call SQFLab_fnc_lightsSetTimeNight";
		};

		class ReflectorTitle: TypeTitle
		{
			y = SQFLAB_LT_Y_REFLECTOR_TITLE;
			text = $STR_SQFLAB_Lights_ReflectorCone;
			tooltip = $STR_SQFLAB_Lights_ReflectorCone_Tooltip;
		};
		class LabelConeOut: LabelPos { y = SQFLAB_LT_Y_CONE_OUT; text = $STR_SQFLAB_Lights_ConeOuter; };
		class SliderConeOut: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_CONE_OUT; y = SQFLAB_LT_Y_CONE_OUT; };
		class ValueConeOut: ValueDir { idc = SQFLAB_LT_IDC_VALUE_CONE_OUT; y = SQFLAB_LT_Y_CONE_OUT; };

		class LabelConeIn: LabelPos { y = SQFLAB_LT_Y_CONE_IN; text = $STR_SQFLAB_Lights_ConeInner; };
		class SliderConeIn: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_CONE_IN; y = SQFLAB_LT_Y_CONE_IN; };
		class ValueConeIn: ValueDir { idc = SQFLAB_LT_IDC_VALUE_CONE_IN; y = SQFLAB_LT_Y_CONE_IN; };

		class LabelConeCoef: LabelPos { y = SQFLAB_LT_Y_CONE_COEF; text = $STR_SQFLAB_Lights_ConeCoef; };
		class SliderConeCoef: SliderDir { idc = SQFLAB_LT_IDC_SLIDER_CONE_COEF; y = SQFLAB_LT_Y_CONE_COEF; };
		class ValueConeCoef: ValueDir { idc = SQFLAB_LT_IDC_VALUE_CONE_COEF; y = SQFLAB_LT_Y_CONE_COEF; };

		class CloseBtn: RscButtonMenu
		{
			idc = SQFLAB_LT_IDC_BTN_CLOSE;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PANEL_W - SQFLAB_LT_PAD_SIDE - SQFLAB_LT_BTN_W;
			y = SQFLAB_LT_Y_BOTTOM_BTN;
			w = SQFLAB_LT_BTN_W;
			h = 0.04;
			text = $STR_SQFLAB_Common_Close;
			action = "closeDialog 2";
			colorBackground[] = SQFLAB_LT_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_LT_PROFILE_COLOR(1);
		};
		class ExportBtn: CloseBtn
		{
			idc = SQFLAB_LT_IDC_BTN_EXPORT;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PANEL_W - SQFLAB_LT_PAD_SIDE - (SQFLAB_LT_BTN_W * 3) - (SQFLAB_LT_BTN_GAP * 2);
			text = $STR_SQFLAB_Common_Export;
			action = "[] call SQFLab_fnc_lightsExport";
		};
		class HideUiBtn: CloseBtn
		{
			idc = SQFLAB_LT_IDC_BTN_HIDE_UI;
			x = SQFLAB_LT_PANEL_X + SQFLAB_LT_PANEL_W - SQFLAB_LT_PAD_SIDE - (SQFLAB_LT_BTN_W * 2) - SQFLAB_LT_BTN_GAP;
			text = $STR_SQFLAB_Common_HideUI;
			action = "[] call SQFLab_fnc_lightsToggleUi";
		};
	};
};

#endif

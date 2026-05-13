#ifndef SQFLAB_UI_DRAWICON3D_HPP
#define SQFLAB_UI_DRAWICON3D_HPP

#include "\SQFLab\UI\DrawIcon3D\ui_drawIcon3D_controls.hpp"

#define SQFLAB_DI3D_PROFILE_COLOR(a) { "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.3843])", "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.7019])", "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.8862])", a }

#define SQFLAB_DI3D_PANEL_W 0.68
#define SQFLAB_DI3D_PANEL_H 1.20
#define SQFLAB_DI3D_PANEL_GAP 0.02
#define SQFLAB_DI3D_TOTAL_W ((SQFLAB_DI3D_PANEL_W * 2) + SQFLAB_DI3D_PANEL_GAP)
#define SQFLAB_DI3D_PANEL_X (safeZoneX + ((safeZoneW - SQFLAB_DI3D_TOTAL_W) * 0.5) + SQFLAB_DI3D_PANEL_W + SQFLAB_DI3D_PANEL_GAP)
#define SQFLAB_DI3D_PANEL_Y (safeZoneY + (safeZoneH - SQFLAB_DI3D_PANEL_H) * 0.5)
#define SQFLAB_DI3D_PREVIEW_X (SQFLAB_DI3D_PANEL_X - SQFLAB_DI3D_PANEL_GAP - SQFLAB_DI3D_PANEL_W)

#define SQFLAB_DI3D_PAD_SIDE 0.015
#define SQFLAB_DI3D_PAD_TOP 0.012
#define SQFLAB_DI3D_TITLE_H 0.05
#define SQFLAB_DI3D_SECTION_GAP 0.008
#define SQFLAB_DI3D_ROW_H 0.038
#define SQFLAB_DI3D_GW (SQFLAB_DI3D_PANEL_W - (SQFLAB_DI3D_PAD_SIDE * 2))
#define SQFLAB_DI3D_LABEL_W 0.22
#define SQFLAB_DI3D_FIELD_X (SQFLAB_DI3D_LABEL_W + 0.01)
#define SQFLAB_DI3D_FIELD_W (SQFLAB_DI3D_GW - SQFLAB_DI3D_FIELD_X)
#define SQFLAB_DI3D_SCROLL_Y (SQFLAB_DI3D_PANEL_Y + SQFLAB_DI3D_PAD_TOP + SQFLAB_DI3D_TITLE_H + SQFLAB_DI3D_SECTION_GAP)
#define SQFLAB_DI3D_SCROLL_H (SQFLAB_DI3D_PANEL_H - (SQFLAB_DI3D_PAD_TOP * 2) - SQFLAB_DI3D_TITLE_H - 0.1)
#define SQFLAB_DI3D_BTN_W 0.16
#define SQFLAB_DI3D_BTN_GAP 0.01
#define SQFLAB_DI3D_Y_BOTTOM_BTN (SQFLAB_DI3D_PANEL_Y + SQFLAB_DI3D_PANEL_H - SQFLAB_DI3D_PAD_TOP - 0.04)

class SQFLab_DrawIcon3DMenu
{
	idd = SQFLAB_DI3D_IDD;
	movingEnable = 0;
	enableSimulation = 1;
	enableDisplay = 1;
	onLoad = "_this call SQFLab_fnc_drawIcon3DInit";
	onUnload = "_this call SQFLab_fnc_drawIcon3DCleanup";

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
			x = SQFLAB_DI3D_PANEL_X;
			y = SQFLAB_DI3D_PANEL_Y;
			w = SQFLAB_DI3D_PANEL_W;
			h = SQFLAB_DI3D_PANEL_H;
			colorBackground[] = {0.10, 0.10, 0.10, 0.95};
		};
	};

	class controls
	{
		class PreviewTitle: RscText
		{
			idc = SQFLAB_DI3D_IDC_PREVIEW_TITLE;
			x = SQFLAB_DI3D_PREVIEW_X + SQFLAB_DI3D_PAD_SIDE;
			y = SQFLAB_DI3D_PANEL_Y + SQFLAB_DI3D_PAD_TOP;
			w = SQFLAB_DI3D_PANEL_W - (SQFLAB_DI3D_PAD_SIDE * 2);
			h = SQFLAB_DI3D_TITLE_H;
			text = $STR_SQFLAB_DrawIcon3D_Preview;
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_DI3D_PROFILE_COLOR(0.9);
		};
		class Title: RscText
		{
			idc = -1;
			x = SQFLAB_DI3D_PANEL_X + SQFLAB_DI3D_PAD_SIDE;
			y = SQFLAB_DI3D_PANEL_Y + SQFLAB_DI3D_PAD_TOP;
			w = SQFLAB_DI3D_GW;
			h = SQFLAB_DI3D_TITLE_H;
			text = $STR_SQFLAB_DrawIcon3D_Title;
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_DI3D_PROFILE_COLOR(0.9);
		};

		class GroupScroll: RscControlsGroup
		{
			idc = SQFLAB_DI3D_IDC_GROUP_SCROLL;
			x = SQFLAB_DI3D_PANEL_X + SQFLAB_DI3D_PAD_SIDE;
			y = SQFLAB_DI3D_SCROLL_Y;
			w = SQFLAB_DI3D_GW;
			h = SQFLAB_DI3D_SCROLL_H;
			class VScrollbar { width = 0; height = 0; scrollSpeed = 0.15; };
			class HScrollbar { width = 0; height = 0; color[] = {1, 1, 1, 0}; colorActive[] = {1, 1, 1, 0}; colorDisabled[] = {1, 1, 1, 0}; };
			class controls
			{
				class G_LabelBase: RscText { idc = -1; x = 0; w = SQFLAB_DI3D_LABEL_W; h = SQFLAB_DI3D_ROW_H; colorBackground[] = {0,0,0,0}; sizeEx = 0.03; };
				class G_SectionPosition: RscText { idc = -1; x = 0; y = 0.00; w = SQFLAB_DI3D_GW; h = 0.03; text = $STR_SQFLAB_DrawIcon3D_PositionTitle; colorBackground[] = SQFLAB_DI3D_PROFILE_COLOR(0.35); };
				class G_LabelPosMode: G_LabelBase { y = 0.036; text = $STR_SQFLAB_DrawIcon3D_Label_PosMode; };
				class G_PosMode: RscCombo { idc = SQFLAB_DI3D_IDC_COMBO_POS_MODE; x = SQFLAB_DI3D_FIELD_X; y = 0.036; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; sizeEx = 0.03; onLBSelChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelPosVec: G_LabelBase { y = 0.082; text = $STR_SQFLAB_DrawIcon3D_Label_PosVector; };
				class G_PosVec: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_POS_VEC; x = SQFLAB_DI3D_FIELD_X; y = 0.082; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "[0,0,2]"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelPosObj: G_LabelBase { y = 0.128; text = $STR_SQFLAB_DrawIcon3D_Label_Object; };
				class G_PosObj: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_POS_OBJECT; x = SQFLAB_DI3D_FIELD_X; y = 0.128; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "player"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelPosSelection: G_LabelBase { y = 0.174; text = $STR_SQFLAB_DrawIcon3D_Label_Selection; };
				class G_PosSelection: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_POS_SELECTION; x = SQFLAB_DI3D_FIELD_X; y = 0.174; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = ""; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelPosOffsetZ: G_LabelBase { y = 0.220; text = $STR_SQFLAB_DrawIcon3D_Label_OffsetZ; };
				class G_PosOffsetZ: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_POS_OFFSETZ; x = SQFLAB_DI3D_FIELD_X; y = 0.220; w = (SQFLAB_DI3D_FIELD_W * 0.49); h = SQFLAB_DI3D_ROW_H; text = "2"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelPosLod: G_LabelBase { x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.51); y = 0.220; w = 0.08; text = $STR_SQFLAB_DrawIcon3D_Label_Lod; };
				class G_PosLod: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_POS_LOD; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.60); y = 0.220; w = (SQFLAB_DI3D_FIELD_W * 0.40); h = SQFLAB_DI3D_ROW_H; text = "-1"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };

				class G_SectionCore: G_SectionPosition { y = 0.276; text = $STR_SQFLAB_DrawIcon3D_CoreTitle; };
				class G_LabelTexture: G_LabelBase { y = 0.312; text = $STR_SQFLAB_DrawIcon3D_Label_Texture; };
				class G_Texture: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_TEXTURE; x = SQFLAB_DI3D_FIELD_X; y = 0.312; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = ""; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_SliderBase: RscSlider
				{
					idc = -1;
					x = 0;
					y = -10;
					w = SQFLAB_DI3D_FIELD_W * 0.84;
					h = SQFLAB_DI3D_ROW_H;
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
					tooltipColorText[] = {1, 1, 1, 1};
					tooltipColorBox[] = {1, 1, 1, 1};
					tooltipColorShade[] = {0, 0, 0, 0.65};
					onSliderPosChanged = "_this call SQFLab_fnc_drawIcon3DOnSlider";
				};
				class G_LabelSize: G_LabelBase { y = 0.362; text = $STR_SQFLAB_DrawIcon3D_Label_Size; };
				class G_SizeSlider: G_SliderBase { idc = SQFLAB_DI3D_IDC_SLIDER_SIZE; x = SQFLAB_DI3D_FIELD_X; y = 0.362; w = SQFLAB_DI3D_FIELD_W * 0.84; };
				class G_SizeValue: RscEdit { idc = SQFLAB_DI3D_IDC_VALUE_SIZE; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.85); y = 0.362; w = SQFLAB_DI3D_FIELD_W * 0.15; h = SQFLAB_DI3D_ROW_H; style = 1; text = "0.05"; onKillFocus = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelFont: G_LabelBase { y = 0.408; text = $STR_SQFLAB_DrawIcon3D_Label_Font; };
				class G_Font: RscCombo { idc = SQFLAB_DI3D_IDC_EDIT_FONT; x = SQFLAB_DI3D_FIELD_X; y = 0.408; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; sizeEx = 0.03; onLBSelChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };

				class G_ColorPreview: RscButtonMenu { idc = SQFLAB_DI3D_IDC_COLOR_PREVIEW; x = 0; y = 0.454; w = SQFLAB_DI3D_GW; h = SQFLAB_DI3D_ROW_H; text = $STR_SQFLAB_Common_ColorPreview; style = 2; action = ""; };
				class G_LabelColorR: G_LabelBase { y = 0.500; text = $STR_SQFLAB_Common_ColorR; };
				class G_ColorR: G_SliderBase { idc = SQFLAB_DI3D_IDC_SLIDER_COLOR_R; x = SQFLAB_DI3D_FIELD_X; y = 0.500; w = SQFLAB_DI3D_FIELD_W * 0.84; };
				class G_ColorRVal: RscEdit { idc = SQFLAB_DI3D_IDC_VALUE_COLOR_R; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.85); y = 0.500; w = SQFLAB_DI3D_FIELD_W * 0.15; h = SQFLAB_DI3D_ROW_H; style = 1; text = "1"; onKillFocus = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelColorG: G_LabelBase { y = 0.546; text = $STR_SQFLAB_Common_ColorG; };
				class G_ColorG: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_COLOR_G; y = 0.546; };
				class G_ColorGVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_COLOR_G; y = 0.546; };
				class G_LabelColorB: G_LabelBase { y = 0.592; text = $STR_SQFLAB_Common_ColorB; };
				class G_ColorB: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_COLOR_B; y = 0.592; };
				class G_ColorBVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_COLOR_B; y = 0.592; };
				class G_LabelColorA: G_LabelBase { y = 0.638; text = $STR_SQFLAB_Common_ColorA; };
				class G_ColorA: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_COLOR_A; y = 0.638; };
				class G_ColorAVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_COLOR_A; y = 0.638; };

				class G_LabelShadow: G_LabelBase { y = 0.684; text = $STR_SQFLAB_DrawIcon3D_Label_Shadow; };
				class G_Shadow: RscCheckBox { idc = SQFLAB_DI3D_IDC_CHK_SHADOW; x = SQFLAB_DI3D_GW - 0.03; y = 0.684; w = 0.03; h = SQFLAB_DI3D_ROW_H; checked = 0; onCheckedChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelFade: G_LabelBase { y = 0.730; text = $STR_SQFLAB_DrawIcon3D_Label_Fade; };
				class G_Fade: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_FADE; x = SQFLAB_DI3D_FIELD_X; y = 0.730; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "[-1,-1]"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelDynamic: G_LabelBase { y = 0.776; text = $STR_SQFLAB_DrawIcon3D_Label_Dynamic; };
				class G_Dynamic: RscCheckBox { idc = SQFLAB_DI3D_IDC_CHK_DYNAMIC; x = SQFLAB_DI3D_FIELD_X; y = 0.776; w = 0.03; h = SQFLAB_DI3D_ROW_H; checked = 0; onCheckedChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelCheckVis: G_LabelBase { x = SQFLAB_DI3D_FIELD_X + 0.06; y = 0.776; w = 0.22; text = $STR_SQFLAB_DrawIcon3D_Label_CheckVisibility; };
				class G_CheckVis: RscCheckBox { idc = SQFLAB_DI3D_IDC_CHK_CHECK_VIS; x = SQFLAB_DI3D_GW - 0.03; y = 0.776; w = 0.03; h = SQFLAB_DI3D_ROW_H; checked = 0; onCheckedChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };

				class G_LabelOffsetX: G_LabelBase { y = 0.822; text = $STR_SQFLAB_DrawIcon3D_Label_OffsetX; };
				class G_OffsetX: G_SliderBase { idc = SQFLAB_DI3D_IDC_SLIDER_OFFSET_X; x = SQFLAB_DI3D_FIELD_X; y = 0.822; w = SQFLAB_DI3D_FIELD_W * 0.84; };
				class G_OffsetXVal: RscEdit { idc = SQFLAB_DI3D_IDC_VALUE_OFFSET_X; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.85); y = 0.822; w = SQFLAB_DI3D_FIELD_W * 0.15; h = SQFLAB_DI3D_ROW_H; style = 1; text = "0"; onKillFocus = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelOffsetY: G_LabelBase { y = 0.868; text = $STR_SQFLAB_DrawIcon3D_Label_OffsetY; };
				class G_OffsetY: G_OffsetX { idc = SQFLAB_DI3D_IDC_SLIDER_OFFSET_Y; y = 0.868; };
				class G_OffsetYVal: G_OffsetXVal { idc = SQFLAB_DI3D_IDC_VALUE_OFFSET_Y; y = 0.868; };
				class G_LabelHardAlpha: G_LabelBase { y = 0.914; text = $STR_SQFLAB_DrawIcon3D_Label_HardAlpha; };
				class G_HardAlpha: G_OffsetX { idc = SQFLAB_DI3D_IDC_SLIDER_HARD_ALPHA; y = 0.914; };
				class G_HardAlphaVal: G_OffsetXVal { idc = SQFLAB_DI3D_IDC_VALUE_HARD_ALPHA; y = 0.914; text = "-1"; };

				class G_SectionArrows: G_SectionPosition { y = 0.968; text = $STR_SQFLAB_DrawIcon3D_ArrowsTitle; };
				class G_LabelDrawArrows: G_LabelBase { y = 1.004; text = $STR_SQFLAB_DrawIcon3D_Label_DrawArrows; };
				class G_DrawArrows: RscCheckBox { idc = SQFLAB_DI3D_IDC_CHK_DRAW_ARROWS; x = SQFLAB_DI3D_GW - 0.03; y = 1.004; w = 0.03; h = SQFLAB_DI3D_ROW_H; checked = 0; onCheckedChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_ArrowTexture: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_ARROW_TEXTURE; x = SQFLAB_DI3D_FIELD_X; y = 1.004; w = SQFLAB_DI3D_FIELD_W - 0.04; h = SQFLAB_DI3D_ROW_H; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelArrowSize: G_LabelBase { y = 1.054; text = $STR_SQFLAB_DrawIcon3D_Label_ArrowSize; };
				class G_ArrowSize: G_SliderBase { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_SIZE; x = SQFLAB_DI3D_FIELD_X; y = 1.054; w = SQFLAB_DI3D_FIELD_W * 0.84; };
				class G_ArrowSizeVal: RscEdit { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_SIZE; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.85); y = 1.054; w = SQFLAB_DI3D_FIELD_W * 0.15; h = SQFLAB_DI3D_ROW_H; style = 1; text = "0.05"; onKillFocus = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };

				class G_ArrowColorPreview: RscButtonMenu { idc = SQFLAB_DI3D_IDC_ARROW_COLOR_PREVIEW; x = 0; y = 1.100; w = SQFLAB_DI3D_GW; h = SQFLAB_DI3D_ROW_H; text = $STR_SQFLAB_DrawIcon3D_ArrowColor; style = 2; action = ""; };
				class G_LabelArrowColorR: G_LabelBase { y = 1.146; text = $STR_SQFLAB_Common_ColorR; };
				class G_ArrowColorR: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_R; y = 1.146; };
				class G_ArrowColorRVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_R; y = 1.146; };
				class G_LabelArrowColorG: G_LabelBase { y = 1.192; text = $STR_SQFLAB_Common_ColorG; };
				class G_ArrowColorG: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_G; y = 1.192; };
				class G_ArrowColorGVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_G; y = 1.192; };
				class G_LabelArrowColorB: G_LabelBase { y = 1.238; text = $STR_SQFLAB_Common_ColorB; };
				class G_ArrowColorB: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_B; y = 1.238; };
				class G_ArrowColorBVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_B; y = 1.238; };
				class G_LabelArrowColorA: G_LabelBase { y = 1.284; text = $STR_SQFLAB_Common_ColorA; };
				class G_ArrowColorA: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_A; y = 1.284; };
				class G_ArrowColorAVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_A; y = 1.284; };

				class G_LabelArrowText: G_LabelBase { y = 1.330; text = $STR_SQFLAB_DrawIcon3D_Label_ArrowText; };
				class G_ArrowText: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_TEXT; x = SQFLAB_DI3D_FIELD_X; y = 1.330; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = ""; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelArrowTextParams: G_LabelBase { y = 1.376; text = $STR_SQFLAB_DrawIcon3D_Label_ArrowTextParams; };
				class G_ArrowTextSize: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_SIZE; x = SQFLAB_DI3D_FIELD_X; y = 1.376; w = SQFLAB_DI3D_FIELD_W * 0.32; h = SQFLAB_DI3D_ROW_H; text = "0.04"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_ArrowTextOX: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_OX; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.34); y = 1.376; w = SQFLAB_DI3D_FIELD_W * 0.32; h = SQFLAB_DI3D_ROW_H; text = "1"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_ArrowTextOY: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_OY; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.68); y = 1.376; w = SQFLAB_DI3D_FIELD_W * 0.32; h = SQFLAB_DI3D_ROW_H; text = "1"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_ArrowTextShadow: RscCheckBox { idc = SQFLAB_DI3D_IDC_CHK_ARROW_TEXT_SHADOW; x = SQFLAB_DI3D_GW - 0.03; y = 1.422; w = 0.03; h = SQFLAB_DI3D_ROW_H; checked = 0; onCheckedChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };

				class G_ArrowTextColorPreview: RscButtonMenu { idc = SQFLAB_DI3D_IDC_ARROW_TEXT_COLOR_PREVIEW; x = 0; y = 1.422; w = SQFLAB_DI3D_GW - 0.04; h = SQFLAB_DI3D_ROW_H; text = $STR_SQFLAB_DrawIcon3D_ArrowTextColor; style = 2; action = ""; };
				class G_LabelArrowTextColorR: G_LabelBase { y = 1.468; text = $STR_SQFLAB_Common_ColorR; };
				class G_ArrowTextColorR: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_R; y = 1.468; };
				class G_ArrowTextColorRVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_R; y = 1.468; };
				class G_LabelArrowTextColorG: G_LabelBase { y = 1.514; text = $STR_SQFLAB_Common_ColorG; };
				class G_ArrowTextColorG: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_G; y = 1.514; };
				class G_ArrowTextColorGVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_G; y = 1.514; };
				class G_LabelArrowTextColorB: G_LabelBase { y = 1.560; text = $STR_SQFLAB_Common_ColorB; };
				class G_ArrowTextColorB: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_B; y = 1.560; };
				class G_ArrowTextColorBVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_B; y = 1.560; };
				class G_LabelArrowTextColorA: G_LabelBase { y = 1.606; text = $STR_SQFLAB_Common_ColorA; };
				class G_ArrowTextColorA: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_A; y = 1.606; };
				class G_ArrowTextColorAVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_A; y = 1.606; };

				class G_SectionTexts: G_SectionPosition { y = 1.660; text = $STR_SQFLAB_DrawIcon3D_TextsTitle; };
				class G_LabelTextsText: G_LabelBase { y = 1.696; text = "Text"; };
				class G_TextsText: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_TEXTS_TEXT; x = SQFLAB_DI3D_FIELD_X; y = 1.696; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = ""; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelTextsSize: G_LabelBase { y = 1.742; text = "Text size"; };
				class G_TextsSize: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_TEXTS_SIZE; x = SQFLAB_DI3D_FIELD_X; y = 1.742; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "0.025"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelTextsOX: G_LabelBase { y = 1.788; text = "Text offset X"; };
				class G_TextsOX: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_TEXTS_OX; x = SQFLAB_DI3D_FIELD_X; y = 1.788; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "-0.085"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelTextsOY: G_LabelBase { y = 1.834; text = "Text offset Y"; };
				class G_TextsOY: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_TEXTS_OY; x = SQFLAB_DI3D_FIELD_X; y = 1.834; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "0"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelTextsShadow: G_LabelBase { y = 1.880; text = "Text shadow"; };
				class G_TextsShadow: RscCheckBox { idc = SQFLAB_DI3D_IDC_CHK_TEXTS_SHADOW; x = SQFLAB_DI3D_GW - 0.03; y = 1.880; w = 0.03; h = SQFLAB_DI3D_ROW_H; checked = 0; onCheckedChanged = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_TextsColorPreview: RscButtonMenu { idc = SQFLAB_DI3D_IDC_TEXTS_COLOR_PREVIEW; x = 0; y = 1.926; w = SQFLAB_DI3D_GW; h = SQFLAB_DI3D_ROW_H; text = "Texts color"; style = 2; action = ""; };
				class G_LabelTextsColorR: G_LabelBase { y = 1.972; text = $STR_SQFLAB_Common_ColorR; };
				class G_TextsColorR: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_TEXTS_R; y = 1.972; };
				class G_TextsColorRVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_TEXTS_R; y = 1.972; };
				class G_LabelTextsColorG: G_LabelBase { y = 2.018; text = $STR_SQFLAB_Common_ColorG; };
				class G_TextsColorG: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_TEXTS_G; y = 2.018; };
				class G_TextsColorGVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_TEXTS_G; y = 2.018; };
				class G_LabelTextsColorB: G_LabelBase { y = 2.064; text = $STR_SQFLAB_Common_ColorB; };
				class G_TextsColorB: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_TEXTS_B; y = 2.064; };
				class G_TextsColorBVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_TEXTS_B; y = 2.064; };
				class G_LabelTextsColorA: G_LabelBase { y = 2.110; text = $STR_SQFLAB_Common_ColorA; };
				class G_TextsColorA: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_TEXTS_A; y = 2.110; };
				class G_TextsColorAVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_TEXTS_A; y = 2.110; };

				class G_SectionProgress: G_SectionPosition { y = 2.164; text = $STR_SQFLAB_DrawIcon3D_ProgressTitle; };
				class G_LabelProgressW: G_LabelBase { y = 2.200; text = "Progress width"; };
				class G_ProgressW: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_PROGRESS_W; x = SQFLAB_DI3D_FIELD_X; y = 2.200; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "0.005"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelProgressH: G_LabelBase { y = 2.246; text = "Progress height"; };
				class G_ProgressH: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_PROGRESS_H; x = SQFLAB_DI3D_FIELD_X; y = 2.246; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "0.05"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelProgressOX: G_LabelBase { y = 2.292; text = "Progress offset X"; };
				class G_ProgressOX: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_PROGRESS_OX; x = SQFLAB_DI3D_FIELD_X; y = 2.292; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "-0.085"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };
				class G_LabelProgressOY: G_LabelBase { y = 2.338; text = "Progress offset Y"; };
				class G_ProgressOY: RscEdit { idc = SQFLAB_DI3D_IDC_EDIT_PROGRESS_OY; x = SQFLAB_DI3D_FIELD_X; y = 2.338; w = SQFLAB_DI3D_FIELD_W; h = SQFLAB_DI3D_ROW_H; text = "0"; onKeyUp = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };

				class G_ProgressFgPreview: RscButtonMenu { idc = SQFLAB_DI3D_IDC_PROGRESS_FG_PREVIEW; x = 0; y = 2.384; w = SQFLAB_DI3D_GW; h = SQFLAB_DI3D_ROW_H; text = "Progress FG"; style = 2; action = ""; };
				class G_LabelProgressFgR: G_LabelBase { y = 2.430; text = $STR_SQFLAB_Common_ColorR; };
				class G_ProgressFgR: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_R; y = 2.430; };
				class G_ProgressFgRVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_R; y = 2.430; };
				class G_LabelProgressFgG: G_LabelBase { y = 2.476; text = $STR_SQFLAB_Common_ColorG; };
				class G_ProgressFgG: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_G; y = 2.476; };
				class G_ProgressFgGVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_G; y = 2.476; };
				class G_LabelProgressFgB: G_LabelBase { y = 2.522; text = $STR_SQFLAB_Common_ColorB; };
				class G_ProgressFgB: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_B; y = 2.522; };
				class G_ProgressFgBVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_B; y = 2.522; };
				class G_LabelProgressFgA: G_LabelBase { y = 2.568; text = $STR_SQFLAB_Common_ColorA; };
				class G_ProgressFgA: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_A; y = 2.568; };
				class G_ProgressFgAVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_A; y = 2.568; };

				class G_ProgressBgPreview: RscButtonMenu { idc = SQFLAB_DI3D_IDC_PROGRESS_BG_PREVIEW; x = 0; y = 2.614; w = SQFLAB_DI3D_GW; h = SQFLAB_DI3D_ROW_H; text = "Progress BG"; style = 2; action = ""; };
				class G_LabelProgressBgR: G_LabelBase { y = 2.660; text = $STR_SQFLAB_Common_ColorR; };
				class G_ProgressBgR: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_R; y = 2.660; };
				class G_ProgressBgRVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_R; y = 2.660; };
				class G_LabelProgressBgG: G_LabelBase { y = 2.706; text = $STR_SQFLAB_Common_ColorG; };
				class G_ProgressBgG: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_G; y = 2.706; };
				class G_ProgressBgGVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_G; y = 2.706; };
				class G_LabelProgressBgB: G_LabelBase { y = 2.752; text = $STR_SQFLAB_Common_ColorB; };
				class G_ProgressBgB: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_B; y = 2.752; };
				class G_ProgressBgBVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_B; y = 2.752; };
				class G_LabelProgressBgA: G_LabelBase { y = 2.798; text = $STR_SQFLAB_Common_ColorA; };
				class G_ProgressBgA: G_ColorR { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_A; y = 2.798; };
				class G_ProgressBgAVal: G_ColorRVal { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_A; y = 2.798; };

				class G_LabelProgressValue: G_LabelBase { y = 2.844; text = $STR_SQFLAB_DrawIcon3D_Label_ProgressValue; };
				class G_ProgressValue: G_SliderBase { idc = SQFLAB_DI3D_IDC_SLIDER_PROGRESS_VALUE; x = SQFLAB_DI3D_FIELD_X; y = 2.844; w = SQFLAB_DI3D_FIELD_W * 0.84; };
				class G_ProgressValueVal: RscEdit { idc = SQFLAB_DI3D_IDC_VALUE_PROGRESS_VALUE; x = SQFLAB_DI3D_FIELD_X + (SQFLAB_DI3D_FIELD_W * 0.85); y = 2.844; w = SQFLAB_DI3D_FIELD_W * 0.15; h = SQFLAB_DI3D_ROW_H; style = 1; text = "0.67"; onKillFocus = "[] call SQFLab_fnc_drawIcon3DApplyPreview"; };

				class G_EndPad: RscText { idc = -1; x = 0; y = 2.908; w = 0.02; h = 0.02; colorBackground[] = {0,0,0,0}; };
			};
		};

		class CloseBtn: RscButtonMenu
		{
			idc = SQFLAB_DI3D_IDC_BTN_CLOSE;
			x = SQFLAB_DI3D_PANEL_X + SQFLAB_DI3D_PANEL_W - SQFLAB_DI3D_PAD_SIDE - SQFLAB_DI3D_BTN_W;
			y = SQFLAB_DI3D_Y_BOTTOM_BTN;
			w = SQFLAB_DI3D_BTN_W;
			h = 0.04;
			text = $STR_SQFLAB_Common_Close;
			action = "closeDialog 2";
			colorBackground[] = SQFLAB_DI3D_PROFILE_COLOR(0.9);
		};
		class ExportBtn: CloseBtn
		{
			idc = SQFLAB_DI3D_IDC_BTN_EXPORT;
			x = SQFLAB_DI3D_PANEL_X + SQFLAB_DI3D_PANEL_W - SQFLAB_DI3D_PAD_SIDE - (SQFLAB_DI3D_BTN_W * 2) - SQFLAB_DI3D_BTN_GAP;
			text = $STR_SQFLAB_Common_Export;
			action = "[] call SQFLab_fnc_drawIcon3DExport";
		};
	};
};

#endif

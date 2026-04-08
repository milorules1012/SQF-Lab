#ifndef SQFLAB_UI_MARKERS_HPP
#define SQFLAB_UI_MARKERS_HPP

#include "\SQFLab\UI\Markers\ui_markers_controls.hpp"

#define SQFLAB_MKR_PROFILE_COLOR(a) { "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.3843])", "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.7019])", "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.8862])", a }

#define SQFLAB_MKR_PANEL_W 0.68
#define SQFLAB_MKR_PANEL_H 1.14
#define SQFLAB_MKR_PANEL_GAP 0.02
#define SQFLAB_MKR_TOTAL_W ((SQFLAB_MKR_PANEL_W * 2) + SQFLAB_MKR_PANEL_GAP)
#define SQFLAB_MKR_PANEL_X (safeZoneX + ((safeZoneW - SQFLAB_MKR_TOTAL_W) * 0.5) + SQFLAB_MKR_PANEL_W + SQFLAB_MKR_PANEL_GAP)
#define SQFLAB_MKR_PANEL_Y (safeZoneY + (safeZoneH - SQFLAB_MKR_PANEL_H) * 0.5)
#define SQFLAB_MKR_MAP_X (SQFLAB_MKR_PANEL_X - SQFLAB_MKR_PANEL_GAP - SQFLAB_MKR_PANEL_W)
#define SQFLAB_MKR_MAP_Y SQFLAB_MKR_PANEL_Y

#define SQFLAB_MKR_PAD_SIDE 0.016
#define SQFLAB_MKR_PAD_TOP 0.016
#define SQFLAB_MKR_TITLE_H 0.056
#define SQFLAB_MKR_SECTION_H 0.032
#define SQFLAB_MKR_ROW_H 0.038
#define SQFLAB_MKR_ROW_GAP 0.007
#define SQFLAB_MKR_SECTION_GAP 0.009
#define SQFLAB_MKR_TYPE_LIST_H 0.24
#define SQFLAB_MKR_BTN_W 0.16
#define SQFLAB_MKR_BTN_GAP 0.01
#define SQFLAB_MKR_LABEL_W 0.20
#define SQFLAB_MKR_VALUE_W 0.09
#define SQFLAB_MKR_LABEL_SIZEEX 0.032

/* Inner width = right panel content width (same as scroll group width) */
#define SQFLAB_MKR_GW (SQFLAB_MKR_PANEL_W - (SQFLAB_MKR_PAD_SIDE * 2))
#define SQFLAB_MKR_G_ID_LABEL_W 0.14
#define SQFLAB_MKR_G_EDIT_W (SQFLAB_MKR_GW - SQFLAB_MKR_G_ID_LABEL_W - 0.01)
#define SQFLAB_MKR_G_CHK_BOX_W 0.03
#define SQFLAB_MKR_G_CHK_H 0.028
#define SQFLAB_MKR_G_SLIDER_X (SQFLAB_MKR_LABEL_W + 0.012)
#define SQFLAB_MKR_G_SLIDER_W (SQFLAB_MKR_GW - SQFLAB_MKR_LABEL_W - SQFLAB_MKR_VALUE_W - 0.02)
#define SQFLAB_MKR_G_VALUE_X (SQFLAB_MKR_G_SLIDER_X + SQFLAB_MKR_G_SLIDER_W + 0.008)

#define SQFLAB_MKR_Y_DIALOG_TITLE (SQFLAB_MKR_PANEL_Y + SQFLAB_MKR_PAD_TOP)
#define SQFLAB_MKR_SCROLL_X (SQFLAB_MKR_PANEL_X + SQFLAB_MKR_PAD_SIDE)
#define SQFLAB_MKR_SCROLL_Y (SQFLAB_MKR_Y_DIALOG_TITLE + SQFLAB_MKR_TITLE_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_SCROLL_H (SQFLAB_MKR_PANEL_H - (SQFLAB_MKR_PAD_TOP * 2) - SQFLAB_MKR_TITLE_H - SQFLAB_MKR_SECTION_GAP - 0.044 - 0.012)
#define SQFLAB_MKR_Y_BOTTOM_BTN (SQFLAB_MKR_PANEL_Y + SQFLAB_MKR_PANEL_H - SQFLAB_MKR_PAD_TOP - 0.042)

/* Y positions inside scroll group (origin = top-left of group content) */
#define SQFLAB_MKR_GS_IDENTITY 0
#define SQFLAB_MKR_GS_NAME (SQFLAB_MKR_GS_IDENTITY + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_TEXT (SQFLAB_MKR_GS_NAME + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_SCOPE_TITLE (SQFLAB_MKR_GS_TEXT + SQFLAB_MKR_ROW_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_GS_SCOPE_ROW (SQFLAB_MKR_GS_SCOPE_TITLE + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_CHANNEL_ROW (SQFLAB_MKR_GS_SCOPE_ROW + SQFLAB_MKR_G_CHK_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_TYPE_TITLE (SQFLAB_MKR_GS_CHANNEL_ROW + SQFLAB_MKR_ROW_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_GS_TYPE_LIST (SQFLAB_MKR_GS_TYPE_TITLE + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_COLORS_TITLE (SQFLAB_MKR_GS_TYPE_LIST + SQFLAB_MKR_TYPE_LIST_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_GS_COLOR_PREVIEW (SQFLAB_MKR_GS_COLORS_TITLE + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_COLOR_R (SQFLAB_MKR_GS_COLOR_PREVIEW + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_COLOR_G (SQFLAB_MKR_GS_COLOR_R + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_COLOR_B (SQFLAB_MKR_GS_COLOR_G + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_COLOR_A (SQFLAB_MKR_GS_COLOR_B + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_POS_TITLE (SQFLAB_MKR_GS_COLOR_A + SQFLAB_MKR_ROW_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_GS_POS_ROW (SQFLAB_MKR_GS_POS_TITLE + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_POS_OFFSET_ROW (SQFLAB_MKR_GS_POS_ROW + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_SHAPE_TITLE (SQFLAB_MKR_GS_POS_OFFSET_ROW + SQFLAB_MKR_G_CHK_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_GS_COMBO_SHAPE (SQFLAB_MKR_GS_SHAPE_TITLE + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_SLIDER_SIZE_A (SQFLAB_MKR_GS_COMBO_SHAPE + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_SLIDER_SIZE_B (SQFLAB_MKR_GS_SLIDER_SIZE_A + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_SLIDER_DIR (SQFLAB_MKR_GS_SLIDER_SIZE_B + SQFLAB_MKR_ROW_H + SQFLAB_MKR_ROW_GAP)
#define SQFLAB_MKR_GS_BRUSH_TITLE (SQFLAB_MKR_GS_SLIDER_DIR + SQFLAB_MKR_ROW_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_GS_COMBO_BRUSH (SQFLAB_MKR_GS_BRUSH_TITLE + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_SHADOW_TITLE (SQFLAB_MKR_GS_COMBO_BRUSH + SQFLAB_MKR_ROW_H + SQFLAB_MKR_SECTION_GAP)
#define SQFLAB_MKR_GS_COMBO_SHADOW (SQFLAB_MKR_GS_SHADOW_TITLE + SQFLAB_MKR_SECTION_H + 0.004)
#define SQFLAB_MKR_GS_CONTENT_BOTTOM (SQFLAB_MKR_GS_COMBO_SHADOW + SQFLAB_MKR_ROW_H + 0.024)

class SQFLab_MarkersMenu
{
	idd = SQFLAB_MKR_IDD;
	movingEnable = 0;
	enableSimulation = 1;
	enableDisplay = 1;
	onLoad = "_this call SQFLab_fnc_markersInit";
	onUnload = "_this call SQFLab_fnc_markersCleanup";

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
			x = SQFLAB_MKR_PANEL_X;
			y = SQFLAB_MKR_PANEL_Y;
			w = SQFLAB_MKR_PANEL_W;
			h = SQFLAB_MKR_PANEL_H;
			colorBackground[] = {0.10, 0.10, 0.10, 0.95};
		};
		class MapBackground: Background
		{
			x = SQFLAB_MKR_MAP_X;
			y = SQFLAB_MKR_MAP_Y;
		};
	};

	class controls
	{
		class MapTitle: RscText
		{
			idc = SQFLAB_MKR_IDC_MAP_TITLE;
			x = SQFLAB_MKR_MAP_X + SQFLAB_MKR_PAD_SIDE;
			y = SQFLAB_MKR_MAP_Y + SQFLAB_MKR_PAD_TOP;
			w = SQFLAB_MKR_PANEL_W - (SQFLAB_MKR_PAD_SIDE * 2);
			h = SQFLAB_MKR_TITLE_H;
			text = "Map";
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_MKR_PROFILE_COLOR(0.9);
			colorText[] = {1, 1, 1, 1};
		};
		class MapView: RscMapControl
		{
			idc = SQFLAB_MKR_IDC_MAP;
			x = SQFLAB_MKR_MAP_X + SQFLAB_MKR_PAD_SIDE;
			y = SQFLAB_MKR_MAP_Y + SQFLAB_MKR_PAD_TOP + SQFLAB_MKR_TITLE_H + SQFLAB_MKR_SECTION_GAP;
			w = SQFLAB_MKR_PANEL_W - (SQFLAB_MKR_PAD_SIDE * 2);
			h = SQFLAB_MKR_PANEL_H - (SQFLAB_MKR_PAD_TOP * 2) - SQFLAB_MKR_TITLE_H - SQFLAB_MKR_SECTION_GAP;
			widthRailWay = 1;
		};

		class Title: RscText
		{
			idc = -1;
			x = SQFLAB_MKR_PANEL_X + SQFLAB_MKR_PAD_SIDE;
			y = SQFLAB_MKR_Y_DIALOG_TITLE;
			w = SQFLAB_MKR_PANEL_W - (SQFLAB_MKR_PAD_SIDE * 2);
			h = SQFLAB_MKR_TITLE_H;
			text = "Markers";
			style = 2;
			sizeEx = 0.042;
			colorBackground[] = SQFLAB_MKR_PROFILE_COLOR(0.9);
			colorText[] = {1, 1, 1, 1};
		};

		class GroupScroll: RscControlsGroup
		{
			idc = SQFLAB_MKR_IDC_GROUP_SCROLL;
			x = SQFLAB_MKR_SCROLL_X;
			y = SQFLAB_MKR_SCROLL_Y;
			w = SQFLAB_MKR_GW;
			h = SQFLAB_MKR_SCROLL_H;
			class VScrollbar
			{
				width = 0;
				height = 0;
				/* Default engine scrollSpeed ~0.06; 2.5x for wheel / drag */
				scrollSpeed = 0.15;
				autoScrollEnabled = 1;
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				shadow = 0;
				color[] = {1, 1, 1, 0};
				colorActive[] = {1, 1, 1, 0};
				colorDisabled[] = {1, 1, 1, 0};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
			};
			class HScrollbar
			{
				height = 0;
				width = 0;
				color[] = {1, 1, 1, 0};
				colorActive[] = {1, 1, 1, 0};
				colorDisabled[] = {1, 1, 1, 0};
			};
			class controls
			{
				class G_IdentityTitle: RscText
				{
					idc = -1;
					x = 0;
					y = SQFLAB_MKR_GS_IDENTITY;
					w = SQFLAB_MKR_GW;
					h = SQFLAB_MKR_SECTION_H;
					text = "Identity";
					tooltip = "Marker name and display text.";
					colorBackground[] = SQFLAB_MKR_PROFILE_COLOR(0.35);
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
				};
				class G_LabelName: RscText
				{
					idc = -1;
					x = 0;
					y = SQFLAB_MKR_GS_NAME;
					w = SQFLAB_MKR_G_ID_LABEL_W;
					h = SQFLAB_MKR_ROW_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					text = "Name";
					colorBackground[] = {0, 0, 0, 0};
				};
				class G_EditName: RscEdit
				{
					idc = SQFLAB_MKR_IDC_EDIT_NAME;
					x = SQFLAB_MKR_G_ID_LABEL_W + 0.008;
					y = SQFLAB_MKR_GS_NAME;
					w = SQFLAB_MKR_G_EDIT_W;
					h = SQFLAB_MKR_ROW_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					text = "";
					onKillFocus = "[] call SQFLab_fnc_markersApplyPreview";
				};
				class G_LabelText: G_LabelName
				{
					y = SQFLAB_MKR_GS_TEXT;
					text = "Text";
				};
				class G_EditText: G_EditName
				{
					idc = SQFLAB_MKR_IDC_EDIT_TEXT;
					y = SQFLAB_MKR_GS_TEXT;
					onKillFocus = "true";
					onKeyUp = "[] call SQFLab_fnc_markersApplyPreview";
				};

				class G_ScopeTitle: G_IdentityTitle
				{
					y = SQFLAB_MKR_GS_SCOPE_TITLE;
					text = "Scope";
					tooltip = "Global marker APIs vs local (*Local) variants when scripting.";
				};
				class G_LabelGlobal: RscText
				{
					idc = -1;
					x = 0;
					y = SQFLAB_MKR_GS_SCOPE_ROW;
					w = SQFLAB_MKR_LABEL_W;
					h = SQFLAB_MKR_G_CHK_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					style = 0;
					text = "Global";
					tooltip = "When checked, scripting uses createMarker / setMarker* (global). Unchecked: *Local variants.";
					colorBackground[] = {0, 0, 0, 0};
					colorText[] = {1, 1, 1, 0.95};
				};
				class G_ChkGlobal: RscCheckBox
				{
					idc = SQFLAB_MKR_IDC_CHK_GLOBAL;
					x = SQFLAB_MKR_LABEL_W + 0.006;
					y = SQFLAB_MKR_GS_SCOPE_ROW;
					w = SQFLAB_MKR_G_CHK_BOX_W;
					h = SQFLAB_MKR_G_CHK_H;
					text = "";
					tooltip = "Unchecked: createMarkerLocal / setMarker*Local. Checked: createMarker / setMarker*.";
					color[] = {1, 1, 1, 0.9};
					colorFocused[] = {1, 1, 1, 1};
					colorHover[] = {1, 1, 1, 1};
					colorPressed[] = {1, 1, 1, 1};
					colorDisabled[] = {1, 1, 1, 0.45};
					sizeEx = 0.026;
					checked = 0;
					onCheckedChanged = "uiNamespace setVariable ['SQFLab_markers_global', (_this select 1) isEqualTo 1]; [] call SQFLab_fnc_markersApplyPreview;";
				};

				class G_LabelChannel: G_LabelName
				{
					y = SQFLAB_MKR_GS_CHANNEL_ROW;
					w = SQFLAB_MKR_LABEL_W;
					text = "Channel";
					tooltip = "createMarker / createMarkerLocal channel: who can see the marker (see wiki).";
				};
				class G_ComboChannel: RscCombo
				{
					idc = SQFLAB_MKR_IDC_COMBO_CHANNEL;
					x = SQFLAB_MKR_LABEL_W + 0.01;
					y = SQFLAB_MKR_GS_CHANNEL_ROW;
					w = SQFLAB_MKR_GW - SQFLAB_MKR_LABEL_W - 0.01;
					h = SQFLAB_MKR_ROW_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					onLBSelChanged = "[] call SQFLab_fnc_markersApplyPreview";
				};

				class G_TypeTitle: G_IdentityTitle
				{
					y = SQFLAB_MKR_GS_TYPE_TITLE;
					text = "Marker type (CfgMarkers)";
					tooltip = "";
				};
				class G_ListTypes: RscListBox
				{
					idc = SQFLAB_MKR_IDC_LIST_TYPES;
					x = 0;
					y = SQFLAB_MKR_GS_TYPE_LIST;
					w = SQFLAB_MKR_GW;
					h = SQFLAB_MKR_TYPE_LIST_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					rowHeight = 0.042;
					colorBackground[] = {0.05, 0.05, 0.05, 0.92};
					colorSelect[] = {1, 1, 1, 1};
					colorSelectBackground[] = SQFLAB_MKR_PROFILE_COLOR(0.55);
					class ScrollBar
					{
						width = 0.021;
						height = 0;
						scrollSpeed = 0.05;
						arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
						arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
						border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
						thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
						color[] = {1, 1, 1, 0.55};
					};
					onLBSelChanged = "[] call SQFLab_fnc_markersApplyPreview";
				};

				class G_ColorsTitle: G_IdentityTitle
				{
					y = SQFLAB_MKR_GS_COLORS_TITLE;
					text = "Color preview (RGBA)";
					tooltip = "setMarkerColorLocal with direct RGBA string #(r,g,b,a), values 0..1 (see wiki).";
				};
				class G_ColorPreview: RscButtonMenu
				{
					idc = SQFLAB_MKR_IDC_COLOR_PREVIEW;
					x = 0;
					y = SQFLAB_MKR_GS_COLOR_PREVIEW;
					w = SQFLAB_MKR_GW;
					h = SQFLAB_MKR_ROW_H;
					text = "Color preview";
					style = 2;
					action = "";
					colorBackground[] = SQFLAB_MKR_PROFILE_COLOR(0.9);
					colorBackgroundFocused[] = SQFLAB_MKR_PROFILE_COLOR(0.9);
				};

				class G_LabelColorR: G_LabelName
				{
					y = SQFLAB_MKR_GS_COLOR_R;
					w = SQFLAB_MKR_LABEL_W;
					text = "Color R";
				};
				class G_SliderColorR: RscSlider
				{
					idc = SQFLAB_MKR_IDC_SLIDER_COLOR_R;
					x = SQFLAB_MKR_G_SLIDER_X;
					y = SQFLAB_MKR_GS_COLOR_R;
					w = SQFLAB_MKR_G_SLIDER_W;
					h = SQFLAB_MKR_ROW_H;
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
					onSliderPosChanged = "_this call SQFLab_fnc_markersOnSlider";
				};
				class G_ValueColorR: RscEdit
				{
					idc = SQFLAB_MKR_IDC_VALUE_COLOR_R;
					x = SQFLAB_MKR_G_VALUE_X;
					y = SQFLAB_MKR_GS_COLOR_R;
					w = SQFLAB_MKR_VALUE_W;
					h = SQFLAB_MKR_ROW_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					style = 1;
					text = "0";
					colorBackground[] = {0.06, 0.06, 0.06, 0.9};
					tooltip = "Type a value and click away (or Tab) to apply to the slider.";
					onKillFocus = "_this call SQFLab_fnc_markersSliderValueCommit";
				};

				class G_LabelColorG: G_LabelName { y = SQFLAB_MKR_GS_COLOR_G; w = SQFLAB_MKR_LABEL_W; text = "Color G"; };
				class G_SliderColorG: G_SliderColorR { idc = SQFLAB_MKR_IDC_SLIDER_COLOR_G; y = SQFLAB_MKR_GS_COLOR_G; };
				class G_ValueColorG: G_ValueColorR { idc = SQFLAB_MKR_IDC_VALUE_COLOR_G; y = SQFLAB_MKR_GS_COLOR_G; };

				class G_LabelColorB: G_LabelName { y = SQFLAB_MKR_GS_COLOR_B; w = SQFLAB_MKR_LABEL_W; text = "Color B"; };
				class G_SliderColorB: G_SliderColorR { idc = SQFLAB_MKR_IDC_SLIDER_COLOR_B; y = SQFLAB_MKR_GS_COLOR_B; };
				class G_ValueColorB: G_ValueColorR { idc = SQFLAB_MKR_IDC_VALUE_COLOR_B; y = SQFLAB_MKR_GS_COLOR_B; };

				class G_LabelColorA: G_LabelName { y = SQFLAB_MKR_GS_COLOR_A; w = SQFLAB_MKR_LABEL_W; text = "Color A"; };
				class G_SliderColorA: G_SliderColorR { idc = SQFLAB_MKR_IDC_SLIDER_COLOR_A; y = SQFLAB_MKR_GS_COLOR_A; };
				class G_ValueColorA: G_ValueColorR { idc = SQFLAB_MKR_IDC_VALUE_COLOR_A; y = SQFLAB_MKR_GS_COLOR_A; };

				class G_PosTitle: G_IdentityTitle
				{
					y = SQFLAB_MKR_GS_POS_TITLE;
					text = "Position (setMarkerPos)";
					tooltip = "";
				};
				class G_LabelPos: G_LabelName
				{
					y = SQFLAB_MKR_GS_POS_ROW;
					w = SQFLAB_MKR_LABEL_W;
					text = "Position";
					tooltip = "World position as an array, e.g. [x, y] or [x, y, z].";
				};
				class G_EditPos: RscEdit
				{
					idc = SQFLAB_MKR_IDC_EDIT_POS;
					x = SQFLAB_MKR_LABEL_W + 0.01;
					y = SQFLAB_MKR_GS_POS_ROW;
					w = SQFLAB_MKR_GW - SQFLAB_MKR_LABEL_W - 0.01;
					h = SQFLAB_MKR_ROW_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					text = "[0,0,0]";
					onKeyUp = "[] call SQFLab_fnc_markersApplyPreview";
				};

				class G_LabelPosOffset: RscText
				{
					idc = -1;
					x = 0;
					y = SQFLAB_MKR_GS_POS_OFFSET_ROW;
					w = SQFLAB_MKR_LABEL_W;
					h = SQFLAB_MKR_G_CHK_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					style = 0;
					text = "North offset";
					tooltip = "When enabled, the default position is placed north of you so the map marker does not sit on top of your player icon (easier to see the preview).";
					colorBackground[] = {0, 0, 0, 0};
					colorText[] = {1, 1, 1, 0.95};
				};
				class G_ChkPosOffset: RscCheckBox
				{
					idc = SQFLAB_MKR_IDC_CHK_POS_OFFSET;
					x = SQFLAB_MKR_LABEL_W + 0.006;
					y = SQFLAB_MKR_GS_POS_OFFSET_ROW;
					w = SQFLAB_MKR_G_CHK_BOX_W;
					h = SQFLAB_MKR_G_CHK_H;
					text = "";
					tooltip = "When enabled, the default position is placed north of you so the map marker does not sit on top of your player icon (easier to see the preview).";
					color[] = {1, 1, 1, 0.9};
					colorFocused[] = {1, 1, 1, 1};
					colorHover[] = {1, 1, 1, 1};
					colorPressed[] = {1, 1, 1, 1};
					colorDisabled[] = {1, 1, 1, 0.45};
					sizeEx = 0.026;
					checked = 0;
					onCheckedChanged = "_this call SQFLab_fnc_markersPosOffsetToggle";
				};

				class G_ShapeTitle: G_IdentityTitle
				{
					y = SQFLAB_MKR_GS_SHAPE_TITLE;
					text = "Shape, size, direction";
					tooltip = "";
				};
				class G_LabelShape: G_LabelName
				{
					y = SQFLAB_MKR_GS_COMBO_SHAPE;
					w = SQFLAB_MKR_LABEL_W;
					text = "Shape";
				};
				class G_ComboShape: RscCombo
				{
					idc = SQFLAB_MKR_IDC_COMBO_SHAPE;
					x = SQFLAB_MKR_LABEL_W + 0.01;
					y = SQFLAB_MKR_GS_COMBO_SHAPE;
					w = SQFLAB_MKR_GW - SQFLAB_MKR_LABEL_W - 0.01;
					h = SQFLAB_MKR_ROW_H;
					sizeEx = SQFLAB_MKR_LABEL_SIZEEX;
					onLBSelChanged = "[] call SQFLab_fnc_markersApplyPreview";
				};

				class G_LabelSizeA: G_LabelName { y = SQFLAB_MKR_GS_SLIDER_SIZE_A; w = SQFLAB_MKR_LABEL_W; text = "Size A"; };
				class G_SliderSizeA: G_SliderColorR { idc = SQFLAB_MKR_IDC_SLIDER_SIZE_A; y = SQFLAB_MKR_GS_SLIDER_SIZE_A; };
				class G_ValueSizeA: G_ValueColorR { idc = SQFLAB_MKR_IDC_VALUE_SIZE_A; y = SQFLAB_MKR_GS_SLIDER_SIZE_A; };

				class G_LabelSizeB: G_LabelName { y = SQFLAB_MKR_GS_SLIDER_SIZE_B; w = SQFLAB_MKR_LABEL_W; text = "Size B"; };
				class G_SliderSizeB: G_SliderColorR { idc = SQFLAB_MKR_IDC_SLIDER_SIZE_B; y = SQFLAB_MKR_GS_SLIDER_SIZE_B; };
				class G_ValueSizeB: G_ValueColorR { idc = SQFLAB_MKR_IDC_VALUE_SIZE_B; y = SQFLAB_MKR_GS_SLIDER_SIZE_B; };

				class G_LabelDir: G_LabelName { y = SQFLAB_MKR_GS_SLIDER_DIR; w = SQFLAB_MKR_LABEL_W; text = "Direction"; };
				class G_SliderDir: G_SliderColorR { idc = SQFLAB_MKR_IDC_SLIDER_DIR; y = SQFLAB_MKR_GS_SLIDER_DIR; };
				class G_ValueDir: G_ValueColorR { idc = SQFLAB_MKR_IDC_VALUE_DIR; y = SQFLAB_MKR_GS_SLIDER_DIR; };

				class G_BrushTitle: G_IdentityTitle
				{
					y = SQFLAB_MKR_GS_BRUSH_TITLE;
					text = "Brush (setMarkerBrush)";
					tooltip = "";
				};
				class G_LabelBrush: G_LabelName
				{
					y = SQFLAB_MKR_GS_COMBO_BRUSH;
					w = SQFLAB_MKR_LABEL_W;
					text = "Brush";
				};
				class G_ComboBrush: G_ComboShape
				{
					idc = SQFLAB_MKR_IDC_COMBO_BRUSH;
					y = SQFLAB_MKR_GS_COMBO_BRUSH;
				};

				class G_ShadowTitle: G_IdentityTitle
				{
					y = SQFLAB_MKR_GS_SHADOW_TITLE;
					text = "Shadow";
					tooltip = "";
				};

				class G_LabelShadow: G_LabelName
				{
					y = SQFLAB_MKR_GS_COMBO_SHADOW;
					w = SQFLAB_MKR_LABEL_W;
					text = "Shadow";
				};
				class G_ComboShadow: G_ComboShape
				{
					idc = SQFLAB_MKR_IDC_COMBO_SHADOW;
					y = SQFLAB_MKR_GS_COMBO_SHADOW;
				};

				class G_ScrollEndPad: RscText
				{
					idc = -1;
					x = 0;
					y = SQFLAB_MKR_GS_CONTENT_BOTTOM;
					w = 0.02;
					h = 0.02;
					colorBackground[] = {0, 0, 0, 0};
				};
			};
		};

		class CloseBtn: RscButtonMenu
		{
			idc = SQFLAB_MKR_IDC_BTN_CLOSE;
			x = SQFLAB_MKR_PANEL_X + SQFLAB_MKR_PANEL_W - SQFLAB_MKR_PAD_SIDE - SQFLAB_MKR_BTN_W;
			y = SQFLAB_MKR_Y_BOTTOM_BTN;
			w = SQFLAB_MKR_BTN_W;
			h = 0.04;
			text = "Close";
			action = "closeDialog 2";
			colorBackground[] = SQFLAB_MKR_PROFILE_COLOR(0.9);
			colorBackgroundFocused[] = SQFLAB_MKR_PROFILE_COLOR(1);
		};
		class ExportBtn: CloseBtn
		{
			idc = SQFLAB_MKR_IDC_BTN_EXPORT;
			x = SQFLAB_MKR_PANEL_X + SQFLAB_MKR_PANEL_W - SQFLAB_MKR_PAD_SIDE - (SQFLAB_MKR_BTN_W * 2) - SQFLAB_MKR_BTN_GAP;
			text = "Export";
			action = "[] call SQFLab_fnc_markersExport";
			tooltip = "Copy marker setup as SQF to clipboard (RPT fallback if unavailable).";
		};
	};
};

#endif

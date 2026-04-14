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
#define SQFLAB_FORM_X (SQFLAB_PANEL_X + SQFLAB_PAD_SIDE)
#define SQFLAB_FORM_Y (SQFLAB_PANEL_Y + SQFLAB_PAD_TOP + SQFLAB_TITLE_H + SQFLAB_SECTION_GAP)
#define SQFLAB_FORM_W (SQFLAB_PANEL_W - (SQFLAB_PAD_SIDE * 2))
#define SQFLAB_FORM_H (SQFLAB_PANEL_H - (SQFLAB_PAD_TOP * 2) - SQFLAB_TITLE_H - 0.11)
#define SQFLAB_G_LABEL_W 0.22
#define SQFLAB_G_EDIT_X (SQFLAB_G_LABEL_W + 0.01)
#define SQFLAB_G_EDIT_W (SQFLAB_FORM_W - SQFLAB_G_EDIT_X)
#define SQFLAB_G_SLIDER_X (SQFLAB_G_LABEL_W + 0.012)
#define SQFLAB_G_SLIDER_W (SQFLAB_FORM_W - SQFLAB_G_SLIDER_X - SQFLAB_VALUE_W - 0.01)
#define SQFLAB_G_VALUE_X (SQFLAB_G_SLIDER_X + SQFLAB_G_SLIDER_W + 0.008)
#define SQFLAB_G_ROW(y) y
#define SQFLAB_G_SECTION(y) y
#define SQFLAB_SCROLL_CONTENT_H 2.85
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
			y = SQFLAB_FORM_Y;
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
		class GroupScroll: RscControlsGroup
		{
			idc = SQFLAB_IDC_GROUP_SCROLL;
			x = SQFLAB_FORM_X;
			y = SQFLAB_FORM_Y + SQFLAB_ROW_H + SQFLAB_ROW_GAP;
			w = SQFLAB_FORM_W;
			h = SQFLAB_FORM_H - SQFLAB_ROW_H - SQFLAB_ROW_GAP;
			class VScrollbar
			{
				width = 0;
				height = 0;
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
				class G_SectionType: RscText { idc = -1; x = 0; y = SQFLAB_G_SECTION(0.00); w = SQFLAB_FORM_W; h = SQFLAB_SECTION_H; text = $STR_SQFLAB_Particles_TypeTitle; colorBackground[] = SQFLAB_PROFILE_COLOR(0.35); };
				class G_LabelShape: RscText { idc = -1; x = 0; y = SQFLAB_G_ROW(0.04); w = SQFLAB_G_LABEL_W; h = SQFLAB_ROW_H; text = $STR_SQFLAB_Particles_ParticleShape; colorBackground[] = {0,0,0,0}; };
				class G_EditShape: RscEdit { idc = SQFLAB_IDC_EDIT_PARTICLE_SHAPE; x = SQFLAB_G_EDIT_X; y = SQFLAB_G_ROW(0.04); w = SQFLAB_G_EDIT_W; h = SQFLAB_ROW_H; onKillFocus = "[] call SQFLab_fnc_particlesOnSlider"; };
				class G_LabelType: G_LabelShape { y = SQFLAB_G_ROW(0.088); text = $STR_SQFLAB_Particles_ParticleType; };
				class G_EditType: G_EditShape { idc = SQFLAB_IDC_EDIT_PARTICLE_TYPE; y = SQFLAB_G_ROW(0.088); };
				class G_LabelAnim: G_LabelShape { y = SQFLAB_G_ROW(0.136); text = $STR_SQFLAB_Particles_AnimationName; };
				class G_EditAnim: G_EditShape { idc = SQFLAB_IDC_EDIT_ANIM_NAME; y = SQFLAB_G_ROW(0.136); };
				class G_LabelTimer: G_LabelShape { y = SQFLAB_G_ROW(0.184); text = $STR_SQFLAB_Particles_TimerPeriod; };
				class G_EditTimer: G_EditShape { idc = SQFLAB_IDC_EDIT_TIMER_PERIOD; y = SQFLAB_G_ROW(0.184); };
				class G_LabelFsNtieth: G_LabelShape { y = SQFLAB_G_ROW(0.232); text = $STR_SQFLAB_Particles_ParticleFSNtieth; };
				class G_EditFsNtieth: G_EditShape { idc = SQFLAB_IDC_EDIT_FS_NTIETH; y = SQFLAB_G_ROW(0.232); };
				class G_LabelFsIndex: G_LabelShape { y = SQFLAB_G_ROW(0.280); text = $STR_SQFLAB_Particles_ParticleFSIndex; };
				class G_EditFsIndex: G_EditShape { idc = SQFLAB_IDC_EDIT_FS_INDEX; y = SQFLAB_G_ROW(0.280); };
				class G_LabelFsFrameCount: G_LabelShape { y = SQFLAB_G_ROW(0.328); text = $STR_SQFLAB_Particles_ParticleFSFrameCount; };
				class G_EditFsFrameCount: G_EditShape { idc = SQFLAB_IDC_EDIT_FS_FRAMECOUNT; y = SQFLAB_G_ROW(0.328); };
				class G_LabelFsLoop: G_LabelShape { y = SQFLAB_G_ROW(0.376); text = $STR_SQFLAB_Particles_ParticleFSLoop; };
				class G_EditFsLoop: G_EditShape { idc = SQFLAB_IDC_EDIT_FS_LOOP; y = SQFLAB_G_ROW(0.376); };

				class G_SectionParams: G_SectionType { y = SQFLAB_G_SECTION(0.43); text = $STR_SQFLAB_Particles_ParamsTitle; };
				class G_LabelPos: G_LabelShape { y = SQFLAB_G_ROW(0.47); text = $STR_SQFLAB_Particles_Pos3D; };
				class G_EditPos: G_EditShape { idc = SQFLAB_IDC_EDIT_POS3D; y = SQFLAB_G_ROW(0.47); };
				class G_LabelMove: G_LabelShape { y = SQFLAB_G_ROW(0.518); text = $STR_SQFLAB_Particles_MoveVelocityVec; };
				class G_EditMove: G_EditShape { idc = SQFLAB_IDC_EDIT_MOVE_VELOCITY; y = SQFLAB_G_ROW(0.518); };
				class G_LabelSizeOverLife: G_LabelShape { y = SQFLAB_G_ROW(0.566); text = $STR_SQFLAB_Particles_SizeOverLifetime; };
				class G_EditSizeOverLife: G_EditShape { idc = SQFLAB_IDC_EDIT_SIZE_OVER_LIFE; y = SQFLAB_G_ROW(0.566); };
				class G_LabelColorStages: G_LabelShape { y = SQFLAB_G_ROW(0.614); text = $STR_SQFLAB_Particles_ColorStages; };
				class G_EditColorStages: G_EditShape { idc = SQFLAB_IDC_EDIT_COLOR_STAGES; y = SQFLAB_G_ROW(0.614); };
				class G_LabelAnimSpeed: G_LabelShape { y = SQFLAB_G_ROW(0.662); text = $STR_SQFLAB_Particles_AnimationSpeed; };
				class G_EditAnimSpeed: G_EditShape { idc = SQFLAB_IDC_EDIT_ANIM_SPEED; y = SQFLAB_G_ROW(0.662); };
				class G_LabelDirPeriod: G_LabelShape { y = SQFLAB_G_ROW(0.710); text = $STR_SQFLAB_Particles_RandomDirectionPeriod; };
				class G_EditDirPeriod: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD; y = SQFLAB_G_ROW(0.710); };
				class G_LabelDirIntensity: G_LabelShape { y = SQFLAB_G_ROW(0.758); text = $STR_SQFLAB_Particles_RandomDirectionIntensity; };
				class G_EditDirIntensity: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY; y = SQFLAB_G_ROW(0.758); };

				class G_SectionSliders: G_SectionType { y = SQFLAB_G_SECTION(0.81); text = $STR_SQFLAB_Particles_CoreSliders; };
				class G_LabelSize: G_LabelShape { y = SQFLAB_G_ROW(0.85); text = $STR_SQFLAB_Particles_Size; };
				class G_SliderSize: RscSlider
				{
					idc = SQFLAB_IDC_SLIDER_SIZE;
					x = SQFLAB_G_SLIDER_X;
					y = SQFLAB_G_ROW(0.85);
					w = SQFLAB_G_SLIDER_W;
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
				class G_ValueSize: RscText { idc = SQFLAB_IDC_VALUE_SIZE; x = SQFLAB_G_VALUE_X; y = SQFLAB_G_ROW(0.85); w = SQFLAB_VALUE_W; h = SQFLAB_ROW_H; style = 1; text = "0"; colorBackground[] = {0,0,0,0}; };
				class G_LabelLife: G_LabelSize { y = SQFLAB_G_ROW(0.898); text = $STR_SQFLAB_Particles_LifeTime; };
				class G_SliderLife: G_SliderSize { idc = SQFLAB_IDC_SLIDER_LIFETIME; y = SQFLAB_G_ROW(0.898); };
				class G_ValueLife: G_ValueSize { idc = SQFLAB_IDC_VALUE_LIFETIME; y = SQFLAB_G_ROW(0.898); };
				class G_LabelInterval: G_LabelSize { y = SQFLAB_G_ROW(0.946); text = $STR_SQFLAB_Particles_SpawnInterval; };
				class G_SliderInterval: G_SliderSize { idc = SQFLAB_IDC_SLIDER_INTERVAL; y = SQFLAB_G_ROW(0.946); };
				class G_ValueInterval: G_ValueSize { idc = SQFLAB_IDC_VALUE_INTERVAL; y = SQFLAB_G_ROW(0.946); };
				class G_LabelMoveVel: G_LabelSize { y = SQFLAB_G_ROW(0.994); text = $STR_SQFLAB_Particles_MoveVelocity; };
				class G_SliderMoveVel: G_SliderSize { idc = SQFLAB_IDC_SLIDER_MOVEVEL; y = SQFLAB_G_ROW(0.994); };
				class G_ValueMoveVel: G_ValueSize { idc = SQFLAB_IDC_VALUE_MOVEVEL; y = SQFLAB_G_ROW(0.994); };
				class G_LabelRotVel: G_LabelSize { y = SQFLAB_G_ROW(1.042); text = $STR_SQFLAB_Particles_RotationVelocity; };
				class G_SliderRotVel: G_SliderSize { idc = SQFLAB_IDC_SLIDER_ROTVEL; y = SQFLAB_G_ROW(1.042); };
				class G_ValueRotVel: G_ValueSize { idc = SQFLAB_IDC_VALUE_ROTVEL; y = SQFLAB_G_ROW(1.042); };
				class G_LabelWeight: G_LabelSize { y = SQFLAB_G_ROW(1.090); text = $STR_SQFLAB_Particles_Weight; };
				class G_SliderWeight: G_SliderSize { idc = SQFLAB_IDC_SLIDER_WEIGHT; y = SQFLAB_G_ROW(1.090); };
				class G_ValueWeight: G_ValueSize { idc = SQFLAB_IDC_VALUE_WEIGHT; y = SQFLAB_G_ROW(1.090); };
				class G_LabelVolume: G_LabelSize { y = SQFLAB_G_ROW(1.138); text = $STR_SQFLAB_Particles_Volume; };
				class G_SliderVolume: G_SliderSize { idc = SQFLAB_IDC_SLIDER_VOLUME; y = SQFLAB_G_ROW(1.138); };
				class G_ValueVolume: G_ValueSize { idc = SQFLAB_IDC_VALUE_VOLUME; y = SQFLAB_G_ROW(1.138); };
				class G_LabelRubbing: G_LabelSize { y = SQFLAB_G_ROW(1.186); text = $STR_SQFLAB_Particles_Rubbing; };
				class G_SliderRubbing: G_SliderSize { idc = SQFLAB_IDC_SLIDER_RUBBING; y = SQFLAB_G_ROW(1.186); };
				class G_ValueRubbing: G_ValueSize { idc = SQFLAB_IDC_VALUE_RUBBING; y = SQFLAB_G_ROW(1.186); };

				class G_SectionColors: G_SectionType { y = SQFLAB_G_SECTION(1.24); text = $STR_SQFLAB_Particles_ColorsTitle; };
				class G_ColorPreview: RscButtonMenu { idc = SQFLAB_IDC_COLOR_PREVIEW; x = 0; y = SQFLAB_G_ROW(1.28); w = SQFLAB_FORM_W; h = SQFLAB_ROW_H; text = $STR_SQFLAB_Common_ColorPreview; style = 2; action = ""; colorBackground[] = SQFLAB_PROFILE_COLOR(0.9); colorBackgroundFocused[] = SQFLAB_PROFILE_COLOR(0.9); };
				class G_LabelColorR: G_LabelSize { y = SQFLAB_G_ROW(1.328); text = $STR_SQFLAB_Common_ColorR; };
				class G_SliderColorR: G_SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_R; y = SQFLAB_G_ROW(1.328); };
				class G_ValueColorR: G_ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_R; y = SQFLAB_G_ROW(1.328); };
				class G_LabelColorG: G_LabelSize { y = SQFLAB_G_ROW(1.376); text = $STR_SQFLAB_Common_ColorG; };
				class G_SliderColorG: G_SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_G; y = SQFLAB_G_ROW(1.376); };
				class G_ValueColorG: G_ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_G; y = SQFLAB_G_ROW(1.376); };
				class G_LabelColorB: G_LabelSize { y = SQFLAB_G_ROW(1.424); text = $STR_SQFLAB_Common_ColorB; };
				class G_SliderColorB: G_SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_B; y = SQFLAB_G_ROW(1.424); };
				class G_ValueColorB: G_ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_B; y = SQFLAB_G_ROW(1.424); };
				class G_LabelColorA: G_LabelSize { y = SQFLAB_G_ROW(1.472); text = $STR_SQFLAB_Common_ColorA; };
				class G_SliderColorA: G_SliderSize { idc = SQFLAB_IDC_SLIDER_COLOR_A; y = SQFLAB_G_ROW(1.472); };
				class G_ValueColorA: G_ValueSize { idc = SQFLAB_IDC_VALUE_COLOR_A; y = SQFLAB_G_ROW(1.472); };

				class G_SectionCircle: G_SectionType { y = SQFLAB_G_SECTION(1.54); text = $STR_SQFLAB_Particles_CircleTitle; };
				class G_LabelCircleRadius: G_LabelShape { y = SQFLAB_G_ROW(1.58); text = $STR_SQFLAB_Particles_CircleRadius; };
				class G_EditCircleRadius: G_EditShape { idc = SQFLAB_IDC_EDIT_CIRCLE_RADIUS; y = SQFLAB_G_ROW(1.58); };
				class G_LabelCircleVelocity: G_LabelShape { y = SQFLAB_G_ROW(1.628); text = $STR_SQFLAB_Particles_CircleVelocity; };
				class G_EditCircleVelocity: G_EditShape { idc = SQFLAB_IDC_EDIT_CIRCLE_VELOCITY; y = SQFLAB_G_ROW(1.628); };

				class G_SectionRandom: G_SectionType { y = SQFLAB_G_SECTION(1.69); text = $STR_SQFLAB_Particles_RandomTitle; };
				class G_LabelRandomLife: G_LabelShape { y = SQFLAB_G_ROW(1.73); text = $STR_SQFLAB_Particles_RandomLifetimeVar; };
				class G_EditRandomLife: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_LIFETIME_VAR; y = SQFLAB_G_ROW(1.73); };
				class G_LabelRandomPos: G_LabelShape { y = SQFLAB_G_ROW(1.778); text = $STR_SQFLAB_Particles_RandomPositionVar; };
				class G_EditRandomPos: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_POSITION_VAR; y = SQFLAB_G_ROW(1.778); };
				class G_LabelRandomMove: G_LabelShape { y = SQFLAB_G_ROW(1.826); text = $STR_SQFLAB_Particles_RandomMoveVelocityVar; };
				class G_EditRandomMove: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_MOVE_VELOCITY_VAR; y = SQFLAB_G_ROW(1.826); };
				class G_LabelRandomRot: G_LabelShape { y = SQFLAB_G_ROW(1.874); text = $STR_SQFLAB_Particles_RandomRotationVelocityVar; };
				class G_EditRandomRot: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_ROTATION_VELOCITY_VAR; y = SQFLAB_G_ROW(1.874); };
				class G_LabelRandomSize: G_LabelShape { y = SQFLAB_G_ROW(1.922); text = $STR_SQFLAB_Particles_RandomSizeVar; };
				class G_EditRandomSize: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_SIZE_VAR; y = SQFLAB_G_ROW(1.922); };
				class G_LabelRandomColor: G_LabelShape { y = SQFLAB_G_ROW(1.970); text = $STR_SQFLAB_Particles_RandomColorVar; };
				class G_EditRandomColor: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_COLOR_VAR; y = SQFLAB_G_ROW(1.970); };
				class G_LabelRandomDirPeriod: G_LabelShape { y = SQFLAB_G_ROW(2.018); text = $STR_SQFLAB_Particles_RandomDirPeriodVar; };
				class G_EditRandomDirPeriod: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD_VAR; y = SQFLAB_G_ROW(2.018); };
				class G_LabelRandomDirIntensity: G_LabelShape { y = SQFLAB_G_ROW(2.066); text = $STR_SQFLAB_Particles_RandomDirIntensityVar; };
				class G_EditRandomDirIntensity: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY_VAR; y = SQFLAB_G_ROW(2.066); };
				class G_LabelRandomAngle: G_LabelShape { y = SQFLAB_G_ROW(2.114); text = $STR_SQFLAB_Particles_RandomAngleVar; };
				class G_EditRandomAngle: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_ANGLE_VAR; y = SQFLAB_G_ROW(2.114); };
				class G_LabelRandomBounce: G_LabelShape { y = SQFLAB_G_ROW(2.162); text = $STR_SQFLAB_Particles_RandomBounceOnSurfaceVar; };
				class G_EditRandomBounce: G_EditShape { idc = SQFLAB_IDC_EDIT_RANDOM_BOUNCE_VAR; y = SQFLAB_G_ROW(2.162); };
			};
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

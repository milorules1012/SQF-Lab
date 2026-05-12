class CfgPatches
{
	class SQFlab
	{
		author="Milo";
		name="SQF Lab";
		requiredAddons[]=
		{
			"A3_UiFonts_F",
			"A3_3DEN",
			"A3_Ui_F",
			"A3_Functions_F",
			"A3_Data_F_AoW_Loadorder"
		};
		requiredVersion=2.20;
		units[]={};
		version[]={4,0};
		versionStr="4.0-Final";
		weapons[]={};
	};
};

class RscText;
class RscButtonMenu;
class RscControlsGroup;
class RscSlider;
class RscCombo;
class RscEdit;
class RscPicture;
class RscMapControl;
class RscListBox;
class RscCheckBox;

#include "\SQFLab\UI\ui_mainMenu.hpp"
#include "\SQFLab\UI\Particles\ui_particles.hpp"
#include "\SQFLab\UI\Markers\ui_markers.hpp"
#include "\SQFLab\UI\Lights\ui_lights.hpp"
#include "\SQFLab\UI\DrawIcon3D\ui_drawIcon3D.hpp"

class CfgFunctions
{
	tag = "SQFLab";
	class SQFLab
	{
		class Functions
		{
			file = "\SQFLab\Functions";
			class parseArrayOrFallback {};
			class parseNumberOrFallback {};
			class trimSpaces {};
			class vecCross {};
			class vecNorm {};
		};
		class Events
		{
			file = "\SQFLab\Events";
		};
		class UI
		{
			file = "\SQFLab\UI";
			class mainMenu {};
		};
		class Particles
		{
			file = "\SQFLab\UI\Particles";
			class particlesCleanup {};
			class particlesInit {};
			class particlesMenu {};
			class particlesOnSlider {};
			class particlesExport {};
			class particlesToggleUi {};
		};
		class Markers
		{
			file = "\SQFLab\UI\Markers";
			class markersApplyPreview {};
			class markersCleanup {};
			class markersCollectUi {};
			class markersExport {};
			class markersInit {};
			class markersMenu {};
			class markersOnSlider {};
			class markersPosOffsetToggle {};
			class markersSliderValueCommit {};
		};
		class Lights
		{
			file = "\SQFLab\UI\Lights";
			class lightsCleanup {};
			class lightsExport {};
			class lightsInit {};
			class lightsMenu {};
			class lightsOnSlider {};
			class lightsSetTimeDay {};
			class lightsSetTimeNight {};
			class lightsToggleUi {};
		};
		class DrawIcon3D
		{
			file = "\SQFLab\UI\DrawIcon3D";
			class drawIcon3DApplyPreview {};
			class drawIcon3DCleanup {};
			class drawIcon3DCollectUi {};
			class drawIcon3DDrawEH {};
			class drawIcon3DExport {};
			class drawIcon3DInit {};
			class drawIcon3DMenu {};
			class drawIcon3DOnSlider {};
		};
		class Config
		{
			file = "\SQFLab\Config";
		};
		class Misc
		{
			file = "\SQFLab\Misc";
		};
		class Systems
		{
			file = "\SQFLab\Systems";
		};
	};
};

class CfgUserActions
{
	class SQFLab_OpenMainMenu
	{
		displayName = $STR_SQFLAB_Keybind_MainMenu;
		tooltip = $STR_SQFLAB_Keybind_MainMenu_Tooltip;
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_mainMenu }";
		modifierBlocking = 1;
	};
	class SQFLab_OpenLights
	{
		displayName = $STR_SQFLAB_Keybind_Lights;
		tooltip = $STR_SQFLAB_Keybind_Lights_Tooltip;
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_lightsMenu }";
		modifierBlocking = 1;
	};
	class SQFLab_OpenMarkers
	{
		displayName = $STR_SQFLAB_Keybind_Markers;
		tooltip = $STR_SQFLAB_Keybind_Markers_Tooltip;
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_markersMenu }";
		modifierBlocking = 1;
	};
	class SQFLab_OpenParticles
	{
		displayName = $STR_SQFLAB_Keybind_Particles;
		tooltip = $STR_SQFLAB_Keybind_Particles_Tooltip;
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_particlesMenu }";
		modifierBlocking = 1;
	};
	class SQFLab_OpenDrawIcon3D
	{
		displayName = $STR_SQFLAB_Keybind_DrawIcon3D;
		tooltip = $STR_SQFLAB_Keybind_DrawIcon3D_Tooltip;
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_drawIcon3DMenu }";
		modifierBlocking = 1;
	};
};

class UserActionGroups
{
	class SQFLabSection
	{
		name = $STR_SQFLAB_Keybind_Group;
		isAddon = 1;
		group[] = { "SQFLab_OpenMainMenu", "SQFLab_OpenLights", "SQFLab_OpenMarkers", "SQFLab_OpenParticles", "SQFLab_OpenDrawIcon3D" };
	};
};

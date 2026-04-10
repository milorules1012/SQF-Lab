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

class CfgFunctions
{
	tag = "SQFLab";
	class SQFLab
	{
		class Functions
		{
			file = "\SQFLab\Functions";
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
		displayName = "Open Main Menu";
		tooltip = "Open or close the SQF Lab main menu";
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_mainMenu }";
		modifierBlocking = 1;
	};
	class SQFLab_OpenLights
	{
		displayName = "Open Light Sources Editor";
		tooltip = "Open or close the SQF Lab light sources editor";
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_lightsMenu }";
		modifierBlocking = 1;
	};
	class SQFLab_OpenMarkers
	{
		displayName = "Open Markers Editor";
		tooltip = "Open or close the SQF Lab markers editor";
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_markersMenu }";
		modifierBlocking = 1;
	};
	class SQFLab_OpenParticles
	{
		displayName = "Open Particles Editor";
		tooltip = "Open or close the SQF Lab particles editor";
		onActivate = "if (_this) then { [] spawn SQFLab_fnc_particlesMenu }";
		modifierBlocking = 1;
	};
};

class UserActionGroups
{
	class SQFLabSection
	{
		name = "SQF Lab";
		isAddon = 1;
		group[] = { "SQFLab_OpenMainMenu", "SQFLab_OpenLights", "SQFLab_OpenMarkers", "SQFLab_OpenParticles" };
	};
};

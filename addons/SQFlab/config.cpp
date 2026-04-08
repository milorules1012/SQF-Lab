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

class CfgFunctions
{
	tag = "SQFLab";
	class SQFLab
	{
		class Functions
		{
			file = "\SQFLab\Functions";
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
};

class UserActionGroups
{
	class SQFLabSection
	{
		name = "SQF Lab";
		isAddon = 1;
		group[] = { "SQFLab_OpenMainMenu" };
	};
};

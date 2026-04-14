// File: fn_particlesInit.sqf
// Author: Milo
// Description: Initializes the particle effect menu and camera.

#define SQFLAB_PARTICLE_DEFAULT_TYPE "fire"

#include "ui_particles_controls.hpp"
params [
	["_event", displayNull, [displayNull, []]]
];

private _display = displayNull;
if (_event isEqualType displayNull) then {
	_display = _event;
} else {
	_display = _event param [0, displayNull, [displayNull]];
};
if (isNull _display) exitWith { false };

uiNamespace setVariable ["SQFLab_particles_display", _display];
uiNamespace setVariable ["SQFLab_particles_previewType", SQFLAB_PARTICLE_DEFAULT_TYPE];
uiNamespace setVariable ["SQFLab_particles_uiHidden", false];

private _sliderDefaults = createHashMapFromArray [
	[SQFLAB_IDC_SLIDER_SIZE, 0.6],
	[SQFLAB_IDC_SLIDER_LIFETIME, 2],
	[SQFLAB_IDC_SLIDER_INTERVAL, 0.03],
	[SQFLAB_IDC_SLIDER_MOVEVEL, 2],
	[SQFLAB_IDC_SLIDER_ROTVEL, 4],
	[SQFLAB_IDC_SLIDER_WEIGHT, 1.2],
	[SQFLAB_IDC_SLIDER_VOLUME, 1],
	[SQFLAB_IDC_SLIDER_RUBBING, 0.05],
	[SQFLAB_IDC_SLIDER_COLOR_R, 1],
	[SQFLAB_IDC_SLIDER_COLOR_G, 0.6],
	[SQFLAB_IDC_SLIDER_COLOR_B, 0.2],
	[SQFLAB_IDC_SLIDER_COLOR_A, 0.9]
];
private _editDefaults = createHashMapFromArray [
	[SQFLAB_IDC_EDIT_PARTICLE_SHAPE, "\A3\data_f\ParticleEffects\Universal\Universal"],
	[SQFLAB_IDC_EDIT_PARTICLE_TYPE, "Billboard"],
	[SQFLAB_IDC_EDIT_ANIM_NAME, ""],
	[SQFLAB_IDC_EDIT_TIMER_PERIOD, "1"],
	[SQFLAB_IDC_EDIT_FS_NTIETH, "16"],
	[SQFLAB_IDC_EDIT_FS_INDEX, "12"],
	[SQFLAB_IDC_EDIT_FS_FRAMECOUNT, "8"],
	[SQFLAB_IDC_EDIT_FS_LOOP, "0"],
	[SQFLAB_IDC_EDIT_POS3D, "[0,0,0]"],
	[SQFLAB_IDC_EDIT_MOVE_VELOCITY, "[0,0,1]"],
	[SQFLAB_IDC_EDIT_SIZE_OVER_LIFE, "[0.6,0.75,1.05]"],
	[SQFLAB_IDC_EDIT_COLOR_STAGES, "[]"],
	[SQFLAB_IDC_EDIT_ANIM_SPEED, "[0.08]"],
	[SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD, "0.1"],
	[SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY, "0.05"],
	[SQFLAB_IDC_EDIT_CIRCLE_RADIUS, "0"],
	[SQFLAB_IDC_EDIT_CIRCLE_VELOCITY, "[0,0,0]"],
	[SQFLAB_IDC_EDIT_RANDOM_LIFETIME_VAR, "0"],
	[SQFLAB_IDC_EDIT_RANDOM_POSITION_VAR, "[0.03,0.03,0.02]"],
	[SQFLAB_IDC_EDIT_RANDOM_MOVE_VELOCITY_VAR, "[0.3,0.3,0.3]"],
	[SQFLAB_IDC_EDIT_RANDOM_ROTATION_VELOCITY_VAR, "0.4"],
	[SQFLAB_IDC_EDIT_RANDOM_SIZE_VAR, "0.05"],
	[SQFLAB_IDC_EDIT_RANDOM_COLOR_VAR, "[0,0,0,0]"],
	[SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD_VAR, "0.05"],
	[SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY_VAR, "0"],
	[SQFLAB_IDC_EDIT_RANDOM_ANGLE_VAR, "0"],
	[SQFLAB_IDC_EDIT_RANDOM_BOUNCE_VAR, "0"]
];
private _sliderRanges = [
	[SQFLAB_IDC_SLIDER_SIZE, 0.01, 5],
	[SQFLAB_IDC_SLIDER_LIFETIME, 0.01, 15],
	[SQFLAB_IDC_SLIDER_INTERVAL, 0.001, 1],
	[SQFLAB_IDC_SLIDER_MOVEVEL, 0, 25],
	[SQFLAB_IDC_SLIDER_ROTVEL, 0, 50],
	[SQFLAB_IDC_SLIDER_WEIGHT, 0, 10],
	[SQFLAB_IDC_SLIDER_VOLUME, 0, 10],
	[SQFLAB_IDC_SLIDER_RUBBING, 0, 2],
	[SQFLAB_IDC_SLIDER_COLOR_R, 0, 1],
	[SQFLAB_IDC_SLIDER_COLOR_G, 0, 1],
	[SQFLAB_IDC_SLIDER_COLOR_B, 0, 1],
	[SQFLAB_IDC_SLIDER_COLOR_A, 0, 1]
];

{
	_x params ["_idc", "_min", "_max"];
	private _ctrl = _display displayCtrl _idc;
	_ctrl sliderSetRange [_min, _max];
	_ctrl sliderSetSpeed [((_max) - (_min)) / 100, ((_max) - (_min)) / 10];
	_ctrl sliderSetPosition (_sliderDefaults get _idc);
} forEach _sliderRanges;

{
	private _ctrl = _display displayCtrl _x;
	if (!isNull _ctrl) then {
		_ctrl ctrlSetText (_editDefaults get _x);
		_ctrl ctrlAddEventHandler ["KillFocus", { [] call SQFLab_fnc_particlesOnSlider; }];
	};
} forEach (keys _editDefaults);

private _previewAnchor = "Sign_Sphere10cm_F" createVehicleLocal [0, 0, 0];
private _anchorPos = player modelToWorld [0, 3, 1.8];
_previewAnchor setPosATL _anchorPos;
_previewAnchor hideObject true;

private _camTarget = "Sign_Sphere10cm_F" createVehicleLocal [0, 0, 0];
private _targetPos = _anchorPos vectorAdd [0, 0, 0.15];
_camTarget setPosATL _targetPos;
_camTarget hideObject true;

private _camPos = _targetPos vectorAdd [0, -2.8, 1.0];
private _cam = "camera" camCreate _camPos;
_cam cameraEffect ["INTERNAL", "BACK", "SQFLAB_PARTICLE_RT"];
_cam camSetTarget _camTarget;
_cam camSetFov 0.75;
_cam camCommit 0;

private _particleSource = "#particlesource" createVehicleLocal _anchorPos;
_particleSource setPosATL _anchorPos;

uiNamespace setVariable ["SQFLab_particles_pipCamera", _cam];
uiNamespace setVariable ["SQFLab_particles_previewAnchor", _previewAnchor];
uiNamespace setVariable ["SQFLab_particles_pipTarget", _camTarget];
uiNamespace setVariable ["SQFLab_particles_previewSource", _particleSource];

private _previewCtrl = _display displayCtrl SQFLAB_IDC_PREVIEW_PICTURE;
_previewCtrl ctrlSetText "#(argb,512,512,1)r2t(SQFLAB_PARTICLE_RT,1.0)";

[] call SQFLab_fnc_particlesOnSlider;

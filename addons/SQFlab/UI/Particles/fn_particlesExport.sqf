// File: fn_particlesExport.sqf
// Author: Milo
// Description: Exports particle data to clipboard or diag_log if not available.

#include "ui_particles_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_particles_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_ParticlesExport could not find the particles menu";
	systemChat (localize "STR_SQFLAB_Err_ParticlesMenuNotFound");
};

private _size = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_SIZE);
private _lifeTime = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_LIFETIME);
private _interval = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_INTERVAL);
private _moveVel = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_MOVEVEL);
private _rotVel = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_ROTVEL);
private _weight = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_WEIGHT);
private _volume = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_VOLUME);
private _rubbing = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_RUBBING);
private _r = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_R);
private _g = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_G);
private _b = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_B);
private _a = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_A);
private _preset = uiNamespace getVariable ["SQFLab_particles_previewType", "fire"];

private _shape = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_PARTICLE_SHAPE);
if (_shape isEqualTo "") then { _shape = "\A3\data_f\ParticleEffects\Universal\Universal"; };
private _type = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_PARTICLE_TYPE);
if (_type isEqualTo "") then { _type = "Billboard"; };
private _animName = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_ANIM_NAME);
private _timerPeriod = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_TIMER_PERIOD), 1] call SQFLab_fnc_parseNumberOrFallback;
private _fsNtieth = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_NTIETH), 16] call SQFLab_fnc_parseNumberOrFallback;
private _fsIndex = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_INDEX), 12] call SQFLab_fnc_parseNumberOrFallback;
private _fsFrameCount = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_FRAMECOUNT), 8] call SQFLab_fnc_parseNumberOrFallback;
private _fsLoop = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_LOOP), 0] call SQFLab_fnc_parseNumberOrFallback;

private _defaultMove = [0, 0, _moveVel];
switch (toLower _preset) do {
	case "smoke": { _defaultMove = [0, 0, _moveVel * 0.45]; };
	case "drop": { _defaultMove = [0, 0, -(_moveVel max 0.01)]; };
};
private _pos3D = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_POS3D), [0, 0, 0]] call SQFLab_fnc_parseArrayOrFallback;
private _moveVelocity = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_MOVE_VELOCITY), _defaultMove] call SQFLab_fnc_parseArrayOrFallback;
private _sizeMid = _size * 1.25;
private _sizeEnd = _size * 1.75;
private _sizeOverLife = [_size, _sizeMid, _sizeEnd];
private _sizeOverLifeText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_SIZE_OVER_LIFE);
private _sizeOverLifeTrimmed = [_sizeOverLifeText] call SQFLab_fnc_trimSpaces;
if (_sizeOverLifeTrimmed != "" && {_sizeOverLifeTrimmed != "[]"} && {_sizeOverLifeTrimmed != "[0.6,0.75,1.05]"}) then {
	_sizeOverLife = [_sizeOverLifeText, _sizeOverLife] call SQFLab_fnc_parseArrayOrFallback;
};

private _baseRGB = [1, 0.5, 0.1];
switch (toLower _preset) do {
	case "smoke": { _baseRGB = [0.45, 0.45, 0.45]; };
	case "drop": { _baseRGB = [0.55, 0.7, 1]; };
};
private _colorR = (_baseRGB select 0) * _r;
private _colorG = (_baseRGB select 1) * _g;
private _colorB = (_baseRGB select 2) * _b;
private _defaultColors = [
	[_colorR, _colorG, _colorB, _a],
	[_colorR, _colorG, _colorB, _a * 0.6],
	[_colorR, _colorG, _colorB, 0]
];
private _colorStagesText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_COLOR_STAGES);
private _colorStages = _defaultColors;
if (([_colorStagesText] call SQFLab_fnc_trimSpaces) != "[]" && {_colorStagesText != ""}) then {
	_colorStages = [_colorStagesText, _defaultColors] call SQFLab_fnc_parseArrayOrFallback;
};
private _animationSpeed = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_ANIM_SPEED), [0.08]] call SQFLab_fnc_parseArrayOrFallback;
private _randomDirectionPeriod = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD), 0.1] call SQFLab_fnc_parseNumberOrFallback;
private _randomDirectionIntensity = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY), 0.05] call SQFLab_fnc_parseNumberOrFallback;

private _circleRadius = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_CIRCLE_RADIUS), 0] call SQFLab_fnc_parseNumberOrFallback;
private _circleVelocity = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_CIRCLE_VELOCITY), [0, 0, 0]] call SQFLab_fnc_parseArrayOrFallback;

private _randomLifeVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_LIFETIME_VAR), 0] call SQFLab_fnc_parseNumberOrFallback;
private _randomPosVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_POSITION_VAR), [_size * 0.05, _size * 0.05, _size * 0.03]] call SQFLab_fnc_parseArrayOrFallback;
private _randomMoveVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_MOVE_VELOCITY_VAR), [_moveVel * 0.15, _moveVel * 0.15, _moveVel * 0.15]] call SQFLab_fnc_parseArrayOrFallback;
private _randomRotVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_ROTATION_VELOCITY_VAR), _rotVel * 0.1] call SQFLab_fnc_parseNumberOrFallback;
private _randomSizeVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_SIZE_VAR), 0.05] call SQFLab_fnc_parseNumberOrFallback;
private _randomColorVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_COLOR_VAR), [0, 0, 0, 0]] call SQFLab_fnc_parseArrayOrFallback;
private _randomDirPeriodVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD_VAR), 0.05] call SQFLab_fnc_parseNumberOrFallback;
private _randomDirIntensityVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY_VAR), 0] call SQFLab_fnc_parseNumberOrFallback;
private _randomAngleVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_ANGLE_VAR), 0] call SQFLab_fnc_parseNumberOrFallback;
private _randomBounceVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_BOUNCE_VAR), 0] call SQFLab_fnc_parseNumberOrFallback;
private _onTimerScript = "";
private _beforeDestroyScript = "";

private _lines = [
	"// SQF Lab - particle effect export",
	format ["// Preset: %1", _preset],
	"// Attach particles to _attachTo (object). Position [0,0,0] in setParticleParams is relative to it.",
	"private _attachTo = player;",
	"private _ps = ""#particlesource"" createVehicle [0, 0, 0];",
	"_ps setPosATL getPosATL _attachTo;",
	format ["_ps setParticleCircle [%1, %2];", _circleRadius, str _circleVelocity],
	format [
		"_ps setParticleRandom [%1, %2, %3, %4, %5, %6, %7, %8, %9, %10];",
		_randomLifeVar,
		str _randomPosVar,
		str _randomMoveVar,
		_randomRotVar,
		_randomSizeVar,
		str _randomColorVar,
		_randomDirPeriodVar,
		_randomDirIntensityVar,
		_randomAngleVar,
		_randomBounceVar
	],
	format [
		"_ps setParticleParams [[%1, %2, %3, %4, %5], %6, %7, %8, %9, %10, %11, %12, %13, %14, %15, %16, %17, %18, %19, %20, %21, %22, _attachTo];",
		str _shape,
		_fsNtieth, _fsIndex, _fsFrameCount, _fsLoop,
		str _animName,
		str _type,
		_timerPeriod,
		_lifeTime,
		str _pos3D,
		str _moveVelocity,
		_rotVel,
		_weight,
		_volume,
		_rubbing,
		str _sizeOverLife,
		str _colorStages,
		str _animationSpeed,
		_randomDirectionPeriod,
		_randomDirectionIntensity,
		str _onTimerScript,
		str _beforeDestroyScript
	],
	format ["_ps setDropInterval %1;", _interval],
	"// deleteVehicle _ps; // when done"
];

private _nl = toString [10];
private _text = _lines joinString _nl;

if (isServer) then {
	copyToClipboard _text;
	hint (localize "STR_SQFLAB_Hint_ParticleExportClipboard");
} else {
	{ diag_log _x } forEach _lines;
	hint (localize "STR_SQFLAB_Hint_ParticleExportRpt");
};

true

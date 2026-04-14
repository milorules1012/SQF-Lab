// File: fn_particlesOnSlider.sqf
// Author: Milo
// Description: Updates slider texts, colors and most importantly active particles.

#include "ui_particles_controls.hpp"
private _display = uiNamespace getVariable ["SQFLab_particles_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_ParticlesOnSlider could not find the particles menu";
	systemChat (localize "STR_SQFLAB_Err_ParticlesMenuNotFound");
};

private _pairs = [
	[SQFLAB_IDC_SLIDER_SIZE, SQFLAB_IDC_VALUE_SIZE],
	[SQFLAB_IDC_SLIDER_LIFETIME, SQFLAB_IDC_VALUE_LIFETIME],
	[SQFLAB_IDC_SLIDER_INTERVAL, SQFLAB_IDC_VALUE_INTERVAL],
	[SQFLAB_IDC_SLIDER_MOVEVEL, SQFLAB_IDC_VALUE_MOVEVEL],
	[SQFLAB_IDC_SLIDER_ROTVEL, SQFLAB_IDC_VALUE_ROTVEL],
	[SQFLAB_IDC_SLIDER_WEIGHT, SQFLAB_IDC_VALUE_WEIGHT],
	[SQFLAB_IDC_SLIDER_VOLUME, SQFLAB_IDC_VALUE_VOLUME],
	[SQFLAB_IDC_SLIDER_RUBBING, SQFLAB_IDC_VALUE_RUBBING],
	[SQFLAB_IDC_SLIDER_COLOR_R, SQFLAB_IDC_VALUE_COLOR_R],
	[SQFLAB_IDC_SLIDER_COLOR_G, SQFLAB_IDC_VALUE_COLOR_G],
	[SQFLAB_IDC_SLIDER_COLOR_B, SQFLAB_IDC_VALUE_COLOR_B],
	[SQFLAB_IDC_SLIDER_COLOR_A, SQFLAB_IDC_VALUE_COLOR_A]
];
{
	_x params ["_sliderIdc", "_valueIdc"];
	private _value = sliderPosition (_display displayCtrl _sliderIdc);
	(_display displayCtrl _valueIdc) ctrlSetText (str ([_value, 3] call BIS_fnc_cutDecimals));
} forEach _pairs;

private _preview = _display displayCtrl SQFLAB_IDC_COLOR_PREVIEW;
private _r = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_R);
private _g = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_G);
private _b = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_B);
private _a = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_COLOR_A);
_preview ctrlSetBackgroundColor [_r, _g, _b, _a];

private _source = uiNamespace getVariable ["SQFLab_particles_previewSource", objNull];
private _anchor = uiNamespace getVariable ["SQFLab_particles_previewAnchor", objNull];
if (!isNull _anchor && !isNull _source) then {
	_source setPosATL (getPosATL _anchor);

	private _toNum = {
		params ["_text", "_fallback"];
		private _v = parseNumber _text;
		if (_v isEqualTo 0 && {_text != "0" && {_text != "0.0"}}) exitWith { _fallback };
		_v
	};
	private _toArray = {
		params ["_text", "_fallback"];
		private _parsed = call compile format ["%1", _text];
		[_fallback, _parsed] select (_parsed isEqualType [])
	};
	private _trimmed = {
		params ["_text"];
		(_text splitString " ") joinString ""
	};

	private _size = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_SIZE);
	private _lifeTime = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_LIFETIME);
	private _interval = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_INTERVAL);
	private _moveVel = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_MOVEVEL);
	private _rotVel = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_ROTVEL);
	private _weight = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_WEIGHT);
	private _volume = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_VOLUME);
	private _rubbing = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_RUBBING);
	private _preset = toLower (uiNamespace getVariable ["SQFLab_particles_previewType", "fire"]);

	private _shape = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_PARTICLE_SHAPE);
	if (_shape isEqualTo "") then { _shape = "\A3\data_f\ParticleEffects\Universal\Universal"; };
	private _type = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_PARTICLE_TYPE);
	if (_type isEqualTo "") then { _type = "Billboard"; };
	private _animName = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_ANIM_NAME);
	private _timerPeriod = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_TIMER_PERIOD), 1] call _toNum;
	private _fsNtieth = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_NTIETH), 16] call _toNum;
	private _fsIndex = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_INDEX), 12] call _toNum;
	private _fsFrameCount = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_FRAMECOUNT), 8] call _toNum;
	private _fsLoop = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_FS_LOOP), 0] call _toNum;

	private _defaultMove = [0, 0, _moveVel];
	switch (_preset) do {
		case "smoke": { _defaultMove = [0, 0, _moveVel * 0.45]; };
		case "drop": { _defaultMove = [0, 0, -(_moveVel max 0.01)]; };
	};
	private _pos3D = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_POS3D), [0, 0, 0]] call _toArray;
	private _moveVelocity = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_MOVE_VELOCITY), _defaultMove] call _toArray;

	private _sizeMid = _size * 1.25;
	private _sizeEnd = _size * 1.75;
	private _sizeOverLife = [_size, _sizeMid, _sizeEnd];
	private _sizeOverLifeText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_SIZE_OVER_LIFE);
	private _sizeOverLifeTrimmed = [_sizeOverLifeText] call _trimmed;
	if (_sizeOverLifeTrimmed != "" && {_sizeOverLifeTrimmed != "[]"} && {_sizeOverLifeTrimmed != "[0.6,0.75,1.05]"}) then {
		_sizeOverLife = [_sizeOverLifeText, _sizeOverLife] call _toArray;
	};

	private _baseRGB = [1, 0.5, 0.1];
	switch (_preset) do {
		case "smoke": { _baseRGB = [0.45, 0.45, 0.45]; };
		case "drop": { _baseRGB = [0.55, 0.7, 1]; };
	};
	private _colorR = (_baseRGB # 0) * _r;
	private _colorG = (_baseRGB # 1) * _g;
	private _colorB = (_baseRGB # 2) * _b;
	private _defaultColors = [
		[_colorR, _colorG, _colorB, _a],
		[_colorR, _colorG, _colorB, _a * 0.6],
		[_colorR, _colorG, _colorB, 0]
	];
	private _colorStagesText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_COLOR_STAGES);
	private _colorStages = _defaultColors;
	if (([_colorStagesText] call _trimmed) != "[]" && {_colorStagesText != ""}) then {
		_colorStages = [_colorStagesText, _defaultColors] call _toArray;
	};
	private _animationSpeed = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_ANIM_SPEED), [0.08]] call _toArray;
	private _randomDirectionPeriod = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD), 0.1] call _toNum;
	private _randomDirectionIntensity = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY), 0.05] call _toNum;
	private _onTimerScript = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_ON_TIMER_SCRIPT);
	private _beforeDestroyScript = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_BEFORE_DESTROY_SCRIPT);

	private _circleRadius = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_CIRCLE_RADIUS), 0] call _toNum;
	private _circleVelocity = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_CIRCLE_VELOCITY), [0, 0, 0]] call _toArray;
	_source setParticleCircle [_circleRadius, _circleVelocity];

	private _randomLifeVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_LIFETIME_VAR), 0] call _toNum;
	private _randomPosVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_POSITION_VAR), [_size * 0.05, _size * 0.05, _size * 0.03]] call _toArray;
	private _randomMoveVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_MOVE_VELOCITY_VAR), [_moveVel * 0.15, _moveVel * 0.15, _moveVel * 0.15]] call _toArray;
	private _randomRotVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_ROTATION_VELOCITY_VAR), _rotVel * 0.1] call _toNum;
	private _randomSizeVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_SIZE_VAR), 0.05] call _toNum;
	private _randomColorVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_COLOR_VAR), [0, 0, 0, 0]] call _toArray;
	private _randomDirPeriodVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_PERIOD_VAR), 0.05] call _toNum;
	private _randomDirIntensityVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_DIR_INTENSITY_VAR), 0] call _toNum;
	private _randomAngleVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_ANGLE_VAR), 0] call _toNum;
	private _randomBounceVar = [ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_RANDOM_BOUNCE_VAR), 0] call _toNum;

	_source setParticleRandom [
		_randomLifeVar,
		_randomPosVar,
		_randomMoveVar,
		_randomRotVar,
		_randomSizeVar,
		_randomColorVar,
		_randomDirPeriodVar,
		_randomDirIntensityVar,
		_randomAngleVar,
		_randomBounceVar
	];

	private _params = [
		[_shape, _fsNtieth, _fsIndex, _fsFrameCount, _fsLoop],
		_animName,
		_type,
		_timerPeriod,
		_lifeTime,
		_pos3D,
		_moveVelocity,
		_rotVel,
		_weight,
		_volume,
		_rubbing,
		_sizeOverLife,
		_colorStages,
		_animationSpeed,
		_randomDirectionPeriod,
		_randomDirectionIntensity,
		_onTimerScript,
		_beforeDestroyScript,
		_anchor
	];

	private _angleText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_ANGLE);
	if (_angleText != "") then {
		_params pushBack ([_angleText, 0] call _toNum);
		_params pushBack (cbChecked (_display displayCtrl SQFLAB_IDC_CHK_ON_SURFACE));
		private _bounceText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_BOUNCE_ON_SURFACE);
		if (_bounceText != "") then {
			_params pushBack ([_bounceText, 0] call _toNum);
			private _emissiveText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_EMISSIVE_COLOR);
			if (_emissiveText != "") then {
				_params pushBack ([_emissiveText, []] call _toArray);
				private _vectorText = ctrlText (_display displayCtrl SQFLAB_IDC_EDIT_VECTOR_DIR);
				if (_vectorText != "") then {
					_params pushBack ([_vectorText, [0, 0, 1]] call _toArray);
				};
			};
		};
	};

	_source setParticleParams _params;
	_source setDropInterval _interval;
};

true

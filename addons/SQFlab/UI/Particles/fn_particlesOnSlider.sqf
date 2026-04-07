// File: fn_particlesOnSlider.sqf
// Author: Milo
// Description: Updates slider texts, colors and most importantly active particles.

#include "ui_particles_controls.hpp"
private _display = uiNamespace getVariable ["SQFLab_particles_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_ParticlesOnSlider could not find the particles menu";
	systemChat "SQF Lab particles menu could not be found";
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

	private _size = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_SIZE);
	private _lifeTime = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_LIFETIME);
	private _interval = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_INTERVAL);
	private _moveVel = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_MOVEVEL);
	private _rotVel = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_ROTVEL);
	private _weight = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_WEIGHT);
	private _volume = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_VOLUME);
	private _rubbing = sliderPosition (_display displayCtrl SQFLAB_IDC_SLIDER_RUBBING);
	private _preset = uiNamespace getVariable ["SQFLab_particles_previewType", "fire"];

	private _baseRGB = [1, 0.5, 0.1];
	private _verticalVel = _moveVel;
	private _shape = "\A3\data_f\ParticleEffects\Universal\Universal";
	switch (toLower _preset) do {
		case "smoke": {
			_baseRGB = [0.45, 0.45, 0.45];
			_verticalVel = _moveVel * 0.45;
		};
		case "drop": {
			_baseRGB = [0.55, 0.7, 1];
			_verticalVel = -(_moveVel max 0.01);
		};
		default {
			_baseRGB = [1, 0.5, 0.1];
			_verticalVel = _moveVel;
		};
	};

	private _colorR = (_baseRGB # 0) * _r;
	private _colorG = (_baseRGB # 1) * _g;
	private _colorB = (_baseRGB # 2) * _b;
	private _sizeMid = _size * 1.25;
	private _sizeEnd = _size * 1.75;

	_source setParticleCircle [0, [0, 0, 0]];
	_source setParticleRandom [
		0,
		[_size * 0.05, _size * 0.05, _size * 0.03],
		[_moveVel * 0.15, _moveVel * 0.15, _moveVel * 0.15],
		_rotVel * 0.1,
		0.05,
		[0, 0, 0, 0],
		0.05,
		0
	];
	_source setParticleParams [
		[_shape, 16, 12, 8, 0],
		"",
		"Billboard",
		1,
		_lifeTime,
		[0, 0, 0],
		[0, 0, _verticalVel],
		_rotVel,
		_weight,
		_volume,
		_rubbing,
		[_size, _sizeMid, _sizeEnd],
		[
			[_colorR, _colorG, _colorB, _a],
			[_colorR, _colorG, _colorB, _a * 0.6],
			[_colorR, _colorG, _colorB, 0]
		],
		[0.08],
		0.1,
		0.05,
		"",
		"",
		_anchor
	];
	_source setDropInterval _interval;
};

true

// File: fn_particlesExport.sqf
// Author: Milo
// Description: Exports particle data to clipboard or diag_log if not available.

#include "ui_particles_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_particles_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_ParticlesExport could not find the particles menu";
	systemChat "SQF Lab particles menu could not be found";
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

private _colorR = (_baseRGB select 0) * _r;
private _colorG = (_baseRGB select 1) * _g;
private _colorB = (_baseRGB select 2) * _b;
private _sizeMid = _size * 1.25;
private _sizeEnd = _size * 1.75;

private _rx = _size * 0.05;
private _ry = _size * 0.05;
private _rz = _size * 0.03;
private _vx = _moveVel * 0.15;
private _vy = _moveVel * 0.15;
private _vz = _moveVel * 0.15;
private _randRot = _rotVel * 0.1;
private _aMid = _a * 0.6;

private _lines = [
	"// SQF Lab - particle effect export",
	format ["// Preset: %1", _preset],
	"// Attach particles to _attachTo (object). Position [0,0,0] in setParticleParams is relative to it.",
	"private _attachTo = player;",
	"private _ps = ""#particlesource"" createVehicle [0, 0, 0];",
	"_ps setPosATL getPosATL _attachTo;",
	"_ps setParticleCircle [0, [0, 0, 0]];",
	format [
		"_ps setParticleRandom [0, [%1, %2, %3], [%4, %5, %6], %7, 0.05, [0, 0, 0, 0], 0.05, 0];",
		_rx, _ry, _rz,
		_vx, _vy, _vz,
		_randRot
	],
	format [
		"_ps setParticleParams [[%1, 16, 12, 8, 0], """", ""Billboard"", 1, %2, [0, 0, 0], [0, 0, %3], %4, %5, %6, %7, [%8, %9, %10], [[%11, %12, %13, %14], [%15, %16, %17, %18], [%19, %20, %21, 0]], [0.08], 0.1, 0.05, """", """", _attachTo];",
		str _shape,
		_lifeTime, _verticalVel, _rotVel,
		_weight, _volume, _rubbing,
		_size, _sizeMid, _sizeEnd,
		_colorR, _colorG, _colorB, _a,
		_colorR, _colorG, _colorB, _aMid,
		_colorR, _colorG, _colorB
	],
	format ["_ps setDropInterval %1;", _interval],
	"// deleteVehicle _ps; // when done"
];

private _nl = toString [10];
private _text = _lines joinString _nl;

if (isServer) then {
	copyToClipboard _text;
	hint "Particle SQF exported to clipboard.";
} else {
	{ diag_log _x } forEach _lines;
	hint "Particle SQF written to RPT as clipboard is not supported in this environment.";
};

true

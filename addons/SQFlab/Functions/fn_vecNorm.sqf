// File: fn_vecNorm.sqf
// Author: Milo
// Description: Normalizes a 3D vector; returns [0,0,1] if length is ~0. Call as [v] call SQFLab_fnc_vecNorm.

params ["_v"];
private _m = _v distance [0, 0, 0];
if (_m < 1e-10) exitWith { [0, 0, 1] };
[
	(_v select 0) / _m,
	(_v select 1) / _m,
	(_v select 2) / _m
]

// File: fn_vecCross.sqf
// Author: Milo
// Description: 3D cross product for two vectors [x,y,z]. Call as [u, v] call SQFLab_fnc_vecCross.

params ["_u", "_v"];
[
	(_u # 1) * (_v # 2) - (_u # 2) * (_v # 1),
	(_u # 2) * (_v # 0) - (_u # 0) * (_v # 2),
	(_u # 0) * (_v # 1) - (_u # 1) * (_v # 0)
]

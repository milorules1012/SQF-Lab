// File: fn_vecCross.sqf
// Author: Milo
// Description: 3D cross product for two vectors [x,y,z]. Call as [u, v] call SQFLab_fnc_vecCross.

params ["_u", "_v"];
[
	(_u select 1) * (_v select 2) - (_u select 2) * (_v select 1),
	(_u select 2) * (_v select 0) - (_u select 0) * (_v select 2),
	(_u select 0) * (_v select 1) - (_u select 1) * (_v select 0)
]

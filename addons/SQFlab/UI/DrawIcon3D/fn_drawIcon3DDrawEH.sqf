// File: fn_drawIcon3DDrawEH.sqf
// Author: Milo
// Description: Draw3D callback that renders current DrawIcon3D editor state.

private _display = uiNamespace getVariable ["SQFLab_drawIcon3D_display", displayNull];
if (isNull _display) exitWith {};

private _icon = uiNamespace getVariable ["SQFLab_drawIcon3D_icon", createHashMap];
if (count _icon isEqualTo 0) exitWith {};

drawIcon3D _icon;

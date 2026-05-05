// File: fn_drawIcon3DCleanup.sqf
// Author: Milo
// Description: Removes Draw3D preview event handler and clears uiNamespace state.

private _ehId = uiNamespace getVariable ["SQFLab_drawIcon3D_ehId", -1];
if (_ehId >= 0) then {
	removeMissionEventHandler ["Draw3D", _ehId];
};

uiNamespace setVariable ["SQFLab_drawIcon3D_ehId", nil];
uiNamespace setVariable ["SQFLab_drawIcon3D_icon", nil];
uiNamespace setVariable ["SQFLab_drawIcon3D_group", controlNull];
uiNamespace setVariable ["SQFLab_drawIcon3D_display", displayNull];

// File: fn_markersPosOffsetToggle.sqf
// Author: Milo
// Description: Position "north offset" checkbox — snap edit to offset or player ATL, then refresh preview.

#include "ui_markers_controls.hpp"

params ["_ignored", "_checked"];

private _scrollGroup = uiNamespace getVariable ["SQFLab_markers_scrollGroup", controlNull];
private _edit = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_EDIT_POS;
if (isNull _scrollGroup || isNull _edit) exitWith {};

if (_checked isEqualTo 1) then {
	_edit ctrlSetText str (player getPos [SQFLAB_MKR_PREVIEW_OFFSET_METERS, 0]);
} else {
	_edit ctrlSetText str (getPosATL player);
};

[] call SQFLab_fnc_markersApplyPreview;


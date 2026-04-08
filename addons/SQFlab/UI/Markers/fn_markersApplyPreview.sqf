// File: fn_markersApplyPreview.sqf
// Author: Milo
// Description: Updates the local preview marker from dialog state.

#include "ui_markers_controls.hpp"

private _state = call SQFLab_fnc_markersCollectUi;
if (isNil "_state") exitWith { false };

private _wantName = _state get "markerName";
if (_wantName isEqualTo "") exitWith {};

private _pos = _state get "position";
if (_state get "positionParsedOk") then {
	uiNamespace setVariable ["SQFLab_markers_lastGoodPos", _pos];
};

private _currentName = uiNamespace getVariable ["SQFLab_markers_previewName", ""];
if (_wantName != _currentName && {_wantName in allMapMarkers}) exitWith {
	systemChat "SQF Lab: a marker with that name already exists. Choose another name.";
};

if ((_currentName != "") && _currentName != _wantName && {_currentName in allMapMarkers}) then {
	deleteMarkerLocal _currentName;
};

private _ch = _state get "channel";
private _prevCh = uiNamespace getVariable ["SQFLab_markers_previewChannel", nil];
if (!isNil "_prevCh" && _prevCh != _ch && {_wantName in allMapMarkers}) then {
	deleteMarkerLocal _wantName;
};

if (!(_wantName in allMapMarkers)) then {
	createMarkerLocal ([[_wantName, _pos, _ch], [_wantName, _pos]] select (_ch < 0));
};

uiNamespace setVariable ["SQFLab_markers_previewName", _wantName];
uiNamespace setVariable ["SQFLab_markers_previewChannel", _ch];

private _mkr = _wantName;
_mkr setMarkerPosLocal _pos;
_mkr setMarkerTypeLocal (_state get "mkrType");

private _shape = _state get "shape";
_mkr setMarkerShapeLocal _shape;

_mkr setMarkerSizeLocal [_state get "sizeA", _state get "sizeB"];
_mkr setMarkerDirLocal (_state get "dir");
_mkr setMarkerBrushLocal (_state get "brush");
_mkr setMarkerShadowLocal ((_state get "shadow") > 0);
_mkr setMarkerTextLocal (_state get "markerText");
_mkr setMarkerColorLocal (_state get "colorRgbaStr");

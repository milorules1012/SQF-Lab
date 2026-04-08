// File: fn_markersExport.sqf
// Author: Milo
// Description: Builds SQF for marker setup (*Local + optional one global tail). Clipboard like particles.

#include "ui_markers_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_markers_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] markersExport could not find the markers menu";
	systemChat "SQF Lab markers menu could not be found";
};

private _state = call SQFLab_fnc_markersCollectUi;
if (isNil "_state") exitWith {};

private _wantName = _state get "markerName";
if (_wantName isEqualTo "") exitWith {
	systemChat "SQF Lab: marker name is empty; nothing exported.";
};
if ((_wantName find ";") >= 0 || (_wantName find "|") >= 0 || (_wantName find toString [10]) >= 0) exitWith {
	systemChat "SQF Lab: marker name contains invalid characters; nothing exported.";
};

private _pos = _state get "position";
private _mkrType = _state get "mkrType";
private _shape = _state get "shape";
private _brush = _state get "brush";
private _shadow = (_state get "shadow") > 0;
private _sizeA = _state get "sizeA";
private _sizeB = _state get "sizeB";
private _dir = _state get "dir";
private _channel = _state get "channel";
private _text = _state get "markerText";
private _colorRgbaStr = _state get "colorRgbaStr";
private _global = _state get "global";

private _lines = [
	"// SQF Lab - marker export",
	"// MP: use *Local for setup, then one global setter at the end to sync (see createMarker wiki).",
	format ["private _mkr = %1;", str _wantName],
	format ["private _pos = %1;", str _pos]
];
if (_channel < 0) then {
	_lines pushBack "createMarkerLocal [_mkr, _pos]; // channel: engine default";
} else {
	_lines pushBack format ["createMarkerLocal [_mkr, _pos, %1];", _channel];
};
_lines append [
	format ["_mkr setMarkerTypeLocal %1;", str _mkrType],
	format ["_mkr setMarkerShapeLocal %1;", str _shape]
];

_lines append [
	format ["_mkr setMarkerSizeLocal [%1, %2];", _sizeA, _sizeB],
	format ["_mkr setMarkerDirLocal %1;", _dir],
	format ["_mkr setMarkerBrushLocal %1;", str _brush],
	format ["_mkr setMarkerShadowLocal %1;", _shadow],
	format ["_mkr setMarkerTextLocal %1;", str _text],
	format ["_mkr setMarkerColorLocal %1;", str _colorRgbaStr]
];

if (_global) then {
	_lines pushBack "// One non-Local call to broadcast full marker state to other clients:";
	_lines pushBack "_mkr setMarkerPos _pos;";
};

private _nl = toString [10];
private _textOut = _lines joinString _nl;

if (isServer) then {
	copyToClipboard _textOut;
	hint "Marker SQF exported to clipboard.";
} else {
	{ diag_log _x } forEach _lines;
	hint "Marker SQF written to RPT as clipboard is not supported in this environment.";
};

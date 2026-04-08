// File: fn_markersCleanup.sqf
// Author: Milo
// Description: Markers menu unload cleanup.

private _preview = uiNamespace getVariable ["SQFLab_markers_previewName", ""];
if ((_preview != "") && {_preview in allMapMarkers}) then {
	deleteMarkerLocal _preview;
};

uiNamespace setVariable ["SQFLab_markers_previewName", nil];
uiNamespace setVariable ["SQFLab_markers_previewChannel", nil];
uiNamespace setVariable ["SQFLab_markers_lastGoodPos", nil];
uiNamespace setVariable ["SQFLab_markers_display", displayNull];
uiNamespace setVariable ["SQFLab_markers_scrollGroup", controlNull];
uiNamespace setVariable ["SQFLab_markers_global", nil];


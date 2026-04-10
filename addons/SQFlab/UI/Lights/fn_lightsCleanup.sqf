// File: fn_lightsCleanup.sqf
// Author: Milo
// Description: Terminates PiP camera and deletes preview / light objects.

private _cam = uiNamespace getVariable ["SQFLab_lights_pipCamera", objNull];
if (!isNull _cam) then {
	_cam cameraEffect ["TERMINATE", "BACK"];
	camDestroy _cam;
};

deleteVehicle (uiNamespace getVariable ["SQFLab_lights_pipTarget", objNull]);
deleteVehicle (uiNamespace getVariable ["SQFLab_lights_previewAnchor", objNull]);
deleteVehicle (uiNamespace getVariable ["SQFLab_lights_light", objNull]);

uiNamespace setVariable ["SQFLab_lights_pipCamera", objNull];
uiNamespace setVariable ["SQFLab_lights_pipTarget", objNull];
uiNamespace setVariable ["SQFLab_lights_previewAnchor", objNull];
uiNamespace setVariable ["SQFLab_lights_light", objNull];
uiNamespace setVariable ["SQFLab_lights_lastGoodPos", nil];
uiNamespace setVariable ["SQFLab_lights_type", nil];
uiNamespace setVariable ["SQFLab_lights_uiHidden", nil];
uiNamespace setVariable ["SQFLab_lights_display", displayNull];

private _datePrev = uiNamespace getVariable ["SQFLab_lights_datePrev", []];
uiNamespace setVariable ["SQFLab_lights_datePrev", nil];
if ((count _datePrev) isEqualTo 5) then {
	setDate _datePrev;
};

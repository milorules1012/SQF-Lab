// File: fn_particlesCleanup.sqf
// Author: Milo
// Description: Cleans up various particle/camera related stuff.

private _cam = uiNamespace getVariable ["SQFLab_particles_pipCamera", objNull];
if (!isNull _cam) then {
	_cam cameraEffect ["TERMINATE", "BACK"];
	camDestroy _cam;
};

private _target = uiNamespace getVariable ["SQFLab_particles_pipTarget", objNull];
if (!isNull _target) then {
	deleteVehicle _target;
};

private _anchor = uiNamespace getVariable ["SQFLab_particles_previewAnchor", objNull];
if (!isNull _anchor) then {
	deleteVehicle _anchor;
};

private _source = uiNamespace getVariable ["SQFLab_particles_previewSource", objNull];
if (!isNull _source) then {
	deleteVehicle _source;
};

uiNamespace setVariable ["SQFLab_particles_pipCamera", objNull];
uiNamespace setVariable ["SQFLab_particles_pipTarget", objNull];
uiNamespace setVariable ["SQFLab_particles_previewAnchor", objNull];
uiNamespace setVariable ["SQFLab_particles_previewSource", objNull];
uiNamespace setVariable ["SQFLab_particles_previewType", nil];
uiNamespace setVariable ["SQFLab_particles_uiHidden", nil];
uiNamespace setVariable ["SQFLab_particles_display", displayNull];

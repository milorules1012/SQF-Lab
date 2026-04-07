// File: fn_particlesCleanup.sqf
// Author: Milo
// Description: Cleans up various particle/camera related stuff.

private _cam = uiNamespace getVariable ["SQFLab_particles_pipCamera", objNull];
_cam cameraEffect ["TERMINATE", "BACK"];
camDestroy _cam;

deleteVehicle (uiNamespace getVariable ["SQFLab_particles_pipTarget", objNull]);
deleteVehicle (uiNamespace getVariable ["SQFLab_particles_previewAnchor", objNull]);
deleteVehicle (uiNamespace getVariable ["SQFLab_particles_previewSource", objNull]);

uiNamespace setVariable ["SQFLab_particles_pipCamera", objNull];
uiNamespace setVariable ["SQFLab_particles_pipTarget", objNull];
uiNamespace setVariable ["SQFLab_particles_previewAnchor", objNull];
uiNamespace setVariable ["SQFLab_particles_previewSource", objNull];
uiNamespace setVariable ["SQFLab_particles_previewType", nil];
uiNamespace setVariable ["SQFLab_particles_uiHidden", nil];
uiNamespace setVariable ["SQFLab_particles_display", displayNull];

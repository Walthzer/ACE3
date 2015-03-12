#include "script_component.hpp"

ADDON = false;

PREP(actionCheckBloodPressure);
PREP(actionCheckBloodPressureLocal);
PREP(actionCheckPulse);
PREP(actionCheckPulseLocal);
PREP(actionCheckResponse);
PREP(actionPlaceInBodyBag);
PREP(actionRemoveTourniquet);
PREP(actionLoadUnit);
PREP(actionUnloadUnit);
PREP(actionCarryUnit);
PREP(actionDropUnit);
PREP(addHeartRateAdjustment);
PREP(addToInjuredCollection);
PREP(addToLog);
PREP(addToTriageCard);
PREP(addUnconsciousCondition);
PREP(canAccessMedicalEquipment);
PREP(canTreat);
PREP(determineIfFatal);
PREP(getBloodLoss);
PREP(getBloodPressure);
PREP(getBloodVolumeChange);
PREP(getCardiacOutput);
PREP(getTypeOfDamage);
PREP(getTriageStatus);
PREP(getUnconsciousCondition);
PREP(handleDamage);
PREP(handleDamage_advanced);
PREP(handleDamage_advancedSetDamage);
PREP(handleDamage_airway);
PREP(handleDamage_basic);
PREP(handleDamage_caching);
PREP(handleDamage_fractures);
PREP(handleDamage_internalInjuries);
PREP(handleDamage_wounds);
PREP(handleUnitVitals);
PREP(handleKilled);
PREP(handleLocal);
PREP(hasItem);
PREP(hasItems);
PREP(hasMedicalEnabled);
PREP(hasTourniquetAppliedTo);
PREP(init);
PREP(isInMedicalFacility);
PREP(isMedic);
PREP(isMedicalVehicle);
PREP(onMedicationUsage);
PREP(onWoundUpdateRequest);
PREP(onPropagateWound);
PREP(onCarryObjectDropped);
PREP(parseConfigForInjuries);
PREP(playInjuredSound);
PREP(reactionToDamage);
PREP(selectionNameToNumber);
PREP(setCardiacArrest);
PREP(setDead);
PREP(setHitPointDamage);
PREP(setUnconscious);
PREP(treatment);
PREP(treatment_failure);
PREP(treatment_success);
PREP(treatmentAdvanced_bandage);
PREP(treatmentAdvanced_bandageLocal);
PREP(treatmentAdvanced_CPR);
PREP(treatmentAdvanced_CPRLocal);
PREP(treatmentAdvanced_fullHeal);
PREP(treatmentAdvanced_fullHealLocal);
PREP(treatmentAdvanced_medication);
PREP(treatmentAdvanced_medicationLocal);
PREP(treatmentBasic_bandage);
PREP(treatmentBasic_bloodbag);
PREP(treatmentBasic_epipen);
PREP(treatmentBasic_morphine);
PREP(treatmentIV);
PREP(treatmentIVLocal);
PREP(treatmentTourniquet);
PREP(treatmentTourniquetLocal);
PREP(useItem);
PREP(useItems);
PREP(displayPatientInformation);
PREP(moduleMedicalSettings);
PREP(moduleAssignMedicRoles);
PREP(moduleAssignMedicalVehicle);
PREP(moduleAssignMedicalFacility);
PREP(moduleTreatmentConfiguration);

GVAR(injuredUnitCollection) = [];
call FUNC(parseConfigForInjuries);

ADDON = true;

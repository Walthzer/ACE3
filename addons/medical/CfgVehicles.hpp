
#define MEDICAL_ACTION_DISTANCE 1.75

class CBA_Extended_EventHandlers;

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class ArgumentsBaseUnits {
        };
    };
    class ACE_Module;
    // TODO Add settings modules

    #define ARM_LEG_ARMOR_DEFAULT 1
    #define ARM_LEG_ARMOR_BETTER  1
    #define ARM_LEG_ARMOR_CSAT    1

    #define ADD_ACE_HITPOINTS(ARM_ARMOR,LEG_ARMOR) \
        class HitLeftArm { \
            armor = ARM_ARMOR; \
            material = -1; \
            name = "hand_l"; \
            passThrough = 1; \
            radius = 0.08; \
            explosionShielding = 1; \
            visual = "injury_hands"; \
            minimalHit = 0.01; \
        }; \
        class HitRightArm: HitLeftArm { \
            name = "hand_r"; \
        }; \
        class HitLeftLeg { \
            armor = LEG_ARMOR; \
            material = -1; \
            name = "leg_l"; \
            passThrough = 1; \
            radius = 0.1; \
            explosionShielding = 1; \
            visual = "injury_legs"; \
            minimalHit = 0.01; \
        }; \
        class HitRightLeg: HitLeftLeg { \
            name = "leg_r"; \
        };

    class Man;
    class CAManBase: Man {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_DEFAULT,ARM_LEG_ARMOR_DEFAULT)
        };
    };

    class SoldierWB: CAManBase {};
    class SoldierEB: CAManBase {};
    class SoldierGB: CAManBase {};

    class B_Soldier_base_F: SoldierWB {};

    class B_Soldier_04_f: B_Soldier_base_F {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_BETTER,ARM_LEG_ARMOR_BETTER)
        };
    };

    class B_Soldier_05_f: B_Soldier_base_F {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_BETTER,ARM_LEG_ARMOR_BETTER)
        };
    };

    class I_Soldier_base_F: SoldierGB {};

    class I_Soldier_03_F: I_Soldier_base_F {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_BETTER,ARM_LEG_ARMOR_BETTER)
        };
    };

    class I_Soldier_04_F: I_Soldier_base_F {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_BETTER,ARM_LEG_ARMOR_BETTER)
        };
    };

    class O_Soldier_base_F: SoldierEB {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_CSAT,ARM_LEG_ARMOR_BETTER)
        };
    };

    class O_Soldier_diver_base_F: O_Soldier_base_F {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_CSAT,ARM_LEG_ARMOR_BETTER)
        };
    };

    class O_Soldier_02_F: O_Soldier_base_F {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_CSAT,ARM_LEG_ARMOR_BETTER)
        };
    };

    class O_officer_F: O_Soldier_base_F {
        class HitPoints {
            ADD_ACE_HITPOINTS(ARM_LEG_ARMOR_CSAT,ARM_LEG_ARMOR_BETTER)
        };
    };

    //These VR guys already have limb hitpoints that we should be able to use
    //Note: the selections are a little weird, eg:  class leg_l {name = "leg_l";};
    // class B_Soldier_VR_F: B_Soldier_base_F { {
        // class HitPoints {
           //Has class hand_l, hand_r, leg_l, leg_r Hitpoints already
        // };
    // };
    // class O_Soldier_VR_F: O_Soldier_base_F { {
        // class HitPoints {
           //Has class hand_l, hand_r, leg_l, leg_r Hitpoints already
        // };
    // };
    // class I_Soldier_VR_F: I_Soldier_base_F { {
        // class HitPoints {
           //Has class hand_l, hand_r, leg_l, leg_r Hitpoints already
        // };
    // };
    // class C_Soldier_VR_F: C_man_1 {
        // class HitPoints {
           //Has class hand_l, hand_r, leg_l, leg_r Hitpoints already
        // };
    // };
    // class O_Protagonist_VR_F: O_Soldier_base_F {
        // class HitPoints {
           //Has class hand_l, hand_r, leg_l, leg_r Hitpoints already
        // };
    // };

    class MapBoard_altis_F;
    class ACE_bodyBagObject: MapBoard_altis_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };

        scope = 1;
        scopeCurator = 2;
        side = -1;
        model = QPATHTOEF(apl,bodybag.p3d);
        icon = "";
        displayName = CSTRING(Bodybag_Display);
        EGVAR(dragging,canDrag) = 1;
        EGVAR(dragging,dragPosition)[] = {0,1.2,0};
        EGVAR(dragging,dragDirection) = 0;
        EGVAR(cargo,size) = 1;
        EGVAR(cargo,canLoad) = 1;
        class ACE_Actions {
            class ACE_MainActions {
                displayName = ECSTRING(interaction,MainAction);
                distance = 5;
                condition = QUOTE(true);
                statement = "";
                icon = "\a3\ui_f\data\IGUI\Cfg\Actions\eject_ca.paa";
                selection = "";
            };
        };
    };

    // Medical litter classes
    class Thing;
    class ACE_MedicalLitterBase: Thing {
        scope = 1;
        scopeCurator = 0;
        displayName = " ";
        destrType = "DestructNo";
        model = QPATHTOF(data\littergeneric.p3d);
    };
    class ACE_MedicalLitter_clean: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_clean.p3d);
    };
    class ACE_MedicalLitter_bandage1: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_bandages1.p3d);
    };
    class ACE_MedicalLitter_bandage2: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_bandages2.p3d);
    };
    class ACE_MedicalLitter_bandage3: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_bandages3.p3d);
    };
    class ACE_MedicalLitter_packingBandage: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_packingBandage.p3d);
    };
    class ACE_MedicalLitter_gloves: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_gloves.p3d);
    };
    class ACE_MedicalLitter_adenosine: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_adenosine.p3d);
    };
    class ACE_MedicalLitter_atropine: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_atropine.p3d);
    };
    class ACE_MedicalLitter_epinephrine: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_epinephrine.p3d);
    };
    class ACE_MedicalLitter_morphine: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_morphine.p3d);
    };
    class ACE_MedicalLitter_QuickClot: ACE_MedicalLitterBase {
        model = QPATHTOF(data\littergeneric_Quikclot.p3d);
    };
    class Item_Base_F;
    class ACE_fieldDressingItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Bandage_Basic_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_fieldDressing,1);
        };
    };
    class ACE_packingBandageItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Packing_Bandage_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_packingBandage,1);
        };
    };
    class ACE_elasticBandageItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Bandage_Elastic_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_elasticBandage,1);
        };
    };
    class ACE_tourniquetItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Tourniquet_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_tourniquet,1);
        };
    };
    class ACE_morphineItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Morphine_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_morphine,1);
        };
    };
    class ACE_adenosineItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Adenosine_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_adenosine,1);
        };
    };
    class ACE_atropineItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Atropine_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_atropine,1);
        };
    };
    class ACE_epinephrineItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Epinephrine_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_epinephrine,1);
        };
    };
    class ACE_plasmaIVItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Plasma_IV);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_plasmaIV,1);
        };
    };

    class ACE_bloodIVItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Blood_IV);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_bloodIV,1);
        };
    };
    class ACE_salineIVItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Saline_IV);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_salineIV,1);
        };
    };
    class ACE_quikClotItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(QuikClot_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_quikclot,1);
        };
    };
    class ACE_personalAidKitItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Aid_Kit_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_personalAidKit,1);
        };
    };
    class ACE_surgicalKitItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(SurgicalKit_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_surgicalKit,1);
        };
    };
    class ACE_bodyBagItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(Bodybag_Display);
        author = ECSTRING(common,ACETeam);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_bodyBag,1);
        };
    };

    class NATO_Box_Base;
    class ACE_medicalSupplyCrate: NATO_Box_Base {
        scope = 2;
        scopeCurator = 2;
        accuracy = 1000;
        displayName = CSTRING(medicalSupplyCrate);
        model = QPATHTOF(data\ace_medcrate.p3d);
        author = ECSTRING(common,ACETeam);
        class TransportItems {
            MACRO_ADDITEM(ACE_fieldDressing,50);
            MACRO_ADDITEM(ACE_morphine,25);
            MACRO_ADDITEM(ACE_epinephrine,25);
            MACRO_ADDITEM(ACE_bloodIV,15);
            MACRO_ADDITEM(ACE_bloodIV_500,15);
            MACRO_ADDITEM(ACE_bloodIV_250,15);
            MACRO_ADDITEM(ACE_bodyBag,10);
        };
    };
    class ACE_medicalSupplyCrate_advanced: ACE_medicalSupplyCrate {
        displayName = CSTRING(medicalSupplyCrate_advanced);
        class TransportItems {
            MACRO_ADDITEM(ACE_fieldDressing,25);
            MACRO_ADDITEM(ACE_packingBandage,25);
            MACRO_ADDITEM(ACE_elasticBandage,25);
            MACRO_ADDITEM(ACE_tourniquet,15);
            MACRO_ADDITEM(ACE_morphine,15);
            MACRO_ADDITEM(ACE_adenosine,15);
            MACRO_ADDITEM(ACE_atropine,15);
            MACRO_ADDITEM(ACE_epinephrine,15);
            MACRO_ADDITEM(ACE_plasmaIV,7);
            MACRO_ADDITEM(ACE_plasmaIV_500,7);
            MACRO_ADDITEM(ACE_plasmaIV_250,7);
            MACRO_ADDITEM(ACE_salineIV,7);
            MACRO_ADDITEM(ACE_salineIV_500,7);
            MACRO_ADDITEM(ACE_salineIV_250,7);
            MACRO_ADDITEM(ACE_bloodIV,7);
            MACRO_ADDITEM(ACE_bloodIV_500,7);
            MACRO_ADDITEM(ACE_bloodIV_250,7);
            MACRO_ADDITEM(ACE_quikClot,20);
            MACRO_ADDITEM(ACE_personalAidKit,3);
            MACRO_ADDITEM(ACE_surgicalKit,2);
            MACRO_ADDITEM(ACE_bodyBag,5);
        };
    };
};

classdef ChamberSensed < Simulink.IntEnumType
    %ChamberPaced Enumerated type definition for second Pacemaker code letter
    %   Possible choices refer to the atrium,ventricle, both or neither
    
    enumeration
        ATRIUM(0)
        VENTRICLE(1)
        DUAL(2)
        NONE(3)
    end
end

